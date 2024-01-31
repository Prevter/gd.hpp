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
}
