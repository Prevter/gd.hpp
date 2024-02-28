#pragma once

#include "../internal.hpp"

#include "GameManager.hpp"
#include "GJGameState.hpp"
#include "GJBaseGameLayer.hpp"

namespace gd {
    class GJGameLevel;

    class LevelEditorLayer : public GJBaseGameLayer {
    public:
        inline static LevelEditorLayer *get() {
            return GameManager::sharedState()->m_levelEditorLayer();
        }
    };
}