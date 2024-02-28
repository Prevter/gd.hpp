#pragma once

#include "../../internal.hpp"
#include "CCGeometry.hpp"
#include "CCScene.hpp"

namespace gd::cocos2d {
    class CCEGLView;

    class CCDirector {
    public:
        inline static CCDirector* sharedDirector() {
            SETUP_METHOD_SIG(CCDirector*, "cocos2d::CCDirector::sharedDirector", __stdcall);
            return method();
        }

        inline CCSize getWinSize() {
            CCSize size;
            SETUP_METHOD_SIG(CCSize*, "cocos2d::CCDirector::getWinSize", __thiscall, CCDirector*, CCSize*);
            method(this, &size);
            return size;
        }

        inline CCEGLView* getOpenGLView() {
            SETUP_METHOD_SIG(CCEGLView*, "cocos2d::CCDirector::getOpenGLView", __thiscall, CCDirector*);
            return method(this);
        }

        inline float getDeltaTime() {
            SETUP_METHOD_SIG(float, "cocos2d::CCDirector::getDeltaTime", __thiscall, CCDirector*);
            return method(this);
        }

        inline CCScene* getRunningScene() { return m_runningScene(); }
        SETUP_MEMBER(CCScene*, m_runningScene, "cocos2d::CCDirector::m_runningScene")
    };
}