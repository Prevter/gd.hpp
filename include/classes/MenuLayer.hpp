// layers/MenuLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for MenuLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/method.hpp"

namespace gd
{
    class MenuLayer
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(MenuLayer *), MenuLayer *> init;
    };
}

namespace gd::hooks
{
    bool __fastcall MenuLayer_init(MenuLayer *self)
    {
        if (!MenuLayer::init.isHooked())
            return MenuLayer::init(self);

        auto hook = MenuLayer::init.getHook();
        return hook(self);
    }
}
