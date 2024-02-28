#pragma once

#include "../internal.hpp"

namespace gd {
    class GJGameState {
    public:
        SETUP_MEMBER(float, m_stepSpeed, "GJGameState::m_stepSpeed")
        SETUP_MEMBER(cocos2d::CCPoint, m_cameraPosition, "GJGameState::m_cameraPosition")
        SETUP_MEMBER(float, m_cameraAngle, "GJGameState::m_cameraAngle")
        SETUP_MEMBER(float, m_targetCameraAngle, "GJGameState::m_targetCameraAngle")
        SETUP_MEMBER(float, m_cameraScale, "GJGameState::m_cameraScale")
        SETUP_MEMBER(float, m_targetCameraScale, "GJGameState::m_targetCameraScale")
    };
}