#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCApplication {
    public:
        inline static CCApplication* sharedApplication() {
            SETUP_METHOD_SIG(CCApplication*, "cocos2d::CCApplication::sharedApplication", __cdecl);
            return method();
        }

        inline void toggleVerticalSync(bool enabled) {
            SETUP_METHOD_SIG(void, "cocos2d::CCApplication::toggleVerticalSync", __thiscall, CCApplication*, bool);
            return method(this, enabled);
        }
    };
}