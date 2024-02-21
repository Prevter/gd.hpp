#pragma once

#include "../internal.hpp"

namespace gd {
    class AppDelegate {
    public:
        inline void applicationWillEnterForeground() {
            SETUP_METHOD(void, "AppDelegate::applicationWillEnterForeground", __thiscall, AppDelegate*);
            return method(this);
        }
    };
}