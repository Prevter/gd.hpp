#pragma once

namespace gd::cocos2d {
    class CCPoint {
    public:
        float x, y;

        CCPoint() : x(0), y(0) {}

        CCPoint(float x, float y) : x(x), y(y) {}
    };

    class CCSize {
    public:
        float width, height;

        CCSize() : width(0), height(0) {}

        CCSize(float width, float height) : width(width), height(height) {}
    };

    class CCRect {
    public:
        CCPoint origin;
        CCSize size;

        CCRect() : origin(), size() {}

        CCRect(float x, float y, float width, float height) : origin(x, y), size(width, height) {}

        CCRect(CCPoint origin, CCSize size) : origin(origin), size(size) {}
    };

    // CCPoint operators
    inline CCPoint operator+(const CCPoint &lhs, const CCPoint &rhs) {
        return CCPoint(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    inline CCPoint operator-(const CCPoint &lhs, const CCPoint &rhs) {
        return CCPoint(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    inline CCPoint operator*(const CCPoint &lhs, const CCPoint &rhs) {
        return CCPoint(lhs.x * rhs.x, lhs.y * rhs.y);
    }

    inline CCPoint operator/(const CCPoint &lhs, const CCPoint &rhs) {
        return CCPoint(lhs.x / rhs.x, lhs.y / rhs.y);
    }

    inline CCPoint operator+(const CCPoint &lhs, const CCSize &rhs) {
        return CCPoint(lhs.x + rhs.width, lhs.y + rhs.height);
    }

    inline CCPoint operator-(const CCPoint &lhs, const CCSize &rhs) {
        return CCPoint(lhs.x - rhs.width, lhs.y - rhs.height);
    }

    inline CCPoint operator*(const CCPoint &lhs, const CCSize &rhs) {
        return CCPoint(lhs.x * rhs.width, lhs.y * rhs.height);
    }

    inline CCPoint operator/(const CCPoint &lhs, const CCSize &rhs) {
        return CCPoint(lhs.x / rhs.width, lhs.y / rhs.height);
    }
}