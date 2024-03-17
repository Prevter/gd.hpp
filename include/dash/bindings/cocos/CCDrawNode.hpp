#pragma once

#include "../../internal.hpp"
#include "CCNode.hpp"
#include "CCTypes.hpp"

namespace gd::cocos2d {
    class CCDrawNode : public CCNode {
    public:
        inline void clear() {
            SETUP_METHOD_SIG(void, "cocos2d::CCDrawNode::clear", __thiscall, CCDrawNode*);
            return method(this);
        }

        inline void drawPolygon(CCPoint *vertex, unsigned int count, const _ccColor4F &fillColor, float borderWidth, const ccColor4F &borderColor) {
            SETUP_METHOD_SIG(void, "cocos2d::CCDrawNode::drawPolygon", __thiscall, CCDrawNode*, CCPoint*, unsigned int, const _ccColor4F&, float, const ccColor4F&);
            return method(this, vertex, count, fillColor, borderWidth, borderColor);
        }

    };

}