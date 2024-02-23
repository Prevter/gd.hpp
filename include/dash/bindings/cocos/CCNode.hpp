#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCNode {
    public:
        inline void addChild(CCNode *child) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::addChild", __thiscall, CCNode*, CCNode*);
            return method(this, child);
        }

        inline void removeChild(CCNode *child) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::removeChild", __thiscall, CCNode*, CCNode*);
            return method(this, child);
        }

        inline void setZOrder(int z) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::setZOrder", __thiscall, CCNode*, int);
            return method(this, z);
        }

        inline void setPosition(const cocos2d::CCPoint& position) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::setPosition", __thiscall, CCNode*, const cocos2d::CCPoint&);
            return method(this, position);
        }

        inline void setVisible(bool visible) {
            SETUP_METHOD_SIG(void, "cocos2d::CCNode::setVisible", __thiscall, CCNode*, bool);
            return method(this, visible);
        }

    };
}