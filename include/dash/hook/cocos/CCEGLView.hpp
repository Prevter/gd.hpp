#pragma once

#include "../hook.hpp"
#include "../../bindings/cocos/CCEGLView.hpp"

namespace gd::hook::CCEGLView {

    // CCEGLView::swapBuffers

    inline static uintptr_t swapBuffers_addr = 0x0;
    inline static std::function<void(cocos2d::CCEGLView *)> swapBuffers_hook;

    /// @brief Calls the original CCEGLView::swapBuffers function.
    inline static void swapBuffers(cocos2d::CCEGLView *self) {
        return reinterpret_cast<void (__thiscall *)(cocos2d::CCEGLView *)>(swapBuffers_addr)(self);
    }

    /// @brief Wrapper for the CCEGLView::swapBuffers hook.
    inline void __fastcall swapBuffersHook(cocos2d::CCEGLView *self) { swapBuffers_hook(self); }

    /// @brief Installs the hook for CCEGLView::swapBuffers.
    SETUP_HOOK_SIG("cocos2d::CCEGLView::swapBuffers", void, swapBuffers, cocos2d::CCEGLView *)

    // CCEGLView::pollEvents

    inline static uintptr_t pollEvents_addr = 0x0;
    inline static std::function<void(cocos2d::CCEGLView *)> pollEvents_hook;

    /// @brief Calls the original CCEGLView::pollEvents function.
    inline static void pollEvents(cocos2d::CCEGLView *self) {
        return reinterpret_cast<void (__thiscall *)(cocos2d::CCEGLView *)>(pollEvents_addr)(self);
    }

    /// @brief Wrapper for the CCEGLView::pollEvents hook.
    inline void __fastcall pollEventsHook(cocos2d::CCEGLView *self) { pollEvents_hook(self); }

    /// @brief Installs the hook for CCEGLView::pollEvents.
    SETUP_HOOK_SIG("cocos2d::CCEGLView::pollEvents", void, pollEvents, cocos2d::CCEGLView *)

    // CCEGLView::toggleFullScreen

    inline static uintptr_t toggleFullScreen_addr = 0x0;
    inline static std::function<void(cocos2d::CCEGLView *, bool, bool)> toggleFullScreen_hook;

    /// @brief Calls the original CCEGLView::toggleFullScreen function.
    inline static void toggleFullScreen(cocos2d::CCEGLView *self, bool fullscreen, bool borderless) {
        const auto &version = ::gd::getVersion();
        if (Version("2.204") <= version) {
            return reinterpret_cast<void (__thiscall *)(cocos2d::CCEGLView *, bool, bool)>(toggleFullScreen_addr)(self,
                                                                                                                  fullscreen,
                                                                                                                  borderless);
        }
        return reinterpret_cast<void (__thiscall *)(cocos2d::CCEGLView *, bool)>(toggleFullScreen_addr)(self,
                                                                                                        fullscreen);
    }

    /// @brief Wrapper for the CCEGLView::toggleFullScreen hook.
    inline void __fastcall toggleFullScreenHook(cocos2d::CCEGLView *self, int, bool fullscreen, bool borderless) {
        toggleFullScreen_hook(self, fullscreen, borderless);
    }

    /// @brief Wrapper for the CCEGLView::toggleFullScreen hook (pre-2.204).
    inline void __fastcall toggleFullScreenHook_old(cocos2d::CCEGLView *self, int, bool fullscreen) {
        toggleFullScreen_hook(self, fullscreen, false);
    }

    /// @brief Installs the hook for CCEGLView::toggleFullScreen.
    inline static HookResult toggleFullScreen(const std::function<void(cocos2d::CCEGLView *, bool, bool)> &hook,
                                              const std::function<void(void *, void *, void **)> &createHook) {
        auto address = findSignature("cocos2d::CCEGLView::toggleFullScreen");
        if (!address) return {nullptr, Status::ADDRESS_NULL};
        toggleFullScreen_hook = hook;
        auto hookPtr = Version("2.204") <= ::gd::getVersion() ? reinterpret_cast<void *>(&toggleFullScreenHook)
                                                              : reinterpret_cast<void *>(&toggleFullScreenHook_old);
        createHook(reinterpret_cast<void *>(address), hookPtr,
                   reinterpret_cast<void **>(&toggleFullScreen_addr));
        return {reinterpret_cast<void *>(toggleFullScreen_addr), Status::OK};
    }
}