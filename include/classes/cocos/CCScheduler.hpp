// classes/cocos/CCScheduler.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCScheduler class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

namespace gd::cocos2d
{
    class CCScheduler
    {
    public:
        INIT_METHOD(cocos2d::CCScheduler, update, void, void(__fastcall*)(CCScheduler*, int, float), CCScheduler*, float);
    };
}

namespace gd::hooks
{
    inline void __fastcall CCScheduler_update(gd::cocos2d::CCScheduler* self, int, float dt)
    {
        if (!gd::cocos2d::CCScheduler::update.isHooked())
            return gd::cocos2d::CCScheduler::update(self, dt);

        auto hook = gd::cocos2d::CCScheduler::update.getHook();
        return hook(self, dt);
    }
}
