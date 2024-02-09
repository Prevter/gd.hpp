// classes/AppDelegate.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for AppDelegate class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class AppDelegate : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<void, void(__fastcall *)(AppDelegate *), AppDelegate *> applicationWillEnterForeground;
        inline static utils::BindableMethod<bool, bool(__fastcall *)(AppDelegate *), AppDelegate *> applicationDidFinishLaunching;
        inline static utils::BindableMethod<void, void(__fastcall *)(AppDelegate *), AppDelegate *> applicationDidEnterBackground;
        inline static utils::BindableMethod<void, void(__fastcall *)(AppDelegate *), AppDelegate *> applicationWillBecomeActive;
        inline static utils::BindableMethod<void, void(__fastcall *)(AppDelegate *), AppDelegate *> applicationWillResignActive;
        inline static utils::BindableMethod<void, void(__fastcall *)(AppDelegate *, int, bool), AppDelegate *, bool> trySaveGame;
    };
}

namespace gd::hooks
{
    inline void __fastcall AppDelegate_applicationWillEnterForeground(AppDelegate *self)
    {
        if (!AppDelegate::applicationWillEnterForeground.isHooked())
            return AppDelegate::applicationWillEnterForeground(self);

        auto hook = AppDelegate::applicationWillEnterForeground.getHook();
        return hook(self);
    }

    inline bool __fastcall AppDelegate_applicationWillDidFinishLaunching(AppDelegate *self)
    {
        if (!AppDelegate::applicationDidFinishLaunching.isHooked())
            return AppDelegate::applicationDidFinishLaunching(self);

        auto hook = AppDelegate::applicationDidFinishLaunching.getHook();
        return hook(self);
    }

    inline void __fastcall AppDelegate_applicationDidEnterBackground(AppDelegate *self)
    {
        if (!AppDelegate::applicationDidEnterBackground.isHooked())
            return AppDelegate::applicationDidEnterBackground(self);

        auto hook = AppDelegate::applicationDidEnterBackground.getHook();
        return hook(self);
    }

    inline void __fastcall AppDelegate_applicationWillBecomeActive(AppDelegate *self)
    {
        if (!AppDelegate::applicationWillBecomeActive.isHooked())
            return AppDelegate::applicationWillBecomeActive(self);

        auto hook = AppDelegate::applicationWillBecomeActive.getHook();
        return hook(self);
    }

    inline void __fastcall AppDelegate_applicationWillResignActive(AppDelegate *self)
    {
        if (!AppDelegate::applicationWillResignActive.isHooked())
            return AppDelegate::applicationWillResignActive(self);

        auto hook = AppDelegate::applicationWillResignActive.getHook();
        return hook(self);
    }

    inline void __fastcall AppDelegate_trySaveGame(AppDelegate *self, int, bool save)
    {
        if (!AppDelegate::trySaveGame.isHooked())
            return AppDelegate::trySaveGame(self, save);

        auto hook = AppDelegate::trySaveGame.getHook();
        return hook(self, save);
    }
}
