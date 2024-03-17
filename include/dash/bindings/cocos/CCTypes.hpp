#pragma once

#include <cstdint>

using GLenum = unsigned int;
using GLubyte = unsigned char;
using GLfloat = float;

namespace gd::cocos2d {
    typedef struct _ccColor3B {
        GLubyte r;
        GLubyte g;
        GLubyte b;
    } ccColor3B;

    typedef struct _ccColor4F {
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
    } ccColor4F;

    typedef struct _ccBlendFunc
    {
        GLenum src;
        GLenum dst;
    } ccBlendFunc;
}