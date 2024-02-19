// classes/LevelEditorLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for LevelEditorLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "GameManager.hpp"

namespace gd
{
    class GJGameLevel;

    class LevelEditorLayer
    {
    public:
        inline static LevelEditorLayer* get() {
            return GameManager::sharedState()->m_levelEditorLayer();
        }

        INIT_METHOD(LevelEditorLayer, init, bool, bool(__fastcall *)(LevelEditorLayer *, int, GJGameLevel *, bool), LevelEditorLayer *, GJGameLevel *, bool);
    };
}

namespace gd::hooks
{
    inline bool __fastcall LevelEditorLayer_init(LevelEditorLayer *self, int, GJGameLevel *level, bool v1)
    {
        if (!LevelEditorLayer::init.isHooked())
            return LevelEditorLayer::init(self, level, v1);

        auto hook = LevelEditorLayer::init.getHook();
        return hook(self, level, v1);
    }
}
