#pragma once

#include "../internal.hpp"

namespace gd {
    class LevelSettingsObject {
    public:
        SETUP_MEMBER(bool, m_resetCamera, "LevelSettingsObject::m_resetCamera");
        SETUP_MEMBER(bool, m_isFlipped, "LevelSettingsObject::m_isFlipped");
        SETUP_MEMBER(bool, m_reverseGameplay, "LevelSettingsObject::m_reverseGameplay");
        SETUP_MEMBER(bool, m_startDual, "LevelSettingsObject::m_startDual");
        SETUP_MEMBER(bool, m_startMini, "LevelSettingsObject::m_startMini");
        SETUP_MEMBER(bool, m_mirrorMode, "LevelSettingsObject::m_mirrorMode");
        SETUP_MEMBER(int, m_startMode, "LevelSettingsObject::m_startMode");
        SETUP_MEMBER(int, m_startSpeed, "LevelSettingsObject::m_startSpeed");
    };
}