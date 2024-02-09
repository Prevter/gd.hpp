// classes/MenuLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for MenuLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class MenuLayer
    {
    public:
        INIT_METHOD(MenuLayer, init, bool, bool(__fastcall *)(MenuLayer *), MenuLayer *);
    };
}

namespace gd::hooks
{
    inline bool __fastcall MenuLayer_init(MenuLayer *self)
    {
        if (!MenuLayer::init.isHooked())
            return MenuLayer::init(self);

        auto hook = MenuLayer::init.getHook();
        return hook(self);
    }
}
