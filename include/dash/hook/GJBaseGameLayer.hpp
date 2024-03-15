#pragma once

#include "hook.hpp"
#include "../bindings/GJBaseGameLayer.hpp"

namespace gd::hook::GJBaseGameLayer {

    // GJBaseGameLayer::processCommands

    inline static uintptr_t processCommands_addr = 0x0;
    inline static std::function<void(gd::GJBaseGameLayer*)> processCommands_hook;

    /// @brief Calls the original GameStatsManager::isItemUnlocked function.
    inline static void processCommands(gd::GJBaseGameLayer* self) {
        reinterpret_cast<void (__thiscall *)(gd::GJBaseGameLayer*)>(processCommands_addr)(self);
    }

    /// @brief Wrapper for the GameStatsManager::isItemUnlocked hook.
    inline void __fastcall processCommandsHook(gd::GJBaseGameLayer* self) { processCommands_hook(self); }

    /// @brief Installs the hook for GameStatsManager::isItemUnlocked.
    SETUP_HOOK("GJBaseGameLayer::processCommands", void, processCommands, gd::GJBaseGameLayer*)

    // GJBaseGameLayer::update

    inline static uintptr_t update_addr = 0x0;
    inline static std::function<void(gd::GJBaseGameLayer*, float)> update_hook;

    /// @brief Calls the original GJBaseGameLayer::update function.
    inline static void update(gd::GJBaseGameLayer* self, float dt) {
        reinterpret_cast<void (__thiscall *)(gd::GJBaseGameLayer*, float)>(update_addr)(self, dt);
    }

    /// @brief Wrapper for the GJBaseGameLayer::update hook.
    inline void __fastcall updateHook(gd::GJBaseGameLayer* self, float dt) { update_hook(self, dt); }

    /// @brief Installs the hook for GJBaseGameLayer::update.
    SETUP_HOOK("GJBaseGameLayer::update", void, update, gd::GJBaseGameLayer*, float)

}