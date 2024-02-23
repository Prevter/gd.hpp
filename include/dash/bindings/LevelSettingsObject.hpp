#pragma once

#include "../internal.hpp"

namespace gd {
    class LevelSettingsObject {
    public:
        SETUP_MEMBER(bool, m_resetCamera, "LevelSettingsObject::m_resetCamera");
    };
}