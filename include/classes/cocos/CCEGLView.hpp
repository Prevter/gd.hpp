// classes/cocos/CCEGLView.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCEGLView class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCEGLViewProtocol.hpp"

#ifndef INIT_METHOD
#error INIT_METHOD is not defined
#endif

namespace gd::cocos2d
{
    class CCEGLView : public CCEGLViewProtocol
    {
    public:
        INIT_METHOD(cocos2d::CCEGLView, pollEvents, void, void(__fastcall *)(CCEGLView *), CCEGLView *);
        INIT_METHOD(cocos2d::CCEGLView, swapBuffers, void, void(__fastcall *)(CCEGLView *), CCEGLView *);
        INIT_METHOD(cocos2d::CCEGLView, toggleFullScreen, void, void(__fastcall *)(CCEGLView *, int, bool, bool), CCEGLView *, bool, bool);

        INIT_MEMBER(float, m_fMouseX);
        INIT_MEMBER(float, m_fMouseY);

        inline CCPoint getMousePosition() { return {m_fMouseX(), m_fMouseY()}; }
    };
}

namespace gd::hooks
{
    inline void __fastcall CCEGLView_pollEvents(gd::cocos2d::CCEGLView *self)
    {
        if (!gd::cocos2d::CCEGLView::pollEvents.isHooked())
            return gd::cocos2d::CCEGLView::pollEvents(self);

        auto hook = gd::cocos2d::CCEGLView::pollEvents.getHook();
        return hook(self);
    }

    inline void __fastcall CCEGLView_swapBuffers(cocos2d::CCEGLView *self)
    {
        if (!gd::cocos2d::CCEGLView::swapBuffers.isHooked())
            return gd::cocos2d::CCEGLView::swapBuffers(self);

        auto hook = gd::cocos2d::CCEGLView::swapBuffers.getHook();
        return hook(self);
    }

    inline void __fastcall CCEGLView_toggleFullScreen_old(cocos2d::CCEGLView *self, int, bool fullscreen)
    {
        if (!gd::cocos2d::CCEGLView::toggleFullScreen.isHooked())
            return gd::cocos2d::CCEGLView::toggleFullScreen(self, fullscreen, false);

        auto hook = gd::cocos2d::CCEGLView::toggleFullScreen.getHook();
        return hook(self, fullscreen, false);
    }

    inline void __fastcall CCEGLView_toggleFullScreen(cocos2d::CCEGLView *self, int, bool fullscreen, bool borderless)
    {
        if (!gd::cocos2d::CCEGLView::toggleFullScreen.isHooked())
            return gd::cocos2d::CCEGLView::toggleFullScreen(self, fullscreen, borderless);

        auto hook = gd::cocos2d::CCEGLView::toggleFullScreen.getHook();
        return hook(self, fullscreen, borderless);
    }
}
