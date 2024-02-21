#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCScheduler {
    public:
        inline void update(float dt) {
            SETUP_METHOD_SIG(void, "cocos2d::CCScheduler::update", __thiscall, CCScheduler*, float);
            return method(this, dt);
        }
    };
}