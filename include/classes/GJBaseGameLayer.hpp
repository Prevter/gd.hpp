// classes/GJBaseGameLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GJBaseGameLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class GJBaseGameLayer
    {
    public:
        INIT_METHOD(GJBaseGameLayer, init, bool, bool(__fastcall *)(GJBaseGameLayer *), GJBaseGameLayer *);
        INIT_METHOD(GJBaseGameLayer, handleButton, void, void(__fastcall *)(GJBaseGameLayer *, int, bool, int, bool), GJBaseGameLayer *, bool, int, bool);
    };
}

namespace gd::hooks
{
    inline bool __fastcall GJBaseGameLayer_init(GJBaseGameLayer *self)
    {
        if (!GJBaseGameLayer::init.isHooked())
            return GJBaseGameLayer::init(self);

        auto hook = GJBaseGameLayer::init.getHook();
        return hook(self);
    }

    inline void __fastcall GJBaseGameLayer_handleButton(GJBaseGameLayer *self, int, bool v1, int v2, bool v3)
    {
        if (!GJBaseGameLayer::handleButton.isHooked())
            return GJBaseGameLayer::handleButton(self, v1, v2, v3);

        auto hook = GJBaseGameLayer::handleButton.getHook();
        return hook(self, v1, v2, v3);
    }
}
