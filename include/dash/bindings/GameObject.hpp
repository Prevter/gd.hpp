#pragma once

#include "../internal.hpp"
#include "cocos/CCGeometry.hpp"

namespace gd {
    class GameObject {
    public:
        SETUP_MEMBER(uint32_t, m_objectID, "GameObject::m_objectID")
        SETUP_MEMBER(cocos2d::CCPoint, m_startPosition, "GameObject::m_startPosition")
    };
}