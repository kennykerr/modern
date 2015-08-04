// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#include <modern\debug.h>

namespace Modern {

template <typename T>
struct HandleTraits
{
	using Type = T;

	constexpr static Type Invalid() noexcept
	{
		return nullptr;
	}

	// static void Close(Type value) noexcept;
};

template <typename T>
class Handle
{
public:

	using Type = typename T::Type;

	Handle() noexcept = default;
	Handle(Handle const &) = delete;
	Handle & operator=(Handle const &) = delete;

	Handle(Type value) noexcept :
		m_value(value)
	{}

	Handle(Handle && other) noexcept :
		m_value(detach(other))
	{}

	Handle & operator=(Handle && other) noexcept
	{
		if (this != &other)
		{
			attach(*this, detach(other));
		}

		return *this;
	}

	~Handle() noexcept
	{
		Close();
	}

	void Close() noexcept
	{
		if (*this)
		{
			T::Close(m_value);
		}
	}

	explicit operator bool() const noexcept
	{
		return m_value != T::Invalid();
	}

	friend Type get(Handle const & handle) noexcept
	{
		return handle.m_value;
	}

	friend Type * set(Handle & handle) noexcept
	{
		MODERN_ASSERT(!handle);
		return &handle.m_value;
	}
	
	friend void attach(Handle & handle, Type value) noexcept
	{
		handle.Close();
		handle.m_value = value;
	}

	friend Type detach(Handle & handle) noexcept
	{
		Type value = handle.m_value;
		handle.m_value = T::Invalid();
		return value;
	}

	friend void swap(Handle & left, Handle & right) noexcept
	{
		Type temp = left.m_value;
		left.m_value = right.m_value;
		right.m_value = temp;
	}

private:

	Type m_value = T::Invalid();

};

template <typename T>
bool operator==(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return get(left) == get(right);
}

template <typename T>
bool operator!=(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return !(left == right);
}

template <typename T>
bool operator<(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return get(left) < get(right);
}

template <typename T>
bool operator>(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return right < left;
}

template <typename T>
bool operator<=(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return !(right < left);
}

template <typename T>
bool operator>=(Handle<T> const & left, Handle<T> const & right) noexcept
{
	return !(left < right);
}

}
