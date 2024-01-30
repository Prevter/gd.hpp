// gd.hpp
// ~~~~~~~~~~~~~~~~
// Main header file for the library.
// This file should be included by the user.
// ~~~~~~~~~~~~~~~~

#pragma once

#include "classes/GameManager.hpp"
#include "classes/GameStatsManager.hpp"
#include "classes/MenuLayer.hpp"
#include "classes/PlayLayer.hpp"

#include "mappings/maps.hpp"

namespace gd
{
    /// @brief Game base address
    inline uintptr_t base;

    /// @brief Cocos2D base address
    inline uintptr_t cocosBase;

    /// @brief FMOD base address
    inline uintptr_t fmodBase;

    template <typename R, typename S, typename... Args>
    void initMethod(utils::BindableMethod<R, S, Args...> &method, const char *name, S hook)
    {
        if (maps::addresses.find(name) == maps::addresses.end())
            return;

        method = utils::BindableMethod<R, S, Args...>(base + gd::maps::addresses[name], hook);
    }

    /// @brief Initialize all hooks/addresses. Must be called
    /// before using any other function.
    void init()
    {
        base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        cocosBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));
        fmodBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("fmod.dll"));

        gd::maps::init();

        // GameManager
        initMethod(GameManager::sharedState, "GameManager::sharedState", &hooks::GameManager_sharedState);
        initMethod(GameManager::getGameVariable, "GameManager::getGameVariable", &hooks::GameManager_getGameVariable);
        initMethod(GameManager::setGameVariable, "GameManager::setGameVariable", &hooks::GameManager_setGameVariable);
        GameManager::init_m_customFPSTarget("GameManager::m_customFPSTarget");

        // GameStatsManager
        initMethod(GameStatsManager::isItemUnlocked, "GameStatsManager::isItemUnlocked", &hooks::GameStatsManager_isItemUnlocked);

        // MenuLayer
        initMethod(MenuLayer::init, "MenuLayer::init", &hooks::MenuLayer_init);

        // PlayLayer
        initMethod(PlayLayer::init, "PlayLayer::init", &hooks::PlayLayer_init);
        initMethod(PlayLayer::resetLevel, "PlayLayer::resetLevel", &hooks::PlayLayer_resetLevel);
        initMethod(PlayLayer::onQuit, "PlayLayer::onQuit", &hooks::PlayLayer_onQuit);
        initMethod(PlayLayer::destructor, "PlayLayer::destructor", &hooks::PlayLayer_destructor);
        initMethod(PlayLayer::update, "PlayLayer::update", &hooks::PlayLayer_update);
        initMethod(PlayLayer::togglePracticeMode, "PlayLayer::togglePracticeMode", &hooks::PlayLayer_togglePracticeMode);
        initMethod(PlayLayer::removeAllCheckpoints, "PlayLayer::removeAllCheckpoints", &hooks::PlayLayer_removeAllCheckpoints);
        initMethod(PlayLayer::addObject, "PlayLayer::addObject", &hooks::PlayLayer_addObject);
        initMethod(PlayLayer::destroyObject, "PlayLayer::destroyObject", &hooks::PlayLayer_destroyObject);
        initMethod(PlayLayer::setStartPosObject, "PlayLayer::setStartPosObject", &hooks::PlayLayer_setStartPosObject);
        initMethod(PlayLayer::pickupCoin, "PlayLayer::pickupCoin", &hooks::PlayLayer_pickupCoin);
        initMethod(PlayLayer::startMusic, "PlayLayer::startMusic", &hooks::PlayLayer_startMusic);
        PlayLayer::init_m_isPracticeMode("PlayLayer::m_isPracticeMode");
        PlayLayer::init_m_startPosCheckpoint("PlayLayer::m_startPosCheckpoint");
        PlayLayer::init_m_jumps("PlayLayer::m_jumps");
        PlayLayer::init_m_attempts("PlayLayer::m_attempts");
        PlayLayer::init_m_isAlive("PlayLayer::m_isAlive");
        PlayLayer::init_m_isDead("PlayLayer::m_isDead");
        PlayLayer::init_m_player1("PlayLayer::m_player1");
        PlayLayer::init_m_player2("PlayLayer::m_player2");
        PlayLayer::init_m_level("PlayLayer::m_level");
        PlayLayer::init_m_time("PlayLayer::m_time");
        PlayLayer::init_m_dualMode("PlayLayer::m_dualMode");
        PlayLayer::init_m_hasCompleted("PlayLayer::m_hasCompleted");

    }

    void setHookCreation(std::function<void(void *, void *, void **)> createHook)
    {
        utils::CreateHook = createHook;
    }

    void setHookRemoval(std::function<void(void *)> removeHook)
    {
        utils::RemoveHook = removeHook;
    }
}