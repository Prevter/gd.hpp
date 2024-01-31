// utils/platform/platform.hpp
// ~~~~~~~~~~~~~~~~
// Wraps platform-specific includes.
// ~~~~~~~~~~~~~~~~

#pragma once

#if defined(_WIN32) || defined(_WIN64)
#include "win32.hpp"
#elif defined(__APPLE__)
#if defined(__MACH__)
#error "macOS is not supported yet."
#include "macos.hpp"
#else
#error "iOS is not supported yet."
#include "ios.hpp"
#endif
#elif defined(__ANDROID__)
#error "Android is not supported yet."
#include "android.hpp"
#endif