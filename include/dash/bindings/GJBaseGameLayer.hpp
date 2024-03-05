#pragma once

#include "../internal.hpp"
#include "cocos/CCArray.hpp"
#include "cocos/CCLayer.hpp"
#include "GameManager.hpp"
#include "GJGameState.hpp"

namespace gd {
    class GJGameLevel;
    class GameObject;
    class PlayerObject;

    class GJBaseGameLayer : public cocos2d::CCLayer {
    public:
        inline static GJBaseGameLayer *get() {
            return GameManager::sharedState()->m_gameLayer();
        }

        inline void update(float dt) {
            SETUP_METHOD(void, "GJBaseGameLayer::update", __thiscall, GJBaseGameLayer*, float);
            method(this, dt);
        }

        inline void resetCamera() {
            SETUP_METHOD(void, "GJBaseGameLayer::resetCamera", __thiscall, GJBaseGameLayer*);
            return method(this);
        }

        inline void addObject(GameObject *obj) {
            SETUP_METHOD(void, "GJBaseGameLayer::addObject", __thiscall, GJBaseGameLayer*, GameObject *);
            method(this, obj);
        }

        inline void destroyObject(GameObject *obj) {
            SETUP_METHOD(void, "GJBaseGameLayer::destroyObject", __thiscall, GJBaseGameLayer*, GameObject *);
            method(this, obj);
        }

        inline void pickupItem(GameObject *obj) {
            SETUP_METHOD(void, "GJBaseGameLayer::pickupItem", __thiscall, GJBaseGameLayer*, GameObject *);
            method(this, obj);
        }

        inline void setStartPosObject(GameObject *obj) {
            SETUP_METHOD(void, "GJBaseGameLayer::setStartPosObject", __thiscall, GJBaseGameLayer*, GameObject *);
            method(this, obj);
        }

        inline void processCommands() {
            SETUP_METHOD(void, "GJBaseGameLayer::processCommands", __thiscall, GJBaseGameLayer*);
            method(this);
        }

        SETUP_MEMBER(bool, m_isPracticeMode, "GJBaseGameLayer::m_isPracticeMode")
        SETUP_MEMBER(void *, m_startPosCheckpoint, "GJBaseGameLayer::m_startPosCheckpoint")
        SETUP_MEMBER(int, m_jumps, "GJBaseGameLayer::m_jumps")
        SETUP_MEMBER(int, m_attempts, "GJBaseGameLayer::m_attempts")
        SETUP_MEMBER(bool, m_isAlive, "GJBaseGameLayer::m_isAlive")
        SETUP_MEMBER(bool, m_isDead, "GJBaseGameLayer::m_isDead")
        SETUP_MEMBER(PlayerObject *, m_player1, "GJBaseGameLayer::m_player1")
        SETUP_MEMBER(PlayerObject *, m_player2, "GJBaseGameLayer::m_player2")
        SETUP_MEMBER(GJGameLevel *, m_level, "GJBaseGameLayer::m_level")
        SETUP_MEMBER(double, m_time, "GJBaseGameLayer::m_time")
        SETUP_MEMBER(bool, m_dualMode, "GJBaseGameLayer::m_dualMode")
        SETUP_MEMBER(bool, m_hasCompleted, "GJBaseGameLayer::m_hasCompleted")
        SETUP_MEMBER(GJGameState, m_gameState, "GJBaseGameLayer::m_gameState")
        SETUP_MEMBER(cocos2d::CCArray*, m_objects, "GJBaseGameLayer::m_objects")
    };
}