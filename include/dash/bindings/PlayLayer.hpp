#pragma once

#include "../internal.hpp"

#include "GameManager.hpp"
#include "GJBaseGameLayer.hpp"

namespace gd {
    class PlayLayer : public GJBaseGameLayer {
    public:
        inline static PlayLayer *get() {
            return GameManager::sharedState()->m_playLayer();
        }

        inline bool init(GJGameLevel *level, bool useReplay, bool dontCreateObjects) {
            SETUP_METHOD(bool, "PlayLayer::init", __thiscall, PlayLayer *, GJGameLevel *, bool, bool);
            return method(this, level, useReplay, dontCreateObjects);
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

        inline void playPlatformerEndAnimationToPos(cocos2d::CCPoint pos, bool unk) {
            SETUP_METHOD(void, "PlayLayer::playPlatformerEndAnimationToPos", __thiscall, PlayLayer *, cocos2d::CCPoint,
                         bool);
            method(this, pos, unk);
        }

        inline void playEndAnimationToPos(cocos2d::CCPoint pos) {
            SETUP_METHOD(void, "PlayLayer::playEndAnimationToPos", __thiscall, PlayLayer *, cocos2d::CCPoint);
            method(this, pos);
        }

        inline int getCurrentPercentInt() {
            SETUP_METHOD(int, "PlayLayer::getCurrentPercentInt", __thiscall, PlayLayer *);
            return method(this);
        }

        inline void destroyPlayer(PlayerObject *player, GameObject *object) {
            SETUP_METHOD(void, "PlayLayer::destroyPlayer", __thiscall, PlayLayer *, PlayerObject *, GameObject *);
            method(this, player, object);
        }

        inline void postUpdate(float dt) {
            SETUP_METHOD(void, "PlayLayer::postUpdate", __thiscall, PlayLayer *, float);
            method(this, dt);
        }

        inline void updateDebugDraw() {
            SETUP_METHOD(void, "PlayLayer::updateDebugDraw", __thiscall, PlayLayer *);
            method(this);
        }

        SETUP_MEMBER(cocos2d::CCDrawNode*, m_debugDrawNode, "PlayLayer::m_debugDrawNode")
        SETUP_MEMBER(bool, m_isPaused, "PlayLayer::m_isPaused")
        SETUP_MEMBER(bool, m_hasCompletedLevel, "PlayLayer::m_hasCompletedLevel")
    };
}