// gd.hpp
// ~~~~~~~~~~~~~~~~
// Main header file for the library.
// This file should be included by the user.
// ~~~~~~~~~~~~~~~~

#ifndef GD_HPP
#define GD_HPP
#pragma once

#include "classes/cocos/CCEGLView.hpp"
#include "classes/cocos/CCPoint.hpp"
#include "classes/AppDelegate.hpp"
#include "classes/CCCircleWave.hpp"
#include "classes/EditorPauseLayer.hpp"
#include "classes/GameManager.hpp"
#include "classes/GameObject.hpp"
#include "classes/GameStatsManager.hpp"
#include "classes/GJBaseGameLayer.hpp"
#include "classes/GJGameLevel.hpp"
#include "classes/LevelEditorLayer.hpp"
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

    /// @brief Initialize all hooks/addresses. Must be called
    /// before using any other function.
    void init();

    inline void setHookCreation(std::function<void(void *, void *, void **)> createHook)
    {
        utils::CreateHook = createHook;
    }

    inline void setHookRemoval(std::function<void(void *)> removeHook)
    {
        utils::RemoveHook = removeHook;
    }
}

#endif // GD_HPP