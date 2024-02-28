#pragma once

#include "../internal.hpp"

namespace gd {
    class GJGameLevel;

    class GameLevelManager {
    public:
        inline static GameLevelManager* sharedState() {
            SETUP_METHOD(GameLevelManager*, "GameLevelManager::sharedState", __stdcall);
            return method();
        }

        inline void saveLevel(GJGameLevel* level) {
            SETUP_METHOD(void, "GameLevelManager::saveLevel", __thiscall, GameLevelManager*, GJGameLevel*);
            method(this, level);
        }
    };
}