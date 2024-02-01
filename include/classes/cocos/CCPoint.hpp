// classes/cocos/CCPoint.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for cocos2d::CCPoint class.
// ~~~~~~~~~~~~~~~~

#pragma once

namespace gd::cocos2d
{
    class CCPoint
    {
    public:
        float x, y;

        CCPoint() : x(0), y(0) {}
        CCPoint(float x, float y) : x(x), y(y) {}
    };
}