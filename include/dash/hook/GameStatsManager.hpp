#pragma once

#include "hook.hpp"
#include "../bindings/GameStatsManager.hpp"

namespace gd::hook::GameStatsManager {

    // GameStatsManager::isItemUnlocked

    inline static uintptr_t isItemUnlocked_addr = 0x0;
    inline static std::function<bool(gd::GameStatsManager*, int, int)> isItemUnlocked_hook;

    /// @brief Calls the original GameStatsManager::isItemUnlocked function.
    inline static bool isItemUnlocked(gd::GameStatsManager* self, int id, int type) {
        return reinterpret_cast<bool (__thiscall *)(gd::GameStatsManager*, int, int)>(isItemUnlocked_addr)(self, id, type);
    }

    /// @brief Wrapper for the GameStatsManager::isItemUnlocked hook.
    inline bool __fastcall isItemUnlockedHook(gd::GameStatsManager* self, int, int id, int type) { return isItemUnlocked_hook(self, id, type); }

    /// @brief Installs the hook for GameStatsManager::isItemUnlocked.
    SETUP_HOOK("GameStatsManager::isItemUnlocked", bool, isItemUnlocked, gd::GameStatsManager*, int, int)

}