#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCArray {
    public:
        inline int count() {
            SETUP_METHOD_SIG(int, "cocos2d::CCArray::count", __thiscall, CCArray*);
            return method(this);
        }
    };
}