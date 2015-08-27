// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef GetCurrentTime
#pragma comment(lib, "runtimeobject")

#include <modern\implements.h>
#include <modern\comptr.h>
#include <modern\handle.h>
#include <inspectable.h>
#include <eventtoken.h>
#include <winstring.h>
#include <set>
#include <memory>
#include <vector>

extern "C"
{
	enum RO_INIT_TYPE;

	BOOL __stdcall RoOriginateErrorW(HRESULT error, unsigned length, wchar_t const * message);
	HRESULT __stdcall RoInitialize(RO_INIT_TYPE type);
	HRESULT __stdcall RoGetActivationFactory(HSTRING classId, GUID const & iid, void ** factory);
	HRESULT __stdcall RoActivateInstance(HSTRING classId, ::IInspectable ** instance);
}

namespace Modern {

enum class AsyncStatus
{
	Started = 0,
	Completed,
	Canceled,
	Error,
};

enum class InitializeType
{
	SingleThreaded,
	MultiThreaded
};

struct Exception
{
	HRESULT Result;

	explicit Exception(HRESULT const value) : Result(value)
	{}

	template <unsigned Count>
	Exception(HRESULT const value, wchar_t const (&message)[Count]) : Result(value)
	{
		RoOriginateErrorW(value, Count - 1, message);
	}
};

inline void check(HRESULT const result)
{
	if (result == S_OK)
	{
		return;
	}

	throw Exception(result);
}

inline void Initialize(InitializeType const type = InitializeType::MultiThreaded)
{
	check(RoInitialize(static_cast<RO_INIT_TYPE>(type)));
}

struct BoolProxy
{
	BoolProxy & operator=(BoolProxy const &) = delete;

	BoolProxy(bool & value) noexcept :
		m_value(value)
	{}

	~BoolProxy() noexcept
	{
		m_value = 0 != m_abi;
	}

	operator boolean * () noexcept
	{
		return &m_abi;
	}

private:

	boolean m_abi = 0;
	bool & m_value;
};

template <typename T>
class FastIterator
{
	T const * m_collection = nullptr;
	unsigned m_index = 0;

public:

	FastIterator(T const & collection, unsigned const index) noexcept :
		m_collection(&collection),
		m_index(index)
	{}

	FastIterator & operator++() noexcept
	{
		++m_index;
		return *this;
	}

	auto operator *() const
	{
		return m_collection->GetAt(m_index);
	}

	bool operator==(FastIterator const & other) const noexcept
	{
		MODERN_ASSERT(m_collection == other.m_collection);
		return m_index == other.m_index;
	}

	bool operator!=(FastIterator const & other) const noexcept
	{
		return !(*this == other);
	}
};

struct StringTraits : HandleTraits<HSTRING>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY_(S_OK, WindowsDeleteString(value));
	}
};

struct StringBufferTraits : HandleTraits<HSTRING_BUFFER>
{
	static void Close(Type value) noexcept
	{
		MODERN_VERIFY_(S_OK, WindowsDeleteStringBuffer(value));
	}
};


struct StringReference
{
	StringReference(StringReference const &) = delete;
	StringReference & operator=(StringReference const &) = delete;

	StringReference(wchar_t const * const value, unsigned length)
	{
		check(WindowsCreateStringReference(value, length, &m_header, &m_string));
	}

	template <unsigned Count>
	StringReference(wchar_t const (&value)[Count]) :
		StringReference(value, Count - 1)
	{}

	operator HSTRING() const noexcept
	{
		return m_string;
	}

private:

	HSTRING_HEADER m_header;
	HSTRING m_string;
};

struct String
{
	String() noexcept = default;
	String(String && other) noexcept = default;
	String & operator=(String && other) noexcept = default;

	String(std::nullptr_t) noexcept {}

	String(wchar_t const * value, unsigned const length) :
		m_handle(CreateString(value, length))
	{}

	template <unsigned Count>
	String(wchar_t const (&value)[Count]) :
		String(value, Count - 1)
	{}

	String(wchar_t const * value) :
		String(value, static_cast<unsigned>(wcslen(value)))
	{}

	String(String const & other) :
		m_handle(DuplicateString(get(other)))
	{}

	String & operator=(String const & other) noexcept
	{
		attach(m_handle, DuplicateString(get(other)));
		return *this;
	}

	String & operator=(std::nullptr_t) noexcept
	{
		m_handle.Close();
		return *this;
	}

	wchar_t const * Buffer() const noexcept
	{
		return WindowsGetStringRawBuffer(get(m_handle), nullptr);
	}

	wchar_t const * Buffer(unsigned & length) const noexcept
	{
		return WindowsGetStringRawBuffer(get(m_handle), &length);
	}

	unsigned Length() const noexcept
	{
		return WindowsGetStringLen(get(m_handle));
	}

	bool Empty() const noexcept
	{
		return 0 != WindowsIsStringEmpty(get(m_handle));
	}

	bool HasEmbeddedNull() const
	{
		BOOL result = 0;
		check(WindowsStringHasEmbeddedNull(get(m_handle), &result));
		return 0 != result;
	}

	String Substring(unsigned const startIndex)
	{
		String result;
		check(WindowsSubstring(get(m_handle), startIndex, set(result)));
		return result;
	}

	String Substring(unsigned const startIndex, unsigned const length)
	{
		String result;
		check(WindowsSubstringWithSpecifiedLength(get(m_handle), startIndex, length, set(result)));
		return result;
	}

	int Compare(wchar_t const * other) const noexcept
	{
		return wcscmp(Buffer(), other);
	}

	int Compare(String const & other) const noexcept
	{
		return Compare(other.Buffer());
	}

	friend HSTRING get(String const & string) noexcept
	{
		return get(string.m_handle);
	}

	friend HSTRING * set(String & string) noexcept
	{
		return set(string.m_handle);
	}

	friend void attach(String & string, HSTRING handle) noexcept
	{
		attach(string.m_handle, handle);
	}

	friend HSTRING detach(String & string) noexcept
	{
		return detach(string.m_handle);
	}

	friend void swap(String & left, String & right) noexcept
	{
		swap(left.m_handle, right.m_handle);
	}

private:

	static HSTRING DuplicateString(HSTRING other)
	{
		HSTRING result = nullptr;
		check(WindowsDuplicateString(other, &result));
		return result;
	}

	static HSTRING CreateString(wchar_t const * value, unsigned const length)
	{
		HSTRING result = nullptr;
		check(WindowsCreateString(value, length, &result));
		return result;
	}

	Handle<StringTraits> m_handle;
};

inline bool operator==(String const & left, String const & right)
{
	int result = 0;
	check(WindowsCompareStringOrdinal(get(left), get(right), &result));
	return result == 0;
}
inline bool operator!=(String const & left, String const & right)
{
	return !(left == right);
}
inline bool operator<(String const & left, String const & right)
{
	int result = 0;
	check(WindowsCompareStringOrdinal(get(left), get(right), &result));
	return result == -1;
}
inline bool operator>(String const & left, String const & right)
{
	return right < left;
}
inline bool operator<=(String const & left, String const & right)
{
	return !(right < left);
}
inline bool operator>=(String const & left, String const & right)
{
	return !(left < right);
}

template <typename To>
struct Lease : To
{
	template <typename From>
	Lease(From value) noexcept : To(nullptr)
	{
		*set(*static_cast<To *>(this)) = value;
	}

	~Lease() noexcept
	{
		detach(*static_cast<To *>(this));
	}
};

template <typename T>
struct Traits
{
	using Abi = T;
};

template <typename T>
class HasDefault
{
	template <typename U> static constexpr bool Check(typename Traits<U>::Default *) { return true; }
	template <typename>   static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(nullptr);
};

template <typename T>
class HasComposable
{
	template <typename U> static constexpr bool Check(typename U::Composable *) { return true; }
	template <typename>   static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(nullptr);
};

template <typename T>
class HasGetAt
{
	template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool Check(int) { return true;  }
	template <typename> static constexpr bool Check(...) { return false; }

public:

	static constexpr bool Value = Check<T>(0);
};

template <typename T>
using IsRandomAccess = typename std::enable_if<HasGetAt<T>::Value>::type *;

template <typename T>
using IsNotRandomAccess = typename std::enable_if<!HasGetAt<T>::Value>::type *;

template <typename T>
using IsComposable = typename std::enable_if<HasComposable<T>::Value>::type *;

template <typename T>
using IsNotComposable = typename std::enable_if<!HasComposable<T>::Value>::type *;

template <typename T>
using IsPod = typename std::enable_if<std::is_pod<T>::value>::type *;

template <typename T>
using IsNotPod = typename std::enable_if<!std::is_pod<T>::value>::type *;


template <typename T>
using Abi = typename Traits<T>::Abi;

template <typename T>
using AbiPtr = NoAddRefRelease<Abi<T>> *;

template <typename T, typename Enable = void>
struct LookupDefaultAbi
{
	using Type = Abi<T>;
};

template <typename T>
struct LookupDefaultAbi<T, typename std::enable_if<HasDefault<T>::Value>::type>
{
	using Type = Abi<typename Traits<T>::Default>;
};

template <typename T>
using DefaultAbi = typename LookupDefaultAbi<T>::Type;


template <typename T, typename Enable = void>
struct LookupDefault
{
	using Type = T;
};

template <typename T>
struct LookupDefault<T, typename std::enable_if<HasDefault<T>::Value>::type>
{
	using Type = typename Traits<T>::Default;
};

template <typename T>
using Default = typename LookupDefault<T>::Type;

template <typename T, IsPod<T> = nullptr>
T const & abi(T const & value) noexcept
{
	return value;
}

template <typename T, IsPod<T> = nullptr>
T * abi(T * value) noexcept
{
	return value;
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T const & value) noexcept
{
	return get(value);
}

template <typename T, IsNotPod<T> = nullptr>
auto abi(T * value) noexcept
{
	return set(*value);
}

inline BoolProxy abi(bool * value) noexcept
{
	return BoolProxy(*value);
}

template <typename To, typename From, IsPod<To> = nullptr>
To forward(From value) noexcept
{
	return value;
}

template <typename To, typename From, IsNotPod<To> = nullptr>
Lease<To> forward(From value) noexcept
{
	return Lease<To>(value);
}

template <typename T>
struct ImplementsDefault : Implements<Abi<T>, ::IAgileObject>
{
	using Default = T;
};

template <> struct Traits<String>
{
	using Abi = HSTRING;
};

}

namespace Modern { namespace ABI {

using String = HSTRING;

}}

namespace Modern { namespace ABI { namespace Windows {

struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
{
	virtual HRESULT __stdcall get_Id(unsigned int * id) = 0;
	virtual HRESULT __stdcall get_Status(AsyncStatus * status) = 0;
	virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
	virtual HRESULT __stdcall abi_Cancel() = 0;
	virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
{
	virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
};

}}}

namespace Modern { namespace Windows {

struct IUnknown
{
	IUnknown() noexcept = default;
	IUnknown(std::nullptr_t) noexcept {}

	IUnknown(IUnknown const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		InternalAddRef();
	}

	IUnknown(IUnknown && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~IUnknown() noexcept
	{
		InternalRelease();
	}

	IUnknown & operator=(IUnknown const & other) noexcept
	{
		InternalCopy(other);
		return *this;
	}

	IUnknown & operator=(IUnknown && other) noexcept
	{
		InternalMove(std::forward<IUnknown>(other));
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	auto operator->() const noexcept
	{
		return static_cast<NoAddRefRelease<::IUnknown> *>(m_ptr);
	}

	IUnknown & operator=(std::nullptr_t) noexcept
	{
		InternalRelease();
		return *this;
	}

	template <typename T>
	T As() const
	{
		T temp = nullptr;
		check(m_ptr->QueryInterface(set(temp)));
		return temp;
	}

	template <typename T>
	friend DefaultAbi<T> * get(T const & object) noexcept
	{
		return static_cast<DefaultAbi<T> *>(object.m_ptr);
	}

	template <typename T>
	friend DefaultAbi<T> ** set(T & object) noexcept
	{
		MODERN_ASSERT(!object);
		return reinterpret_cast<DefaultAbi<T> **>(&object.m_ptr);
	}

	template <typename T>
	friend void attach(T & object, DefaultAbi<T> * value) noexcept
	{
		object.InternalRelease();
		object.m_ptr = value;
	}

	template <typename T>
	friend DefaultAbi<T> * detach(T & object) noexcept
	{
		DefaultAbi<T> * temp = static_cast<DefaultAbi<T> *>(object.m_ptr);
		object.m_ptr = nullptr;
		return temp;
	}

	template <typename T>
	friend DefaultAbi<T> * detach(T && object) noexcept
	{
		return detach(object);
	}

	friend void swap(IUnknown & left, IUnknown & right) noexcept
	{
		::IUnknown * temp = left.m_ptr;
		left.m_ptr = right.m_ptr;
		right.m_ptr = temp;
	}

protected:

	void InternalCopy(::IUnknown * other) noexcept
	{
		if (m_ptr != other)
		{
			InternalRelease();
			m_ptr = other;
			InternalAddRef();
		}
	}

	void InternalCopy(IUnknown const & other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			InternalAddRef();
		}
	}

	void InternalMove(IUnknown && other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	::IUnknown * m_ptr = nullptr;
	
private:

	void InternalAddRef() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void InternalRelease() noexcept
	{
		::IUnknown * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}
};

struct IInspectable;
struct IAsyncInfo;
struct IActivationFactory;

template <typename T> struct impl_IAsyncInfo;

}}

namespace Modern {

using IInspectable = Windows::IInspectable;

}

namespace Modern { namespace ABI {

using IInspectable = ::IInspectable;

}}

namespace Modern {

template <> struct Traits<Windows::IUnknown>
{
	using Abi = ::IUnknown;
};

template <> struct Traits<Windows::IInspectable>
{
	using Abi = ::IInspectable;
};

template <> struct Traits<Windows::IAsyncInfo>
{
	using Abi = ABI::Windows::IAsyncInfo;
	template <typename T> using Methods = Windows::impl_IAsyncInfo<T>;
};

template <> struct Traits<Windows::IActivationFactory>
{
	using Abi = ABI::Windows::IActivationFactory;
};

template <typename T, typename ... Args, IsNotComposable<T> = nullptr>
typename T::Default make(Args && ... args)
{
	typename T::Default instance;
	*set(instance) = new T(std::forward<Args>(args) ...);
	return instance;
}

template <typename T, typename ... Args, IsComposable<T> = nullptr>
typename T::Composable make(Args && ... args)
{
	Windows::IInspectable instance;
	*set(instance) = new T(std::forward<Args>(args) ...);
	return instance.As<T::Composable>();
}

template <typename T>
HRESULT call(T inner) noexcept
{
	try
	{
		inner();
	}
	catch (Exception const & e)
	{
		return e.Result;
	}
	catch (std::bad_alloc const &)
	{
		return E_OUTOFMEMORY;
	}
	catch (std::exception const &)
	{
		return E_FAIL;
	}

	return S_OK;
}

}

namespace Modern { namespace Windows {

inline bool operator==(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) == get(right);
}
inline bool operator!=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left == right);
}
inline bool operator<(IUnknown const & left, IUnknown const & right) noexcept
{
	return get(left) < get(right);
}
inline bool operator>(IUnknown const & left, IUnknown const & right) noexcept
{
	return right < left;
}
inline bool operator<=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(right < left);
}
inline bool operator>=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left < right);
}

struct IInspectable : IUnknown
{
	IInspectable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IInspectable>>(m_ptr); }

	String GetRuntimeClassName() const
	{
		String name;
		check((*this)->GetRuntimeClassName(set(name)));
		return name;
	}
};

template <typename T>
struct impl_IAsyncInfo
{
	unsigned Id() const
	{
		unsigned id;
		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_Id(&id));
		return id;
	}

	AsyncStatus Status() const
	{
		AsyncStatus status;
		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_Status(&status));
		return status;
	}

	HRESULT ErrorCode() const
	{
		HRESULT code;
		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->get_ErrorCode(&code));
		return code;
	}

	void Cancel() const
	{
		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->abi_Cancel());
	}

	void Close() const
	{
		check(static_cast<IAsyncInfo const &>(static_cast<T const &>(*this))->abi_Close());
	}
};

struct IAsyncInfo :
	IInspectable,
	impl_IAsyncInfo<IAsyncInfo>
{
	IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncInfo>>(m_ptr); }
};

template <typename T>
struct impl_IActivationFactory
{
	IInspectable ActivateInstance() const
	{
		IInspectable instance;
		check(static_cast<T const &>(*this)->abi_ActivateInstance(set(instance)));
		return instance;
	}
};

struct IActivationFactory :
	IInspectable,
	impl_IActivationFactory<IActivationFactory>
{
	IActivationFactory(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IActivationFactory>>(m_ptr); }
};

}}

namespace Modern {

inline void impl_ActivateInstance(HSTRING classId, Windows::IInspectable & instance)
{
	check(RoActivateInstance(classId, set(instance)));
}

template <typename Interface>
void impl_ActivateInstance(HSTRING classId, Interface & result)
{
	Windows::IInspectable instance;
	impl_ActivateInstance(classId, instance);
	result = instance.As<Interface>();
}

template <typename Class, typename Interface = typename Traits<Class>::Default>
Interface ActivateInstance()
{
	StringReference classId(Traits<Class>::Name(),
							Traits<Class>::NameLength);

	Interface instance;
	impl_ActivateInstance(classId, instance);
	return instance;
}

template <typename Class, typename Interface = Windows::IActivationFactory>
Interface GetActivationFactory()
{
	StringReference classId(Traits<Class>::Name(),
							Traits<Class>::NameLength);

	Interface factory;
	check(RoGetActivationFactory(classId, __uuidof(Abi<Interface>), reinterpret_cast<void **>(set(factory))));
	return factory;
}

}

namespace Modern { namespace ABI {

template <typename T>
struct Traits
{
	using Default = T;
};

template <typename T>
using Default = typename Traits<T>::Default;

template <typename T, typename Enable = void>
struct Argument
{
	using In = T;
	using Out = T *;
};

template <typename T>
struct Argument<T, typename std::enable_if<std::is_base_of<::IUnknown, T>::value>::type>
{
	using In = T *;
	using Out = T **;
};

template <typename T>
using ArgIn = typename Argument<Default<T>>::In;

template <typename T>
using ArgOut = typename Argument<Default<T>>::Out;

}}

namespace Modern {

template <typename T, typename Enable = void>
struct Argument
{
	static constexpr T Empty() noexcept
	{
		return {};
	}
};

template <typename T>
struct Argument<T, typename std::enable_if<std::is_base_of<Windows::IUnknown, T>::value>::type>
{
	static constexpr T Empty() noexcept
	{
		return nullptr;
	}
};

template <typename T>
using AbiArgIn = typename ABI::ArgIn<DefaultAbi<T>>;

template <typename T>
using AbiArgOut = typename ABI::ArgOut<DefaultAbi<T>>;

template <typename T, typename R>
struct impl_Requires : Traits<R>::template Methods<impl_Requires<T, R>>
{
	operator R() const noexcept
	{
		return static_cast<T const *>(this)->As<R>();
	}
};

template <typename T, typename ... R>
struct Requires : impl_Requires<T, R> ...
{};

template <typename T, typename B>
struct impl_Bases
{
	operator B() const noexcept
	{
		return static_cast<T const *>(this)->As<B>();
	}
};

template <typename T, typename ... B>
struct Bases : impl_Bases<T, B> ...
{};

template <typename ... R>
struct Overrides : Implements<R ...>
{
	template <typename T>
	T As() const
	{
		return m_inner.As<T>();
	}

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = BaseQueryInterface<R ...>(id);

		if (*object == nullptr)
		{
			return m_inner->QueryInterface(id, object);
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

protected:

	Windows::IInspectable m_inner;
};

}

namespace Modern { namespace ABI { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, ArgIn<TProgress> progressInfo) = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncActionProgressHandler<TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncActionProgressHandler<TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults() = 0;
};

template <typename TProgress>
struct __declspec(novtable) impl_IAsyncActionWithProgressCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationProgressHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, ArgIn<TProgress> progressInfo) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgressCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, AsyncStatus status) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperationCompletedHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, AsyncStatus status) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, ArgIn<T> args) = 0;
};

template <typename TSender, typename TArgs>
struct __declspec(novtable) impl_ITypedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(ArgIn<TSender> sender, ArgIn<TArgs> args) = 0;
};

template <typename TResult>
struct __declspec(novtable) impl_IAsyncOperation : IInspectable
{
	virtual HRESULT __stdcall put_Completed(IAsyncOperationCompletedHandler<TResult> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationCompletedHandler<TResult> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(ArgOut<TResult> results) = 0;
};

template <typename TResult, typename TProgress>
struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
{
	virtual HRESULT __stdcall put_Progress(IAsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Progress(IAsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall put_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
	virtual HRESULT __stdcall get_Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
	virtual HRESULT __stdcall abi_GetResults(ArgOut<TResult> results) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
	virtual HRESULT __stdcall get_Value(ArgOut<T> value) = 0;
};

}}}}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress> struct IAsyncActionProgressHandler;
template <typename TProgress> struct IAsyncActionWithProgress;
template <typename TProgress> struct IAsyncActionWithProgressCompletedHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationProgressHandler;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgressCompletedHandler;
template <typename TResult> struct IAsyncOperationCompletedHandler;
template <typename T> struct IEventHandler;
template <typename TSender, typename TArgs> struct ITypedEventHandler;
template <typename TResult> struct IAsyncOperation;
template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;
template <typename T> struct IReference;

template <typename D, typename TProgress>
struct impl_IAsyncActionProgressHandler
{
	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, TProgress const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgress
{
	void Progress(IAsyncActionProgressHandler<TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncActionProgressHandler<TProgress>(handler));
	}

	IAsyncActionProgressHandler<TProgress> Progress() const
	{
		IAsyncActionProgressHandler<TProgress> handler;
		check(static_cast<D const &>(*this)->get_Progress(set(handler)));
		return handler;
	}

	void Completed(IAsyncActionWithProgressCompletedHandler<TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncActionWithProgressCompletedHandler<TProgress>(handler));
	}

	IAsyncActionWithProgressCompletedHandler<TProgress> Completed() const
	{
		IAsyncActionWithProgressCompletedHandler<TProgress> handler;
		check(static_cast<D const &>(*this)->get_Completed(set(handler)));
		return handler;
	}

	void GetResults() const
	{
		check(static_cast<D const &>(*this)->abi_GetResults());
	}
};

template <typename D, typename TProgress>
struct impl_IAsyncActionWithProgressCompletedHandler
{
	void Invoke(IAsyncActionWithProgress<TProgress> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationProgressHandler
{
	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, TProgress const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgressCompletedHandler
{
	void Invoke(IAsyncOperationWithProgress<TResult, TProgress> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename TResult>
struct impl_IAsyncOperationCompletedHandler
{
	void Invoke(IAsyncOperation<TResult> const & sender, AsyncStatus const args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), args));
	}
};

template <typename D, typename T>
struct impl_IEventHandler
{
	void Invoke(IInspectable const & sender, T const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), abi(args)));
	}
};

template <typename D, typename TSender, typename TArgs>
struct impl_ITypedEventHandler
{
	void Invoke(TSender const & sender, TArgs const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(abi(sender), abi(args)));
	}
};

template <typename D, typename TResult>
struct impl_IAsyncOperation
{
	void Completed(IAsyncOperationCompletedHandler<TResult> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationCompletedHandler<TResult>(handler));
	}

	IAsyncOperationCompletedHandler<TResult> Completed() const
	{
		IAsyncOperationCompletedHandler<TResult> temp;
		check(static_cast<D const &>(*this)->get_Completed(set(temp)));
		return temp;
	}

	TResult GetResults() const
	{
		TResult result = Argument<TResult>::Empty();
		check(static_cast<D const &>(*this)->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename TResult, typename TProgress>
struct impl_IAsyncOperationWithProgress
{
	void Progress(IAsyncOperationProgressHandler<TResult, TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Progress(get(handler)));
	}

	template <typename Handler>
	void Progress(Handler handler) const
	{
		return Progress(AsyncOperationProgressHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationProgressHandler<TResult, TProgress> Progress() const
	{
		IAsyncOperationProgressHandler<TResult, TProgress> handler;
		check(static_cast<D const &>(*this)->get_Progress(set(handler)));
		return handler;
	}

	void Completed(IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> const & handler) const
	{
		check(static_cast<D const &>(*this)->put_Completed(get(handler)));
	}

	template <typename Handler>
	void Completed(Handler handler) const
	{
		return Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress>(handler));
	}

	IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const
	{
		IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
		check(static_cast<D const &>(*this)->get_Completed(set(handler)));
		return handler;
	}

	TResult GetResults() const
	{
		TResult result = Argument<TResult>::Empty();
		check(static_cast<D const &>(*this)->abi_GetResults(abi(&result)));
		return result;
	}
};

template <typename D, typename T>
struct impl_IReference
{
	T Value() const
	{
		T result = Argument<T>::Empty();
		check(static_cast<D const &>(*this)->get_Value(abi(&result)));
		return result;
	}
};

template <typename TProgress>
struct IAsyncActionProgressHandler :
	IUnknown,
	impl_IAsyncActionProgressHandler<IAsyncActionProgressHandler<TProgress>, TProgress>
{
	IAsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionProgressHandler>>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgress :
	IInspectable,
	impl_IAsyncActionWithProgress<IAsyncActionWithProgress<TProgress>, TProgress>,
	Requires<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
{
	IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionWithProgress>>(m_ptr); }
};

template <typename TProgress>
struct IAsyncActionWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncActionWithProgressCompletedHandler<IAsyncActionWithProgressCompletedHandler<TProgress>, TProgress>
{
	IAsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncActionWithProgressCompletedHandler>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationProgressHandler :
	IUnknown,
	impl_IAsyncOperationProgressHandler<IAsyncOperationProgressHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationProgressHandler>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgressCompletedHandler :
	IUnknown,
	impl_IAsyncOperationWithProgressCompletedHandler<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>, TResult, TProgress>
{
	IAsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationWithProgressCompletedHandler>>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperationCompletedHandler :
	IUnknown,
	impl_IAsyncOperationCompletedHandler<IAsyncOperationCompletedHandler<TResult>, TResult>
{
	IAsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationCompletedHandler>>(m_ptr); }
};

template <typename T>
struct IEventHandler :
	IUnknown,
	impl_IEventHandler<IEventHandler<T>, T>
{
	IEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IEventHandler>>(m_ptr); }
};

template <typename TSender, typename TArgs>
struct ITypedEventHandler :
	IUnknown,
	impl_ITypedEventHandler<ITypedEventHandler<TSender, TArgs>, TSender, TArgs>
{
	ITypedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<ITypedEventHandler>>(m_ptr); }
};

template <typename TResult>
struct IAsyncOperation :
	IInspectable,
	impl_IAsyncOperation<IAsyncOperation<TResult>, TResult>,
	Requires<IAsyncOperation<TResult>, IAsyncInfo>
{
	IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperation>>(m_ptr); }
};

template <typename TResult, typename TProgress>
struct IAsyncOperationWithProgress :
	IInspectable,
	impl_IAsyncOperationWithProgress<IAsyncOperationWithProgress<TResult, TProgress>, TResult, TProgress>,
	Requires<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
{
	IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IAsyncOperationWithProgress>>(m_ptr); }
};

struct IPropertyValue;

template <typename T>
struct IReference :
	IInspectable,
	impl_IReference<IReference<T>, T> // ,
	// Requires<IReference<T>, IPropertyValue>
{
	IReference(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IReference>>(m_ptr); }
};

}}}

namespace Modern {

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionProgressHandler<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionProgressHandler<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionProgressHandler<D, TProgress>;
};

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionWithProgress<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
};

template <typename TProgress> struct Traits<Windows::Foundation::IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncActionWithProgressCompletedHandler<Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncActionWithProgressCompletedHandler<D, TProgress>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationProgressHandler<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationProgressHandler<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationProgressHandler<D, TResult, TProgress>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgressCompletedHandler<D, TResult, TProgress>;
};

template <typename TResult> struct Traits<Windows::Foundation::IAsyncOperationCompletedHandler<TResult>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationCompletedHandler<Abi<TResult>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationCompletedHandler<D, TResult>;
};

template <typename T> struct Traits<Windows::Foundation::IEventHandler<T>>
{
	using Abi = ABI::Windows::Foundation::IEventHandler<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::impl_IEventHandler<D, T>;
};

template <typename TSender, typename TArgs> struct Traits<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	using Abi = ABI::Windows::Foundation::ITypedEventHandler<Abi<TSender>, Abi<TArgs>>;
	template <typename D> using Methods = Windows::Foundation::impl_ITypedEventHandler<D, TSender, TArgs>;
};

template <typename TResult> struct Traits<Windows::Foundation::IAsyncOperation<TResult>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperation<Abi<TResult>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
};

template <typename TResult, typename TProgress> struct Traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
{
	using Abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<Abi<TResult>, Abi<TProgress>>;
	template <typename D> using Methods = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
};

template <typename T> struct Traits<Windows::Foundation::IReference<T>>
{
	using Abi = ABI::Windows::Foundation::IReference<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::impl_IReference<D, T>;
};

}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

enum class CollectionChange
{
	Reset,
	ItemInserted,
	ItemRemoved,
	ItemChanged,
};

}}}}

namespace Modern { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(Modern::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Index(unsigned * value) = 0;
};

}}}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename D>
struct impl_IVectorChangedEventArgs
{
	CollectionChange CollectionChange() const
	{
		Collections::CollectionChange value = {};
		check(static_cast<D const &>(*this)->get_CollectionChange(&value));
		return value;
	}

	unsigned Index() const
	{
		unsigned index;
		check(static_cast<D const &>(*this)->get_Index(&index));
		return index;
	}
};

struct IVectorChangedEventArgs;

}}}}

namespace Modern {

template <> struct Traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
	template <typename T> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<T>;
};

}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

struct IVectorChangedEventArgs :
	IInspectable,
	impl_IVectorChangedEventArgs<IVectorChangedEventArgs>
{
	IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorChangedEventArgs>>(m_ptr); }
};

}}}}

namespace Modern { namespace ABI { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename T>
struct __declspec(novtable) impl_IIterator : IInspectable
{
	virtual HRESULT __stdcall get_Current(ArgOut<T> current) = 0;
	virtual HRESULT __stdcall get_HasCurrent(boolean * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_MoveNext(boolean * hasCurrent) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;

};

template <typename T>
struct __declspec(novtable) impl_IIterable : IInspectable
{
	virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IKeyValuePair : IInspectable
{
	virtual HRESULT __stdcall get_Key(ArgOut<K> key) = 0;
	virtual HRESULT __stdcall get_Value(ArgOut<V> value) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorView : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, ArgOut<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_IndexOf(ArgIn<T> value, unsigned * index, boolean * found) = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVector : IInspectable
{
	virtual HRESULT __stdcall abi_GetAt(unsigned index, ArgOut<T> item) = 0;
	virtual HRESULT __stdcall get_Size(unsigned * size) = 0;
	virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
	virtual HRESULT __stdcall abi_IndexOf(ArgIn<T> value, unsigned * index, boolean * found) = 0;
	virtual HRESULT __stdcall abi_SetAt(unsigned index, ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_InsertAt(unsigned index, ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) = 0;
	virtual HRESULT __stdcall abi_Append(ArgIn<T> item) = 0;
	virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, ArgOut<T> value, unsigned * actual) = 0;
	virtual HRESULT __stdcall abi_ReplaceAll(unsigned count, ArgOut<T> value) = 0;

};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapView : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(K const & key, ArgOut<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(K const & key, boolean * found) = 0;
	virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMap : IInspectable
{
	virtual HRESULT __stdcall abi_Lookup(K const & key, ArgOut<V> value) = 0;
	virtual HRESULT __stdcall get_Size(unsigned int * size) = 0;
	virtual HRESULT __stdcall abi_HasKey(K const & key, boolean * found) = 0;
	virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
	virtual HRESULT __stdcall abi_Insert(K const & key, V const & value, boolean * replaced) = 0;
	virtual HRESULT __stdcall abi_Remove(K const & key) = 0;
	virtual HRESULT __stdcall abi_Clear() = 0;
};

template <typename K>
struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
{
	virtual HRESULT __stdcall get_CollectionChange(Modern::Windows::Foundation::Collections::CollectionChange * value) = 0;
	virtual HRESULT __stdcall get_Key(ArgOut<K> value) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IMapChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
};

template <typename K, typename V>
struct __declspec(novtable) impl_IObservableMap : IInspectable
{
	virtual HRESULT __stdcall add_MapChanged(IMapChangedEventHandler<K, V> * handler, EventRegistrationToken * token) = 0;
	virtual HRESULT __stdcall remove_MapChanged(EventRegistrationToken token) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IVectorChangedEventHandler : IUnknown
{
	virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
};

template <typename T>
struct __declspec(novtable) impl_IObservableVector : IInspectable
{
	virtual HRESULT __stdcall add_VectorChanged(IVectorChangedEventHandler<T> * handler, EventRegistrationToken *  token) = 0;
	virtual HRESULT __stdcall remove_VectorChanged(EventRegistrationToken token) = 0;
};

}}}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T> struct IIterator;
template <typename T> struct IIterable;
template <typename K, typename V> struct IKeyValuePair;
template <typename T> struct IVectorView;
template <typename T> struct IVector;
template <typename K, typename V> struct IMapView;
template <typename K, typename V> struct IMap;
template <typename K> struct IMapChangedEventArgs;
template <typename K, typename V> struct IMapChangedEventHandler;
template <typename K, typename V> struct IObservableMap;
template <typename T> struct IVectorChangedEventHandler;
template <typename T> struct IObservableVector;

template <typename D, typename T>
struct impl_IIterator
{
	T Current() const
	{
		T result = Argument<T>::Empty();
		check(static_cast<D const &>(*this)->get_Current(abi(&result)));
		return result;
	}

	bool HasCurrent() const
	{
		boolean temp = 0;
		check(static_cast<D const &>(*this)->get_HasCurrent(&temp));
		return 0 != temp;
	}

	bool MoveNext() const
	{
		boolean temp = 0;
		check(static_cast<D const &>(*this)->abi_MoveNext(&temp));
		return 0 != temp;
	}

	impl_IIterator & operator++()
	{
		if (!MoveNext())
		{
			static_cast<D &>(*this) = nullptr;
		}

		return *this;
	}

	T operator *() const
	{
		return Current();
	}
};

template <typename D, typename T>
struct impl_IIterable
{
	IIterator<T> First() const
	{
		IIterator<T> iterator;
		check(static_cast<IIterable<T> const &>(static_cast<D const &>(*this))->abi_First(set(iterator)));
		return iterator;
	}
};

template <typename D, typename K, typename V>
struct impl_IKeyValuePair
{
	K Key() const
	{
		K result = Argument<K>::Empty();
		check(static_cast<D const &>(*this)->get_Key(abi(&result)));
		return result;
	}

	V Value() const
	{
		V result = Argument<V>::Empty();
		check(static_cast<D const &>(*this)->get_Value(abi(&result)));
		return result;
	}
};

template <typename D, typename T>
struct impl_IVectorView
{
	T GetAt(unsigned const index) const
	{
		T result = Argument<T>::Empty();
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->abi_GetAt(index, abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		boolean found = false;
		check(static_cast<IVectorView<T> const &>(static_cast<D const &>(*this))->abi_IndexOf(get(value), &index, &found));
		return 0 != found;
	}
};

template <typename D, typename T>
struct impl_IVector
{
	T GetAt(unsigned const index) const
	{
		T result = Argument<T>::Empty();
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_GetAt(index, abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	IVectorView<T> GetView() const
	{
		IVectorView<T> view;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_GetView(set(view)));
		return view;
	}

	bool IndexOf(T const & value, unsigned & index) const
	{
		boolean found = false;
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_IndexOf(abi(value), &index, &found));
		return 0 != found;
	}

	void SetAt(unsigned const index, T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_SetAt(index, abi(value)));
	}

	void InsertAt(unsigned const index, T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_InsertAt(index, abi(value)));
	}

	void RemoveAt(unsigned const index) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_RemoveAt(index));
	}

	void Append(T const & value) const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_Append(abi(value)));
	}

	void RemoveAtEnd() const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_RemoveAtEnd());
	}

	void Clear() const
	{
		check(static_cast<IVector<T> const &>(static_cast<D const &>(*this))->abi_Clear());
	}
};

template <typename D, typename K, typename V>
struct impl_IMapView
{
	V Lookup(K const & key) const
	{
		V result = Argument<V>::Empty();
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_Lookup(abi(key), abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		boolean found = false;
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
	{
		check(static_cast<IMapView<K, V> const &>(static_cast<D const &>(*this))->abi_Split(set(firstPartition), set(secondPartition)));
	}
};

template <typename D, typename K, typename V>
struct impl_IMap
{
	V Lookup(K const & key) const
	{
		V result = Argument<V>::Empty();
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Lookup(abi(key), abi(&result)));
		return result;
	}

	unsigned Size() const
	{
		unsigned size = 0;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->get_Size(&size));
		return size;
	}

	bool HasKey(K const & key) const
	{
		boolean found = false;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_HasKey(abi(key), &found));
		return 0 != found;
	}

	IMapView<K, V> GetView() const
	{
		IMapView<K, V> view;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_GetView(set(view)));
		return view;
	}

	bool Insert(K const & key, V const & value) const
	{
		boolean replaced = false;
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Insert(abi(key), abi(value), &replaced));
		return 0 != replaced;
	}

	void Remove(K const & key) const
	{
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Remove(abi(key)));
	}

	void Clear() const
	{
		check(static_cast<IMap<K, V> const &>(static_cast<D const &>(*this))->abi_Clear());
	}
};

template <typename D, typename K>
struct impl_IMapChangedEventArgs
{
	CollectionChange CollectionChange() const
	{
		CollectionChange value = {};
		check(static_cast<D const &>(*this)->get_CollectionChange(&value));
		return value;
	}

	K Key() const
	{
		K result = Argument<K>::Empty();
		check(static_cast<D const &>(*this)->get_Key(abi(&result)));
		return result;
	}
};

template <typename D, typename K, typename V>
struct impl_IMapChangedEventHandler
{
	void Invoke(IObservableMap<K, V> const & sender, IMapChangedEventArgs<K> const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename K, typename V>
struct impl_IObservableMap
{
	EventRegistrationToken MapChanged(IMapChangedEventHandler<K, V> const & handler) const
	{
		EventRegistrationToken cookie = {};
		check(static_cast<IObservableMap<K, V> const &>(static_cast<D const &>(*this))->add_MapChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename T> EventRegistrationToken MapChanged(T handler) const
	{
		return MapChanged(MapChangedEventHandler<K, V>(handler));
	}

	void MapChanged(EventRegistrationToken const cookie) const
	{
		check(static_cast<IObservableMap<K, V> const &>(static_cast<D const &>(*this))->remove_MapChanged(cookie));
	}
};

template <typename D, typename T>
struct impl_IVectorChangedEventHandler
{
	void Invoke(IObservableVector<T> const & sender, IVectorChangedEventArgs const & args) const
	{
		check(static_cast<D const &>(*this)->abi_Invoke(get(sender), get(args)));
	}
};

template <typename D, typename T>
struct impl_IObservableVector
{
	EventRegistrationToken VectorChanged(IVectorChangedEventHandler<T> const & handler) const
	{
		EventRegistrationToken cookie = {};
		check(static_cast<IObservableVector<T> const &>(static_cast<D const &>(*this))->add_VectorChanged(get(handler), &cookie));
		return cookie;
	}

	template <typename Handler> EventRegistrationToken VectorChanged(Handler handler) const
	{
		return VectorChanged(VectorChangedEventHandler<T>(handler));
	}

	void VectorChanged(EventRegistrationToken const cookie) const
	{
		check(static_cast<IObservableVector<T> const &>(static_cast<D const &>(*this))->remove_VectorChanged(cookie));
	}
};

template <typename T>
struct IIterator :
	IInspectable,
	impl_IIterator<IIterator<T>, T>
{
	IIterator(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IIterator>>(m_ptr); }
};

template <typename T>
struct IIterable :
	IInspectable,
	impl_IIterable<IIterable<T>, T>
{
	IIterable(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IIterable>>(m_ptr); }
};

template <typename K, typename V>
struct IKeyValuePair :
	IInspectable,
	impl_IKeyValuePair<IKeyValuePair<K, V>, K, V>
{
	IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IKeyValuePair>>(m_ptr); }
};

template <typename T>
struct IVectorView :
	IInspectable,
	impl_IVectorView<IVectorView<T>, T>,
	Requires<IVectorView<T>, IIterable<T>>
{
	IVectorView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorView>>(m_ptr); }
};

template <typename T>
struct IVector :
	IInspectable,
	impl_IVector<IVector<T>, T>,
	Requires<IVector<T>, IIterable<T>>
{
	IVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVector>>(m_ptr); }
};

template <typename K, typename V>
struct IMapView :
	IInspectable,
	impl_IMapView<IMapView<K, V>, K, V>,
	Requires<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMapView(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapView>>(m_ptr); }
};

template <typename K, typename V>
struct IMap :
	IInspectable,
	impl_IMap<IMap<K, V>, K, V>,
	Requires<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMap>>(m_ptr); }
};

template <typename K>
struct IMapChangedEventArgs :
	IInspectable,
	impl_IMapChangedEventArgs<IMapChangedEventArgs<K>, K>
{
	IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapChangedEventArgs>>(m_ptr); }
};

template <typename K, typename V>
struct IMapChangedEventHandler :
	IUnknown,
	impl_IMapChangedEventHandler<IMapChangedEventHandler<K, V>, K, V>
{
	IMapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IMapChangedEventHandler>>(m_ptr); }
};

template <typename K, typename V>
struct IObservableMap :
	IInspectable,
	impl_IObservableMap<IObservableMap<K, V>, K, V>,
	Requires<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
{
	IObservableMap(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IObservableMap>>(m_ptr); }
};

template <typename T>
struct IVectorChangedEventHandler :
	IUnknown,
	impl_IVectorChangedEventHandler<IVectorChangedEventHandler<T>, T>
{
	IVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IVectorChangedEventHandler>>(m_ptr); }
};

template <typename T>
struct IObservableVector :
	IInspectable,
	impl_IObservableVector<IObservableVector<T>, T>,
	Requires<IObservableVector<T>, IVector<T>, IIterable<T>>
{
	IObservableVector(std::nullptr_t = nullptr) noexcept {}
	auto operator->() const noexcept { return static_cast<AbiPtr<IObservableVector>>(m_ptr); }
};

}}}}

namespace Modern {

template <typename T> struct Traits<Windows::Foundation::Collections::IIterator<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IIterator<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterator<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IIterable<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IIterable<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IIterable<D, T>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IKeyValuePair<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVectorView<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorView<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorView<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVector<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVector<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVector<D, T>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMapView<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapView<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMap<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMap<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMap<D, K, V>;
};

template <typename K> struct Traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<Abi<K>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IMapChangedEventHandler<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IMapChangedEventHandler<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IMapChangedEventHandler<D, K, V>;
};

template <typename K, typename V> struct Traits<Windows::Foundation::Collections::IObservableMap<K, V>>
{
	using Abi = ABI::Windows::Foundation::Collections::IObservableMap<Abi<K>, Abi<V>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IVectorChangedEventHandler<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IVectorChangedEventHandler<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IVectorChangedEventHandler<D, T>;
};

template <typename T> struct Traits<Windows::Foundation::Collections::IObservableVector<T>>
{
	using Abi = ABI::Windows::Foundation::Collections::IObservableVector<Abi<T>>;
	template <typename D> using Methods = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
};

}

namespace Modern { namespace Windows { namespace Foundation {

template <typename TProgress, typename THandler>
struct impl_AsyncActionProgressHandler : ImplementsDefault<IAsyncActionProgressHandler<TProgress>>
{
	impl_AsyncActionProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncActionWithProgress<TProgress>> sender, AbiArgIn<TProgress> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncActionWithProgress<TProgress>>(sender), forward<TProgress>(args));
		});
	}
};

template <typename TProgress, typename THandler>
IAsyncActionProgressHandler<TProgress> AsyncActionProgressHandler(THandler handler)
{
	return make<impl_AsyncActionProgressHandler<TProgress, THandler>>(handler);
}

template <typename TProgress, typename THandler>
struct impl_AsyncActionWithProgressCompletedHandler : ImplementsDefault<IAsyncActionWithProgressCompletedHandler<TProgress>>
{
	impl_AsyncActionWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncActionWithProgress<TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncActionWithProgress<TProgress>>(sender), args);
		});
	}
};

template <typename TProgress, typename THandler>
IAsyncActionWithProgressCompletedHandler<TProgress> AsyncActionWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncActionWithProgressCompletedHandler<TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationProgressHandler : ImplementsDefault<IAsyncOperationProgressHandler<TResult, TProgress>>
{
	impl_AsyncOperationProgressHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperationWithProgress<TResult, TProgress>> sender, AbiArgIn<TProgress> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), forward<TProgress>(args));
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationProgressHandler<TResult, TProgress> AsyncOperationProgressHandler(THandler handler)
{
	return make<impl_AsyncOperationProgressHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename TProgress, typename THandler>
struct impl_AsyncOperationWithProgressCompletedHandler : ImplementsDefault<IAsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
{
	impl_AsyncOperationWithProgressCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperationWithProgress<TResult, TProgress>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperationWithProgress<TResult, TProgress>>(sender), args);
		});
	}
};

template <typename TResult, typename TProgress, typename THandler>
IAsyncOperationWithProgressCompletedHandler<TResult, TProgress> AsyncOperationWithProgressCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationWithProgressCompletedHandler<TResult, TProgress, THandler>>(handler);
}

template <typename TResult, typename THandler>
struct impl_AsyncOperationCompletedHandler : ImplementsDefault<IAsyncOperationCompletedHandler<TResult>>
{
	impl_AsyncOperationCompletedHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IAsyncOperation<TResult>> sender, AsyncStatus args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IAsyncOperation<TResult>>(sender), args);
		});
	}
};

template <typename TResult, typename THandler>
IAsyncOperationCompletedHandler<TResult> AsyncOperationCompletedHandler(THandler handler)
{
	return make<impl_AsyncOperationCompletedHandler<TResult, THandler>>(handler);
}

template <typename TArgs, typename THandler>
struct impl_EventHandler : ImplementsDefault<IEventHandler<TArgs>>
{
	impl_EventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<IInspectable> sender, AbiArgIn<TArgs> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<IInspectable>(sender), forward<TArgs>(args));
		});
	}
};

template <typename TArgs, typename THandler>
IEventHandler<TArgs> EventHandler(THandler handler)
{
	return make<impl_EventHandler<TArgs, THandler>>(handler);
}

template <typename TSender, typename TArgs, typename THandler>
struct impl_TypedEventHandler : ImplementsDefault<Windows::Foundation::ITypedEventHandler<TSender, TArgs>>
{
	impl_TypedEventHandler(THandler handler) : m_handler(handler) {}
	THandler m_handler;

	virtual HRESULT __stdcall abi_Invoke(AbiArgIn<TSender> sender, AbiArgIn<TArgs> args) noexcept override
	{
		return call([&]
		{
			m_handler(forward<TSender>(sender), forward<TArgs>(args));
		});
	}
};

template <typename TSender, typename TArgs, typename THandler>
ITypedEventHandler<TSender, TArgs> TypedEventHandler(THandler handler)
{
	return make<impl_TypedEventHandler<TSender, TArgs, THandler>>(handler);
}

}}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T, IsNotRandomAccess<T> = nullptr>
auto begin(T const & collection) -> decltype(collection.First())
{
	auto result = collection.First();

	if (!result.HasCurrent())
	{
		return {};
	}

	return result;
}

template <typename T, IsNotRandomAccess<T> = nullptr>
auto end(T const & collection) -> decltype(collection.First())
{
	collection;
	return {};
}

template <typename T, IsRandomAccess<T> = nullptr>
FastIterator<T> begin(T const & collection) noexcept
{
	return FastIterator<T>(collection, 0);
}

template <typename T, IsRandomAccess<T> = nullptr>
FastIterator<T> end(T const & collection)
{
	return FastIterator<T>(collection, collection.Size());
}

}}}}
