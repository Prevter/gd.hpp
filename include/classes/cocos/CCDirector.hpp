// classes/cocos/ССDirector.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::ССDirector class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCGeometry.hpp"
#include "CCEGLView.hpp"

namespace gd::cocos2d
{
    class CCDirector
    {
    public:
        INIT_METHOD(cocos2d::CCDirector, sharedDirector, CCDirector*, CCDirector*(__stdcall*)());
        INIT_METHOD(cocos2d::CCDirector, getWinSize, CCSize*, CCSize*( __fastcall*)(CCDirector*, int, CCSize*), CCDirector*, CCSize*);
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
    
    inline gd::cocos2d::CCSize* __fastcall CCDirector_getWinSize(gd::cocos2d::CCDirector* self, int, gd::cocos2d::CCSize* size)
    {
        if (!gd::cocos2d::CCDirector::getWinSize.isHooked())
            return gd::cocos2d::CCDirector::getWinSize(self, size);

        auto hook = gd::cocos2d::CCDirector::getWinSize.getHook();
        return hook(self, size);
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
