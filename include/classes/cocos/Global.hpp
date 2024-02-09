// classes/cocos/Global.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for methods in the cocos2d namespace.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

typedef unsigned int GLenum;
typedef unsigned int GLuint;

namespace gd::cocos2d
{
    INIT_GMETHOD(ccGLBlendFunc, void, void(__fastcall *)(GLenum, GLenum), GLenum, GLenum);
    INIT_GMETHOD(ccGLBindTexture2D, void, void(__fastcall *)(GLuint), GLuint);
}

namespace gd::hooks
{
    inline void __fastcall ccGLBlendFunc(GLenum sfactor, GLenum dfactor)
    {
        if (!gd::cocos2d::ccGLBlendFunc.isHooked())
            return gd::cocos2d::ccGLBlendFunc(sfactor, dfactor);

        auto hook = gd::cocos2d::ccGLBlendFunc.getHook();
        return hook(sfactor, dfactor);
    }

    inline void __fastcall ccGLBindTexture2D(GLuint texture)
    {
        if (!gd::cocos2d::ccGLBindTexture2D.isHooked())
            return gd::cocos2d::ccGLBindTexture2D(texture);

        auto hook = gd::cocos2d::ccGLBindTexture2D.getHook();
        return hook(texture);
    }
}