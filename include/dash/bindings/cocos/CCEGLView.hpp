#pragma once

#include "CCEGLViewProtocol.hpp"
#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCEGLView : public CCEGLViewProtocol {
    public:
        inline void pollEvents() {
            SETUP_METHOD_SIG(void, "cocos2d::CCEGLView::pollEvents", __thiscall, CCEGLView*);
            return method(this);
        }

        inline void swapBuffers() {
            SETUP_METHOD_SIG(void, "cocos2d::CCEGLView::swapBuffers", __thiscall, CCEGLView*);
            return method(this);
        }

        inline void toggleFullScreen(bool fullscreen, bool borderless) {
            SETUP_METHOD_SIG(void, "cocos2d::CCEGLView::toggleFullScreen", __thiscall, CCEGLView*, bool, bool);
            return method(this, fullscreen, borderless);
        }

        inline void *getWindow() {
            SETUP_METHOD_SIG(void*, "cocos2d::CCEGLView::getWindow", __thiscall, CCEGLView*);
            return method(this);
        }

        inline static CCEGLView *sharedOpenGLView() {
            SETUP_METHOD_SIG(CCEGLView*, "cocos2d::CCEGLView::sharedOpenGLView", __cdecl);
            return method();
        }

        inline void showCursor(bool show) {
            SETUP_METHOD_SIG(void, "cocos2d::CCEGLView::showCursor", __thiscall, CCEGLView*, bool);
            return method(this, show);
        }

        SETUP_MEMBER(float, m_mouseX, "cocos2d::CCEGLView::m_mouseX");

        SETUP_MEMBER(float, m_mouseY, "cocos2d::CCEGLView::m_mouseY");

        inline CCPoint getMousePosition() {
            return {m_mouseX(), m_mouseY()};
        }

    };
}