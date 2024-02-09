// classes/cocos/CCShaderCache.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCShaderCache class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

#ifndef INIT_METHOD
#error INIT_METHOD is not defined
#endif

namespace gd::cocos2d
{
    class CCEGLProgram
    {
    public:
        INIT_METHOD(cocos2d::CCEGLProgram, use, void, void(__fastcall *)(CCEGLProgram*), CCEGLProgram*);
        INIT_METHOD(cocos2d::CCEGLProgram, setUniformsForBuiltins, void, void(__fastcall *)(CCEGLProgram*), CCEGLProgram*);
    };
}

namespace gd::hooks
{
    inline void __fastcall CCEGLProgram_use(gd::cocos2d::CCEGLProgram* self)
    {
        if (!gd::cocos2d::CCEGLProgram::use.isHooked())
            return gd::cocos2d::CCEGLProgram::use(self);

        auto hook = gd::cocos2d::CCEGLProgram::use.getHook();
        return hook(self);
    }

    inline void __fastcall CCEGLProgram_setUniformsForBuiltins(gd::cocos2d::CCEGLProgram* self)
    {
        if (!gd::cocos2d::CCEGLProgram::setUniformsForBuiltins.isHooked())
            return gd::cocos2d::CCEGLProgram::setUniformsForBuiltins(self);

        auto hook = gd::cocos2d::CCEGLProgram::setUniformsForBuiltins.getHook();
        return hook(self);
    }
}
