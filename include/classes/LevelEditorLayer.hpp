// classes/LevelEditorLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for LevelEditorLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class GJGameLevel;

    class LevelEditorLayer : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(LevelEditorLayer *, int, GJGameLevel *, bool), LevelEditorLayer *, GJGameLevel *, bool> init;
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
