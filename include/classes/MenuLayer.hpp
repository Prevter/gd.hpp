// classes/MenuLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for MenuLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class MenuLayer : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(MenuLayer *), MenuLayer *> init;
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
