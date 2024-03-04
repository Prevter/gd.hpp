#pragma once

#include "../../internal.hpp"
#include "CCTypes.hpp"
#include "CCGeometry.hpp"

namespace gd::cocos2d {
    typedef enum
    {
        kCCTextAlignmentLeft,
        kCCTextAlignmentCenter,
        kCCTextAlignmentRight,
    } CCTextAlignment;

    class CCLabelBMFont : public CCNode {
    public:
        inline static CCLabelBMFont* create(const char* text, const char* fontFile) {
            SETUP_METHOD_SIG(CCLabelBMFont*, "cocos2d::CCLabelBMFont::create", __cdecl, const char*, const char*);
            return method(text, fontFile);
        }

        inline void setString(const char* text) {
            SETUP_METHOD_SIG(void, "cocos2d::CCLabelBMFont::setCString", __thiscall, CCLabelBMFont*, const char*);
            return method(this, text);
        }

        inline void setString(const std::string& text) {
            this->setString(text.c_str());
        }

        inline void setAlignment(cocos2d::CCTextAlignment alignment) {
            SETUP_METHOD_SIG(void, "cocos2d::CCLabelBMFont::setAlignment", __thiscall, CCLabelBMFont*, cocos2d::CCTextAlignment);
            return method(this, alignment);
        }

        inline void setScale(float scale) {
            SETUP_METHOD_SIG(void, "cocos2d::CCLabelBMFont::setScale", __thiscall, CCLabelBMFont*, float);
            return method(this, scale);
        }

        inline void setAnchorPoint(const cocos2d::CCPoint& anchor) {
            SETUP_METHOD_SIG(void, "cocos2d::CCLabelBMFont::setAnchorPoint", __thiscall, CCLabelBMFont*, const cocos2d::CCPoint&);
            return method(this, anchor);
        }
    };
}