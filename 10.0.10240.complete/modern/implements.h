// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#include <inspectable.h>
#include <type_traits>

#pragma comment(lib, "ole32")

namespace Modern {

template <typename Interface>
struct Cloaked : Interface {};

template <typename ... Interfaces>
class __declspec(novtable) Implements : public Interfaces ...
{
	template <typename Interface>
	struct IsCloaked : std::false_type {};

	template <typename Interface>
	struct IsCloaked<Cloaked<Interface>> : std::true_type {};

	template <int = 0>
	constexpr unsigned CountInterfaces() const noexcept
	{
		return 0;
	}

	template <typename First, typename ... Rest>
	constexpr unsigned CountInterfaces() const noexcept
	{
		return !IsCloaked<First>::value + CountInterfaces<Rest ...>();
	}

	template <int = 0>
	constexpr bool IsInspectable() const noexcept
	{
		return false;
	}

	template <typename First, typename ... Rest>
	constexpr bool IsInspectable() const noexcept
	{
		return std::is_base_of<::IInspectable, First>::value || IsInspectable<Rest ...>();
	}

	template <int = 0>
	void * FindInspectable() noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * FindInspectable() noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (std::is_base_of<::IInspectable, First>::value)
		{
			return static_cast<First *>(this);
		}

		#pragma warning(pop)

		return FindInspectable<Rest ...>();
	}

	template <int = 0>
	void CopyInterfaces(GUID *) const noexcept {}

	template <typename First, typename ... Rest>
	void CopyInterfaces(GUID * ids) const noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (!IsCloaked<First>::value)
		{
			*ids++ = __uuidof(First);
		}

		#pragma warning(pop)

		CopyInterfaces<Rest ...>(ids);
	}

	template <int = 0>
	void * FindInterface(GUID const &) noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * FindInterface(GUID const & id) noexcept
	{
		if (id == __uuidof(First))
		{
			return static_cast<First *>(this);
		}

		return FindInterface<Rest ...>(id);
	}

protected:

	unsigned long m_references = 1;

	Implements() noexcept = default;

	virtual ~Implements() noexcept
	{}

    template <typename First, typename ... Rest>
    void * BaseQueryInterface(GUID const & id) noexcept
    {
        if (id == __uuidof(First) || id == __uuidof(::IUnknown))
        {
            return static_cast<First *>(this);
        }

        if (IsInspectable<Interfaces ...>() && id == __uuidof(::IInspectable))
        {
            return FindInspectable<Interfaces ...>();
        }

        return FindInterface<Rest ...>(id);
    }

public:

	Implements(Implements const &) = delete;
	Implements & operator=(Implements const &) = delete;

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = BaseQueryInterface<Interfaces ...>(id);

		if (nullptr == *object)
		{
			return E_NOINTERFACE;
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

	virtual unsigned long __stdcall AddRef() noexcept override
	{
		return InterlockedIncrement(&m_references);
	}

	virtual unsigned long __stdcall Release() noexcept override
	{
		unsigned long const remaining = InterlockedDecrement(&m_references);

		if (0 == remaining)
		{
			delete this;
		}

		return remaining;
	}

	HRESULT __stdcall GetIids(unsigned long * count, GUID ** array) noexcept
	{
		*count = 0;
		*array = nullptr;

		unsigned const localCount = CountInterfaces<Interfaces ...>();

		if (0 == localCount)
		{
			return S_OK;
		}

		GUID * localArray = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * localCount));

		if (nullptr == localArray)
		{
			return E_OUTOFMEMORY;
		}

		CopyInterfaces<Interfaces ...>(localArray);

		*count = localCount;
		*array = localArray;
		return S_OK;
	}

	HRESULT __stdcall GetRuntimeClassName(HSTRING * name) noexcept
	{
		*name = nullptr;
		return E_NOTIMPL;
	}

	HRESULT __stdcall GetTrustLevel(TrustLevel * trustLevel) noexcept
	{
		*trustLevel = BaseTrust;
		return S_OK;
	}
};

}
