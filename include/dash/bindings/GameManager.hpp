#pragma once

#include "../internal.hpp"

namespace gd {
    class PlayLayer;

    class LevelEditorLayer;

    class GJBaseGameLayer;

    class MenuLayer;

    class GameManager {
    public:
        inline static GameManager *sharedState() {
            SETUP_METHOD(GameManager*, "GameManager::sharedState", __stdcall);
            return method();
        }

        inline bool getGameVariable(const char* name) {
            SETUP_METHOD(bool, "GameManager::getGameVariable", __thiscall, GameManager*, const char*);
            return method(this, name);
        }

        inline void setGameVariable(const char* name, bool value) {
            SETUP_METHOD(void, "GameManager::setGameVariable", __thiscall, GameManager*, const char*, bool);
            return method(this, name, value);
        }

        inline void updateCustomFPS() {
            SETUP_METHOD(void, "GameManager::updateCustomFPS", __thiscall, GameManager*);
            return method(this);
        }

        SETUP_MEMBER(float, m_customFPSTarget, "GameManager::m_customFPSTarget")
        SETUP_MEMBER(PlayLayer*, m_playLayer, "GameManager::m_playLayer")
        SETUP_MEMBER(LevelEditorLayer*, m_levelEditorLayer, "GameManager::m_levelEditorLayer")
        SETUP_MEMBER(GJBaseGameLayer*, m_gameLayer, "GameManager::m_gameLayer")
        SETUP_MEMBER(MenuLayer*, m_menuLayer, "GameManager::m_menuLayer")
        SETUP_MEMBER(std::string, m_playerName, "GameManager::m_playerName")
    };
}