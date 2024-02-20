#pragma once

#include "../internal.hpp"

#include "GameManager.hpp"

namespace gd {
    class GJGameLevel;

    class GameObject;

    class PlayerObject;

    class PlayLayer {
    public:
        inline static PlayLayer* get() {
            return GameManager::sharedState()->m_playLayer();
        }

        inline bool init(GJGameLevel *level, bool unk, bool unk2) {
            SETUP_METHOD(bool, "PlayLayer::init", __thiscall, PlayLayer *, GJGameLevel *, bool, bool);
            return method(this, level, unk, unk2);
        }

        inline void update(float dt) {
            SETUP_METHOD(void, "PlayLayer::update", __thiscall, PlayLayer *, float);
            method(this, dt);
        }

        inline void destructor() {
            SETUP_METHOD(void, "PlayLayer::~PlayLayer", __thiscall, PlayLayer *);
            method(this);
        }

        inline void resetLevel() {
            SETUP_METHOD(void, "PlayLayer::resetLevel", __thiscall, PlayLayer *);
            method(this);
        }

        inline int onQuit() {
            SETUP_METHOD(int, "PlayLayer::onQuit", __thiscall, PlayLayer *);
            return method(this);
        }

        inline void addObject(GameObject *obj) {
            SETUP_METHOD(void, "PlayLayer::addObject", __thiscall, PlayLayer *, GameObject *);
            method(this, obj);
        }

        inline void destroyObject(GameObject *obj) {
            SETUP_METHOD(void, "PlayLayer::destroyObject", __thiscall, PlayLayer *, GameObject *);
            method(this, obj);
        }

        inline void pickupCoin(GameObject *obj) {
            SETUP_METHOD(void, "PlayLayer::pickupCoin", __thiscall, PlayLayer *, GameObject *);
            method(this, obj);
        }

        inline void setStartPosObject(GameObject *obj) {
            SETUP_METHOD(void, "PlayLayer::setStartPosObject", __thiscall, PlayLayer *, GameObject *);
            method(this, obj);
        }

        inline void startMusic() {
            SETUP_METHOD(void, "PlayLayer::startMusic", __thiscall, PlayLayer *);
            method(this);
        }

        inline void resetLevelFromStart() {
            SETUP_METHOD(void, "PlayLayer::resetLevelFromStart", __thiscall, PlayLayer *);
            method(this);
        }

        inline void togglePracticeMode(bool value) {
            SETUP_METHOD(void, "PlayLayer::togglePracticeMode", __thiscall, PlayLayer *, bool);
            method(this, value);
        }

        SETUP_MEMBER(bool, m_isPracticeMode, "PlayLayer::m_isPracticeMode")
        SETUP_MEMBER(void *, m_startPosCheckpoint, "PlayLayer::m_startPosCheckpoint")
        SETUP_MEMBER(int, m_jumps, "PlayLayer::m_jumps")
        SETUP_MEMBER(int, m_attempts, "PlayLayer::m_attempts")
        SETUP_MEMBER(bool, m_isAlive, "PlayLayer::m_isAlive")
        SETUP_MEMBER(bool, m_isDead, "PlayLayer::m_isDead")
        SETUP_MEMBER(PlayerObject *, m_player1, "PlayLayer::m_player1")
        SETUP_MEMBER(PlayerObject *, m_player2, "PlayLayer::m_player2")
        SETUP_MEMBER(GJGameLevel *, m_level, "PlayLayer::m_level")
        SETUP_MEMBER(double, m_time, "PlayLayer::m_time")
        SETUP_MEMBER(bool, m_dualMode, "PlayLayer::m_dualMode")
        SETUP_MEMBER(bool, m_hasCompleted, "PlayLayer::m_hasCompleted")
    };
}