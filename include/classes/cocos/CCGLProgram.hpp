// classes/cocos/CCGLProgram.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCGLProgram class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"

namespace gd::cocos2d
{
    class CCGLProgram
    {
    public:
        INIT_METHOD(cocos2d::CCGLProgram, use, void, void(__fastcall *)(CCGLProgram*), CCGLProgram*);
        INIT_METHOD(cocos2d::CCGLProgram, setUniformsForBuiltins, void, void(__fastcall *)(CCGLProgram*), CCGLProgram*);
    };
}

namespace gd::hooks
{
    inline void __fastcall CCGLProgram_use(gd::cocos2d::CCGLProgram* self)
    {
        if (!gd::cocos2d::CCGLProgram::use.isHooked())
            return gd::cocos2d::CCGLProgram::use(self);

        auto hook = gd::cocos2d::CCGLProgram::use.getHook();
        return hook(self);
    }

    inline void __fastcall CCGLProgram_setUniformsForBuiltins(gd::cocos2d::CCGLProgram* self)
    {
        if (!gd::cocos2d::CCGLProgram::setUniformsForBuiltins.isHooked())
            return gd::cocos2d::CCGLProgram::setUniformsForBuiltins(self);

        auto hook = gd::cocos2d::CCGLProgram::setUniformsForBuiltins.getHook();
        return hook(self);
    }
}
