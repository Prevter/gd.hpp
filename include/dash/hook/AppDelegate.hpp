#pragma once

#include "hook.hpp"
#include "../bindings/AppDelegate.hpp"

namespace gd::hook::AppDelegate {

    // AppDelegate::applicationWillEnterForeground

    inline static uintptr_t applicationWillEnterForeground_addr = 0x0;
    inline static std::function<void(gd::AppDelegate *)> applicationWillEnterForeground_hook;

    /// @brief Calls the original CCEGLView::swapBuffers function.
    inline static void applicationWillEnterForeground(gd::AppDelegate *self) {
        return reinterpret_cast<void (__thiscall *)(gd::AppDelegate *)>(applicationWillEnterForeground_addr)(self);
    }

    /// @brief Wrapper for the CCEGLView::swapBuffers hook.
    inline void __fastcall applicationWillEnterForegroundHook(gd::AppDelegate *self) { applicationWillEnterForeground_hook(self); }

    /// @brief Installs the hook for CCEGLView::swapBuffers.
    SETUP_HOOK("AppDelegate::applicationWillEnterForeground", void, applicationWillEnterForeground, gd::AppDelegate *)
}