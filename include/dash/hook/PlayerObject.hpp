#pragma once

#include "hook.hpp"
#include "../bindings/PlayerObject.hpp"

namespace gd::hook::PlayerObject {

    // PlayerObject::pushButton

    inline static uintptr_t pushButton_addr = 0x0;
    inline static std::function<void(gd::PlayerObject*, gd::PlayerButton)> pushButton_hook;

    /// @brief Calls the original PlayerObject::pushButton function.
    inline static void pushButton(gd::PlayerObject* self, gd::PlayerButton btn) {
        reinterpret_cast<void (__thiscall *)(gd::PlayerObject*, gd::PlayerButton)>(pushButton_addr)(self, btn);
    }

    /// @brief Wrapper for the PlayerObject::pushButton hook.
    inline void __fastcall pushButtonHook(gd::PlayerObject* self, int, gd::PlayerButton btn) { pushButton_hook(self, btn); }

    /// @brief Installs the hook for PlayerObject::pushButton.
    SETUP_HOOK("PlayerObject::pushButton", void, pushButton, gd::PlayerObject*, gd::PlayerButton)

    // PlayerObject::releaseButton

    inline static uintptr_t releaseButton_addr = 0x0;
    inline static std::function<void(gd::PlayerObject*, gd::PlayerButton)> releaseButton_hook;

    /// @brief Calls the original PlayerObject::releaseButton function.
    inline static void releaseButton(gd::PlayerObject* self, gd::PlayerButton btn) {
        reinterpret_cast<void (__thiscall *)(gd::PlayerObject*, gd::PlayerButton)>(releaseButton_addr)(self, btn);
    }

    /// @brief Wrapper for the PlayerObject::releaseButton hook.
    inline void __fastcall releaseButtonHook(gd::PlayerObject* self, int, gd::PlayerButton btn) { releaseButton_hook(self, btn); }

    /// @brief Installs the hook for PlayerObject::releaseButton.
    SETUP_HOOK("PlayerObject::releaseButton", void, releaseButton, gd::PlayerObject*, gd::PlayerButton)

}