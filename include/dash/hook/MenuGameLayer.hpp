#pragma once

#include "hook.hpp"
#include "../bindings/MenuGameLayer.hpp"

namespace gd::hook::MenuGameLayer {

    // MenuGameLayer::update

    inline static uintptr_t update_addr = 0x0;
    inline static std::function<void(gd::MenuGameLayer*, float)> update_hook;

    /// @brief Calls the original MenuGameLayer::update function.
    inline static void update(gd::MenuGameLayer* self, float dt) {
        reinterpret_cast<void (__thiscall *)(gd::MenuGameLayer*, float)>(update_addr)(self, dt);
    }

    /// @brief Wrapper for the MenuGameLayer::update hook.
    inline void __fastcall updateHook(gd::MenuGameLayer* self, int, float dt) { update_hook(self, dt); }

    /// @brief Installs the hook for MenuGameLayer::update.
    SETUP_HOOK("MenuGameLayer::update", void, update, gd::MenuGameLayer*, float)

    // MenuGameLayer::tryJump

    inline static uintptr_t tryJump_addr = 0x0;
    inline static std::function<bool(gd::MenuGameLayer*, float)> tryJump_hook;

    /// @brief Calls the original MenuGameLayer::tryJump function.
    inline static bool tryJump(gd::MenuGameLayer* self, float dt) {
        return reinterpret_cast<bool (__thiscall *)(gd::MenuGameLayer*, float)>(tryJump_addr)(self, dt);
    }

    /// @brief Wrapper for the MenuGameLayer::tryJump hook.
    inline bool __fastcall tryJumpHook(gd::MenuGameLayer* self, int, float dt) { return tryJump_hook(self, dt); }

    /// @brief Installs the hook for MenuGameLayer::tryJump.
    SETUP_HOOK("MenuGameLayer::tryJump", bool, tryJump, gd::MenuGameLayer*, float)

}