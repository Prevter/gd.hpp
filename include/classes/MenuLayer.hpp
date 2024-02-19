// classes/MenuLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for MenuLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "GameManager.hpp"

namespace gd
{
    class MenuLayer
    {
    public:
        inline static MenuLayer* get() {
            return GameManager::sharedState()->m_menuLayer();
        }

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
