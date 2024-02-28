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
    };
}