// classes/cocos/CCShaderCache.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCShaderCache class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCEGLProgram.hpp"

#define kCCShader_PositionTextureColor "ShaderPositionTextureColor"
#define kCCShader_PositionTextureColorAlphaTest "ShaderPositionTextureColorAlphaTest"
#define kCCShader_PositionColor "ShaderPositionColor"
#define kCCShader_PositionTexture "ShaderPositionTexture"
#define kCCShader_PositionTexture_uColor "ShaderPositionTexture_uColor"
#define kCCShader_PositionTextureA8Color "ShaderPositionTextureA8Color"
#define kCCShader_Position_uColor "ShaderPosition_uColor"
#define kCCShader_PositionLengthTexureColor "ShaderPositionLengthTextureColor"
#define kCCShader_ControlSwitch "Shader_ControlSwitch"

#ifndef INIT_METHOD
#error INIT_METHOD is not defined
#endif

namespace gd::cocos2d
{
    class CCShaderCache
    {
    public:
        INIT_METHOD(cocos2d::CCShaderCache, sharedShaderCache, CCShaderCache *, void(__stdcall *)());
        INIT_METHOD(cocos2d::CCShaderCache, programForKey, CCEGLProgram *, void(__thiscall *)(CCShaderCache *, int, const char *), CCShaderCache *, const char *);
    };
}

namespace gd::hooks
{
    inline gd::cocos2d::CCShaderCache *__stdcall CCShaderCache_sharedShaderCache()
    {
        if (!gd::cocos2d::CCShaderCache::sharedShaderCache.isHooked())
            return gd::cocos2d::CCShaderCache::sharedShaderCache();

        auto hook = gd::cocos2d::CCShaderCache::sharedShaderCache.getHook();
        return hook();
    }

    inline gd::cocos2d::CCEGLProgram *__fastcall CCShaderCache_programForKey(gd::cocos2d::CCShaderCache *self, int, const char *shader)
    {
        if (!gd::cocos2d::CCShaderCache::programForKey.isHooked())
            return gd::cocos2d::CCShaderCache::programForKey(self, shader);

        auto hook = gd::cocos2d::CCShaderCache::programForKey.getHook();
        return hook(self, shader);
    }
}
