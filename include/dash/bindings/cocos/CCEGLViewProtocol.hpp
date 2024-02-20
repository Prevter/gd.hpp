#pragma once
#include "CCGeometry.hpp"

enum {
    kCCVertexAttrib_Position,
    kCCVertexAttrib_Color,
    kCCVertexAttrib_TexCoords,

    kCCVertexAttrib_MAX,
};

namespace gd::cocos2d
{
    enum ResolutionPolicy
    {
        ExactFit,
        NoBorder,
        ShowAll,
        FixedHeight,
        FixedWidth,
        Unknown,
    };

    class EGLTouchDelegate;
    class CCSet;

    class CCEGLViewProtocol
    {
    public:
        virtual ~CCEGLViewProtocol();
        virtual void end() = 0;
        virtual bool isOpenGLReady() = 0;
        virtual void swapBuffers() = 0;
        virtual void setIMEKeyboardState(bool bOpen) = 0;
        virtual const CCSize &getFrameSize() const;
        virtual void setFrameSize(float width, float height);
        virtual CCSize getVisibleSize() const;
        virtual CCPoint getVisibleOrigin() const;
        virtual void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy);
        virtual const CCSize &getDesignResolutionSize() const;
        virtual void setTouchDelegate(EGLTouchDelegate *pDelegate);
        virtual void setViewPortInPoints(float x, float y, float w, float h);
        virtual void setScissorInPoints(float x, float y, float w, float h);
        virtual bool isScissorEnabled();
        virtual CCRect getScissorRect();
        virtual void setViewName(const char *pszViewName);
        virtual void handleTouchesBegin(int num, int ids[], float xs[], float ys[]);
        virtual void handleTouchesMove(int num, int ids[], float xs[], float ys[]);
        virtual void handleTouchesEnd(int num, int ids[], float xs[], float ys[]);
        virtual void handleTouchesCancel(int num, int ids[], float xs[], float ys[]);
    };
}