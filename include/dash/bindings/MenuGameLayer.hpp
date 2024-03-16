#pragma once

#include "../internal.hpp"
#include "cocos/CCLayer.hpp"

namespace gd {
    class PlayerObject;

    class MenuGameLayer : public cocos2d::CCLayer {
    public:
        inline void update(float dt) {
            SETUP_METHOD(void, "MenuGameLayer::update", __thiscall, MenuGameLayer*, float);
            method(this, dt);
        }

        inline bool tryJump(float dt) {
            SETUP_METHOD(bool, "MenuGameLayer::tryJump", __thiscall, MenuGameLayer*, float);
            return method(this, dt);
        }

        SETUP_MEMBER(PlayerObject *, m_playerObject, "MenuGameLayer::m_playerObject")
    };
}