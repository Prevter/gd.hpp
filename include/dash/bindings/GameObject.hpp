#pragma once

#include "../internal.hpp"
#include "cocos/CCGeometry.hpp"
#include "cocos/CCNode.hpp"

namespace gd {
    class GameObject : public cocos2d::CCNode {
    public:
        inline cocos2d::CCRect* getObjectRect() {
            SETUP_METHOD(cocos2d::CCRect*, "GameObject::getObjectRect", __thiscall, GameObject*);
            return method(this);
        }

        SETUP_MEMBER(uint32_t, m_objectID, "GameObject::m_objectID")
        SETUP_MEMBER(cocos2d::CCPoint, m_startPosition, "GameObject::m_startPosition")
    };
}