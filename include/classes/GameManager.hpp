// classes/GameManager.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GameManager class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class GameManager : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<GameManager *, GameManager *(__stdcall *)()> sharedState;
        inline static utils::BindableMethod<bool, bool(__fastcall *)(GameManager *, int, const char *), GameManager *, const char *> getGameVariable;
        inline static utils::BindableMethod<void, void(__fastcall *)(GameManager *, int, const char *, bool), GameManager *, const char *, bool> setGameVariable;

        INIT_MEMBER(float, m_customFPSTarget)

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
}