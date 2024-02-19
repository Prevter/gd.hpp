// classes/cocos/CCApplication.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCApplication class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

namespace gd::cocos2d
{
    class CCApplication
    {
    public:
        INIT_METHOD(cocos2d::CCApplication, sharedApplication, CCApplication*, CCApplication*(__cdecl*)());
        INIT_METHOD(cocos2d::CCApplication, toggleVerticalSync, void, void(__fastcall*)(CCApplication*, int, bool), CCApplication*, bool);
    };
}

namespace gd::hooks
{
    inline gd::cocos2d::CCApplication* __cdecl CCApplication_sharedApplication()
    {
        if (!gd::cocos2d::CCApplication::sharedApplication.isHooked())
            return gd::cocos2d::CCApplication::sharedApplication();

        auto hook = gd::cocos2d::CCApplication::sharedApplication.getHook();
        return hook();
    }

    inline void __fastcall CCApplication_toggleVerticalSync(gd::cocos2d::CCApplication* self, int, bool verticalSync)
    {
        if (!gd::cocos2d::CCApplication::toggleVerticalSync.isHooked())
            return gd::cocos2d::CCApplication::toggleVerticalSync(self, verticalSync);

        auto hook = gd::cocos2d::CCApplication::toggleVerticalSync.getHook();
        hook(self, verticalSync);
    }
}