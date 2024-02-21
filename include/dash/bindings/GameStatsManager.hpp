#pragma once

#include "../internal.hpp"

namespace gd {
    class GameStatsManager {
    public:
        inline bool isItemUnlocked(int id, int type) {
            SETUP_METHOD(bool, "GameStatsManager::isItemUnlocked", __thiscall, GameStatsManager*, int, int);
            return method(this, id, type);
        }
    };
}