// classes/GameObject.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GameObject class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "cocos/CCGeometry.hpp"

namespace gd
{
    class GameObject
    {
        INIT_MEMBER(uint32_t, m_objectID)
        INIT_MEMBER(cocos2d::CCPoint, m_startPosition)

    private:
        friend void init();
    };
}

namespace gd::hooks
{
}
