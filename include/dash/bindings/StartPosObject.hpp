#pragma once

#include "../internal.hpp"
#include "GameObject.hpp"

namespace gd {
    class LevelSettingsObject;

    class StartPosObject : public GameObject {
    public:
        SETUP_MEMBER(LevelSettingsObject*, m_levelSettings, "StartPosObject::m_levelSettings");
    };
}