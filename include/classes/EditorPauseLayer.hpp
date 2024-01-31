// classes/EditorPauseLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for EditorPauseLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    namespace cocos2d
    {
        class CCObject;
    }

    class EditorPauseLayer : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(EditorPauseLayer *, int, cocos2d::CCObject*), EditorPauseLayer *, cocos2d::CCObject*> onExitEditor;
    };
}

namespace gd::hooks
{
    inline bool __fastcall EditorPauseLayer_onExitEditor(EditorPauseLayer *self, int, cocos2d::CCObject *sender)
    {
        if (!EditorPauseLayer::onExitEditor.isHooked())
            return EditorPauseLayer::onExitEditor(self, sender);

        auto hook = EditorPauseLayer::onExitEditor.getHook();
        return hook(self, sender);
    }
}
