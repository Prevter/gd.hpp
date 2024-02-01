// classes/GameObject.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GameObject class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "cocos/CCPoint.hpp"

namespace gd
{
    class GameObject : public BindableClassBase
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
