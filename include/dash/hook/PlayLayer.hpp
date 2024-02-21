#pragma once

#include "hook.hpp"
#include "../bindings/PlayLayer.hpp"

namespace gd::hook::PlayLayer {

    // PlayLayer::resetLevel

    inline static uintptr_t resetLevel_addr = 0x0;
    inline static std::function<void(gd::PlayLayer*)> resetLevel_hook;

    /// @brief Calls the original PlayLayer::resetLevel function.
    inline static void resetLevel(gd::PlayLayer* self) {
        return reinterpret_cast<void (__thiscall *)(gd::PlayLayer*)>(resetLevel_addr)(self);
    }

    /// @brief Wrapper for the PlayLayer::resetLevel hook.
    inline void __fastcall resetLevelHook(gd::PlayLayer* self) { return resetLevel_hook(self); }

    /// @brief Installs the hook for PlayLayer::resetLevel.
    SETUP_HOOK("PlayLayer::resetLevel", void, resetLevel, gd::PlayLayer*)

}