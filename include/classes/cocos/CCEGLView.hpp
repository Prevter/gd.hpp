// classes/cocos/CCEGLView.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCEGLView class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

namespace gd::cocos2d
{
    class CCEGLView : public gd::BindableClassBase
    {
    public:
        inline static gd::utils::BindableMethod<void, void(__fastcall *)(CCEGLView *), CCEGLView *> swapBuffers;
        inline static gd::utils::BindableMethod<void, void(__fastcall *)(CCEGLView *), CCEGLView *> pollEvents;
    };
}

namespace gd::hooks
{
    inline void __fastcall CCEGLView_swapBuffers(cocos2d::CCEGLView *self)
    {
        if (!gd::cocos2d::CCEGLView::swapBuffers.isHooked())
            return gd::cocos2d::CCEGLView::swapBuffers(self);

        auto hook = gd::cocos2d::CCEGLView::swapBuffers.getHook();
        return hook(self);
    }

    inline void __fastcall CCEGLView_pollEvents(gd::cocos2d::CCEGLView *self)
    {
        if (!gd::cocos2d::CCEGLView::pollEvents.isHooked())
            return gd::cocos2d::CCEGLView::pollEvents(self);

        auto hook = gd::cocos2d::CCEGLView::pollEvents.getHook();
        return hook(self);
    }
}
