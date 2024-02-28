#pragma once

#include "../internal.hpp"
#include "cocos/CCDictionary.hpp"

namespace gd {
    class GJGameLevel;

    class GameStatsManager {
    public:
        inline static GameStatsManager* sharedState() {
            SETUP_METHOD(GameStatsManager*, "GameStatsManager::sharedState", __stdcall);
            return method();
        }

        inline bool isItemUnlocked(int id, int type) {
            SETUP_METHOD(bool, "GameStatsManager::isItemUnlocked", __thiscall, GameStatsManager*, int, int);
            return method(this, id, type);
        }

        inline void uncompleteLevel(GJGameLevel *level) {
            SETUP_METHOD(void, "GameStatsManager::uncompleteLevel", __thiscall, GameStatsManager*, GJGameLevel*);
            method(this, level);
        }

        SETUP_MEMBER(cocos2d::CCDictionary*, m_verifiedUserCoins, "GameStatsManager::m_verifiedUserCoins")
    };
}