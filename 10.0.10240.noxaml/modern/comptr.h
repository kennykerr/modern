// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#include <modern\debug.h>

namespace Modern {

template <typename T>
class NoAddRefRelease : public T
{
	unsigned long __stdcall AddRef();
	unsigned long __stdcall Release();
};

template <typename T>
class ComPtr
{
public:

	using Type = T;

	ComPtr() noexcept = default;

	ComPtr(ComPtr const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		InternalAddRef();
	}

	template <typename T>
	ComPtr(ComPtr<T> const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		InternalAddRef();
	}

	template <typename T>
	ComPtr(ComPtr<T> && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~ComPtr() noexcept
	{
		InternalRelease();
	}

	ComPtr & operator=(ComPtr const & other) noexcept
	{
		InternalCopy(other.m_ptr);
		return *this;
	}

	template <typename T>
	ComPtr & operator=(ComPtr<T> const & other) noexcept
	{
		InternalCopy(other.m_ptr);
		return *this;
	}

	template <typename T>
	ComPtr & operator=(ComPtr<T> && other) noexcept
	{
		InternalMove(other);
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	NoAddRefRelease<T> * operator->() const noexcept
	{
		return static_cast<NoAddRefRelease<T> *>(m_ptr);
	}

	friend T * get(ComPtr const & object) noexcept
	{
		return object.m_ptr;
	}

	friend T ** set(ComPtr & object) noexcept
	{
		MODERN_ASSERT(object.m_ptr == nullptr);
		return &object.m_ptr;
	}

	friend void attach(ComPtr & object, T * value) noexcept
	{
		object.InternalRelease();
		object.m_ptr = value;
	}

	friend T * detach(ComPtr & object) noexcept
	{
		T * temp = object.m_ptr;
		object.m_ptr = nullptr;
		return temp;
	}

	friend void swap(ComPtr & left, ComPtr & right) noexcept
	{
		T * temp = left.m_ptr;
		left.m_ptr = right.m_ptr;
		right.m_ptr = temp;
	}

	ComPtr & operator=(std::nullptr_t) noexcept
	{
		InternalRelease();
		return *this;
	}

	template <typename T>
	ComPtr<T> As() const noexcept
	{
		ComPtr<T> temp;
		m_ptr->QueryInterface(temp.GetAddressOf());
		return temp;
	}

	void CopyFrom(T * other) noexcept
	{
		InternalCopy(other);
	}

	void CopyTo(T ** other) const noexcept
	{
		InternalAddRef();
		*other = m_ptr;
	}

private:

	void InternalCopy(T * other) noexcept
	{
		if (m_ptr != other)
		{
			InternalRelease();
			m_ptr = other;
			InternalAddRef();
		}
	}

	template <typename T>
	void InternalMove(ComPtr<T> & other) noexcept
	{
		if (m_ptr != other.m_ptr)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

	void InternalAddRef() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void InternalRelease() noexcept
	{
		T * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}

	template <typename T>
	friend class ComPtr;

	T * m_ptr = nullptr;
};

template <typename T>
bool operator==(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(ComPtr<T> const & left, ComPtr<T> const & right) noexcept
{
	return !(left < right);
}

}
