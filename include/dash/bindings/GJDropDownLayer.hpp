#pragma once

#include "../internal.hpp"
#include "cocos/CCLayer.hpp"

namespace gd {
    class GJDropDownLayer : public cocos2d::CCLayer {
    public:
        inline void showLayer(bool val) {
            SETUP_METHOD(void, "GJDropDownLayer::showLayer", __thiscall, GJDropDownLayer*, bool);
            return method(this, val);
        }
    };
}