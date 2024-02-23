#pragma once

#include <cstdint>

using GLenum = unsigned int;
using GLubyte = unsigned char;

namespace gd::cocos2d {
    typedef struct _ccColor3B {
        GLubyte r;
        GLubyte g;
        GLubyte b;
    } ccColor3B;

    typedef struct _ccBlendFunc
    {
        GLenum src;
        GLenum dst;
    } ccBlendFunc;
}