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

        [[nodiscard]] inline float getMinX() const {
            return origin.x;
        } /// return the leftmost x-value of current rect
        [[nodiscard]] inline float getMidX() const {
            return (float)(origin.x + size.width / 2.0);
        } /// return the midpoint x-value of current rect
        [[nodiscard]] inline float getMaxX() const {
            return (float)(origin.x + size.width);
        } /// return the rightmost x-value of current rect
        [[nodiscard]] inline float getMinY() const {
            return origin.y;
        } /// return the bottommost y-value of current rect
        [[nodiscard]] inline float getMidY() const {
            return (float)(origin.y + size.height / 2.0);
        } /// return the midpoint y-value of current rect
        [[nodiscard]] inline float getMaxY() const {
            return origin.y + size.height;
        } /// return the topmost y-value of current rect
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