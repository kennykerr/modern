// Modern v1.26 - http://moderncpp.com
// Copyright (c) 2015 Kenny Kerr

#pragma once

#ifdef _DEBUG

#include <crtdbg.h>

#define MODERN_ASSERT _ASSERTE
#define MODERN_VERIFY MODERN_ASSERT
#define MODERN_VERIFY_(result, expression) MODERN_ASSERT(result == expression)

template <typename ... Args>
void MODERN_TRACE(wchar_t const * const message, Args ... args) noexcept
{
	wchar_t buffer[512] = {};
	swprintf_s(buffer, message, args ...);
	OutputDebugString(buffer);
}

#else

#define MODERN_ASSERT __noop
#define MODERN_VERIFY(expression) (expression)
#define MODERN_VERIFY_(result, expression) (expression)
#define MODERN_TRACE __noop

#endif
