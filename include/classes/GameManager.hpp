// classes/GameManager.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GameManager class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class PlayLayer;
    class LevelEditorLayer;
    class GJBaseGameLayer;
    class MenuLayer;

    class GameManager
    {
    public:
        INIT_METHOD(GameManager, sharedState, GameManager *, GameManager *(__stdcall *)());
        INIT_METHOD(GameManager, getGameVariable, bool, bool(__fastcall *)(GameManager *, int, const char *), GameManager *, const char *);
        INIT_METHOD(GameManager, setGameVariable, void, void(__fastcall *)(GameManager *, int, const char *, bool), GameManager *, const char *, bool);
        INIT_METHOD(GameManager, updateCustomFPS, void, void(__fastcall *)(GameManager *), GameManager *);

        INIT_MEMBER(float, m_customFPSTarget)
        INIT_MEMBER(PlayLayer*, m_playLayer)
        INIT_MEMBER(LevelEditorLayer*, m_levelEditorLayer)
        INIT_MEMBER(GJBaseGameLayer*, m_gameLayer)
        INIT_MEMBER(MenuLayer*, m_menuLayer)
        INIT_MEMBER(std::string, m_userName)

    private:
        friend void init();
    };
}

namespace gd::hooks
{
    inline GameManager *__stdcall GameManager_sharedState()
    {
        if (!GameManager::sharedState.isHooked())
            return GameManager::sharedState();

        auto hook = GameManager::sharedState.getHook();
        return hook();
    }

    inline bool __fastcall GameManager_getGameVariable(GameManager *self, int, const char *name)
    {
        if (!GameManager::getGameVariable.isHooked())
            return GameManager::getGameVariable(self, name);

        auto hook = GameManager::getGameVariable.getHook();
        return hook(self, name);
    }

    inline void __fastcall GameManager_setGameVariable(GameManager *self, int, const char *name, bool value)
    {
        if (!GameManager::setGameVariable.isHooked())
            return GameManager::setGameVariable(self, name, value);

        auto hook = GameManager::setGameVariable.getHook();
        return hook(self, name, value);
    }

    inline void __fastcall GameManager_updateCustomFPS(GameManager *self)
    {
        if (!GameManager::updateCustomFPS.isHooked())
            return GameManager::updateCustomFPS(self);

        auto hook = GameManager::updateCustomFPS.getHook();
        return hook(self);
    }
}
