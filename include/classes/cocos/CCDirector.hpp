// classes/cocos/ССDirector.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::ССDirector class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCGeometry.hpp"
#include "CCEGLView.hpp"

#ifndef INIT_METHOD
#error INIT_METHOD is not defined
#endif

namespace gd::cocos2d
{
    class CCDirector
    {
    public:
        INIT_METHOD(cocos2d::CCDirector, sharedDirector, CCDirector*, CCDirector*(__stdcall*)());
        INIT_METHOD(cocos2d::CCDirector, getWinSize, int, int( __fastcall*)(CCDirector*, int, int), CCDirector*, int);
        INIT_METHOD(cocos2d::CCDirector, getOpenGLView, CCEGLView*, CCEGLView*( __fastcall*)(CCDirector*), CCDirector*);
        INIT_METHOD(cocos2d::CCDirector, getDeltaTime, float, float( __fastcall*)(CCDirector*), CCDirector*);
    };
}

namespace gd::hooks
{
    inline gd::cocos2d::CCDirector* __stdcall CCDirector_sharedDirector()
    {
        if (!gd::cocos2d::CCDirector::sharedDirector.isHooked())
            return gd::cocos2d::CCDirector::sharedDirector();

        auto hook = gd::cocos2d::CCDirector::sharedDirector.getHook();
        return hook();
    }
    
    inline int __fastcall CCDirector_getWinSize(gd::cocos2d::CCDirector* self, int, int a)
    {
        if (!gd::cocos2d::CCDirector::getWinSize.isHooked())
            return gd::cocos2d::CCDirector::getWinSize(self, a);

        auto hook = gd::cocos2d::CCDirector::getWinSize.getHook();
        return hook(self, a);
    }

    inline gd::cocos2d::CCEGLView* __fastcall CCDirector_getOpenGLView(gd::cocos2d::CCDirector* self)
    {
        if (!gd::cocos2d::CCDirector::getOpenGLView.isHooked())
            return gd::cocos2d::CCDirector::getOpenGLView(self);

        auto hook = gd::cocos2d::CCDirector::getOpenGLView.getHook();
        return hook(self);
    }

    inline float __fastcall CCDirector_getDeltaTime(gd::cocos2d::CCDirector* self)
    {
        if (!gd::cocos2d::CCDirector::getDeltaTime.isHooked())
            return gd::cocos2d::CCDirector::getDeltaTime(self);

        auto hook = gd::cocos2d::CCDirector::getDeltaTime.getHook();
        return hook(self);
    }
}
