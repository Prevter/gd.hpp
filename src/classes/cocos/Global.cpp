#include <classes/cocos/Global.hpp>

namespace gd::cocos2d
{
    INIT_GMETHOD_IMPL(cocos2d, ccGLBlendFunc, void, void(__fastcall *)(GLenum, GLenum), GLenum, GLenum);
    INIT_GMETHOD_IMPL(cocos2d, ccGLBindTexture2D, void, void(__fastcall *)(GLuint), GLuint);
}