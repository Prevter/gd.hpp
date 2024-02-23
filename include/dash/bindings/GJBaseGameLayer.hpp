#pragma once

#include "../internal.hpp"
#include "cocos/CCLayer.hpp"
#include "GameManager.hpp"

namespace gd {
    class GJBaseGameLayer : public cocos2d::CCLayer {
    public:
        inline static GJBaseGameLayer* get() {
            return GameManager::sharedState()->m_gameLayer();
        }

        inline void resetCamera() {
            SETUP_METHOD(void, "GJBaseGameLayer::resetCamera", __thiscall, GJBaseGameLayer*);
            return method(this);
        }
    };
}