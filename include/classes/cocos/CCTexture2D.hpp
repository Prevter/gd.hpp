// classes/cocos/CCTexture2D.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCTexture2D class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "CCGeometry.hpp"

typedef uint32_t GLuint;

namespace gd::cocos2d
{
    typedef enum
    {
        //! 32-bit texture: RGBA8888
        kCCTexture2DPixelFormat_RGBA8888,
        //! 24-bit texture: RGBA888
        kCCTexture2DPixelFormat_RGB888,
        //! 16-bit texture without Alpha channel
        kCCTexture2DPixelFormat_RGB565,
        //! 8-bit textures used as masks
        kCCTexture2DPixelFormat_A8,
        //! 8-bit intensity texture
        kCCTexture2DPixelFormat_I8,
        //! 16-bit textures used as masks
        kCCTexture2DPixelFormat_AI88,
        //! 16-bit textures: RGBA4444
        kCCTexture2DPixelFormat_RGBA4444,
        //! 16-bit textures: RGB5A1
        kCCTexture2DPixelFormat_RGB5A1,
        //! 4-bit PVRTC-compressed texture: PVRTC4
        kCCTexture2DPixelFormat_PVRTC4,
        //! 2-bit PVRTC-compressed texture: PVRTC2
        kCCTexture2DPixelFormat_PVRTC2,

        //! Default texture format: RGBA8888
        kCCTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_RGBA8888,

        // backward compatibility stuff
        kTexture2DPixelFormat_RGBA8888 = kCCTexture2DPixelFormat_RGBA8888,
        kTexture2DPixelFormat_RGB888 = kCCTexture2DPixelFormat_RGB888,
        kTexture2DPixelFormat_RGB565 = kCCTexture2DPixelFormat_RGB565,
        kTexture2DPixelFormat_A8 = kCCTexture2DPixelFormat_A8,
        kTexture2DPixelFormat_RGBA4444 = kCCTexture2DPixelFormat_RGBA4444,
        kTexture2DPixelFormat_RGB5A1 = kCCTexture2DPixelFormat_RGB5A1,
        kTexture2DPixelFormat_Default = kCCTexture2DPixelFormat_Default

    } CCTexture2DPixelFormat;

    class CCTexture2D
    {
    public:
        INIT_METHOD(cocos2d::CCTexture2D, constructor, CCTexture2D *, CCTexture2D *(__fastcall *)(CCTexture2D *), CCTexture2D *);
        INIT_METHOD(
            cocos2d::CCTexture2D, initWithData, bool,
            bool(__fastcall *)(CCTexture2D *, int, void *, CCTexture2DPixelFormat, uint32_t, uint32_t, const CCSize &),
            CCTexture2D *, void *, CCTexture2DPixelFormat, uint32_t, uint32_t, const CCSize &);

        inline static CCTexture2D *create()
        {
            // allocate memory for the object
            CCTexture2D *texture = reinterpret_cast<CCTexture2D *>(malloc(96));

            // call the constructor
            return constructor(texture);
        }

        INIT_MEMBER(GLuint, m_uName);
    };
}

namespace gd::hooks
{
    inline gd::cocos2d::CCTexture2D *__fastcall CCTexture2D_constructor(gd::cocos2d::CCTexture2D *self)
    {
        if (!gd::cocos2d::CCTexture2D::constructor.isHooked())
            return gd::cocos2d::CCTexture2D::constructor(self);

        auto hook = gd::cocos2d::CCTexture2D::constructor.getHook();
        return hook(self);
    }

    inline bool __fastcall CCTexture2D_initWithData(gd::cocos2d::CCTexture2D *self, int, void *data,
                                                    gd::cocos2d::CCTexture2DPixelFormat format,
                                                    uint32_t width, uint32_t height,
                                                    const gd::cocos2d::CCSize &size)
    {
        if (!gd::cocos2d::CCTexture2D::initWithData.isHooked())
            return gd::cocos2d::CCTexture2D::initWithData(self, data, format, width, height, size);

        auto hook = gd::cocos2d::CCTexture2D::initWithData.getHook();
        return hook(self, data, format, width, height, size);
    }
}