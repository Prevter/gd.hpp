// classes/cocos/CCShaderCache.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCShaderCache class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCGLProgram.hpp"

#define kCCShader_PositionTextureColor "ShaderPositionTextureColor"
#define kCCShader_PositionTextureColorAlphaTest "ShaderPositionTextureColorAlphaTest"
#define kCCShader_PositionColor "ShaderPositionColor"
#define kCCShader_PositionTexture "ShaderPositionTexture"
#define kCCShader_PositionTexture_uColor "ShaderPositionTexture_uColor"
#define kCCShader_PositionTextureA8Color "ShaderPositionTextureA8Color"
#define kCCShader_Position_uColor "ShaderPosition_uColor"
#define kCCShader_PositionLengthTexureColor "ShaderPositionLengthTextureColor"
#define kCCShader_ControlSwitch "Shader_ControlSwitch"

namespace gd::cocos2d
{
    class CCShaderCache
    {
    public:
        INIT_METHOD(cocos2d::CCShaderCache, sharedShaderCache, CCShaderCache *, CCShaderCache *(__stdcall *)());
        INIT_METHOD(cocos2d::CCShaderCache, programForKey, CCGLProgram *, CCGLProgram *(__fastcall *)(CCShaderCache *, int, const char *), CCShaderCache *, const char *);

    private:
        friend void init();
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

    inline gd::cocos2d::CCGLProgram *__fastcall CCShaderCache_programForKey(gd::cocos2d::CCShaderCache *self, int, const char *shader)
    {
        if (!gd::cocos2d::CCShaderCache::programForKey.isHooked())
            return gd::cocos2d::CCShaderCache::programForKey(self, shader);

        auto hook = gd::cocos2d::CCShaderCache::programForKey.getHook();
        return hook(self, shader);
    }
}
