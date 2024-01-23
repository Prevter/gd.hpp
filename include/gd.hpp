// gd.hpp
// ~~~~~~~~~~~~~~~~
// Main header file for the library.
// This file should be included by the user.
// ~~~~~~~~~~~~~~~~

#pragma once

#include "classes/MenuLayer.hpp"
#include "classes/GameStatsManager.hpp"

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

        initMethod(
            MenuLayer::init,
            "MenuLayer::init",
            &hooks::MenuLayer_init);

        initMethod(
            GameStatsManager::isItemUnlocked,
            "GameStatsManager::isItemUnlocked",
            &hooks::GameStatsManager_isItemUnlocked);
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