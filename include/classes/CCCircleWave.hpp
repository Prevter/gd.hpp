// classes/CCCircleWave.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for CCCircleWave class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class CCCircleWave
    {
    public:
        INIT_METHOD(CCCircleWave, init, bool, bool(__fastcall *)(CCCircleWave *, int, float, float, float, bool, bool), CCCircleWave *, float, float, float, bool, bool);
        INIT_METHOD(CCCircleWave, draw, void, void(__fastcall *)(CCCircleWave *), CCCircleWave *);
    };
}

namespace gd::hooks
{
    inline bool __fastcall CCCircleWave_init(CCCircleWave *self, int, float v1, float v2, float v3, bool v4, bool v5)
    {
        if (!CCCircleWave::init.isHooked())
            return CCCircleWave::init(self, v1, v2, v3, v4, v5);

        auto hook = CCCircleWave::init.getHook();
        return hook(self, v1, v2, v3, v4, v5);
    }

    inline void __fastcall CCCircleWave_draw(CCCircleWave *self)
    {
        if (!CCCircleWave::draw.isHooked())
            return CCCircleWave::draw(self);

        auto hook = CCCircleWave::draw.getHook();
        return hook(self);
    }
}
