#pragma once

#include "../hook.hpp"
#include "../../bindings/cocos/CCScheduler.hpp"

namespace gd::hook::CCScheduler {

    // CCScheduler::update

    inline static uintptr_t update_addr = 0x0;
    inline static std::function<void(cocos2d::CCScheduler*, float)> update_hook;

    /// @brief Calls the original CCScheduler::update function.
    inline static void update(cocos2d::CCScheduler* self, float dt) {
        return reinterpret_cast<void (__thiscall *)(cocos2d::CCScheduler*, float)>(update_addr)(self, dt);
    }

    /// @brief Wrapper for the CCScheduler::update hook.
    inline void __fastcall updateHook(cocos2d::CCScheduler* self, int, float dt) { update_hook(self, dt); }

    /// @brief Installs the hook for CCScheduler::update.
    SETUP_HOOK_SIG("cocos2d::CCScheduler::update", void, update, cocos2d::CCScheduler*, float)
}