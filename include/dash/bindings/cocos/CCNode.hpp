#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCNode {
    public:
        inline void addChild(CCNode *child) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::addChild", __thiscall, CCNode*, CCNode*);
            return method(this, child);
        }

        inline void setZOrder(int z) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::setZOrder", __thiscall, CCNode*, int);
            return method(this, z);
        }
    };
}