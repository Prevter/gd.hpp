#pragma once

#include "hook.hpp"
#include "../bindings/PlayLayer.hpp"

namespace gd::hook::PlayLayer {

    // PlayLayer::init

    inline static uintptr_t init_addr = 0x0;
    inline static std::function<bool(gd::PlayLayer*, gd::GJGameLevel*, bool, bool)> init_hook;

    /// @brief Calls the original PlayLayer::init function.
    inline static bool init(gd::PlayLayer* self, gd::GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        return reinterpret_cast<bool (__thiscall *)(gd::PlayLayer*, gd::GJGameLevel*, bool, bool)>(init_addr)(self, level, useReplay, dontCreateObjects);
    }

    /// @brief Wrapper for the PlayLayer::init hook.
    inline bool __fastcall initHook(gd::PlayLayer* self, int, gd::GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        return init_hook(self, level, useReplay, dontCreateObjects);
    }

    /// @brief Installs the hook for PlayLayer::init.
    SETUP_HOOK("PlayLayer::init", bool, init, gd::PlayLayer*, gd::GJGameLevel*, bool, bool)

    // PlayLayer::resetLevel

    inline static uintptr_t resetLevel_addr = 0x0;
    inline static std::function<void(gd::PlayLayer*)> resetLevel_hook;

    /// @brief Calls the original PlayLayer::resetLevel function.
    inline static void resetLevel(gd::PlayLayer* self) {
        return reinterpret_cast<void (__thiscall *)(gd::PlayLayer*)>(resetLevel_addr)(self);
    }

    /// @brief Wrapper for the PlayLayer::resetLevel hook.
    inline void __fastcall resetLevelHook(gd::PlayLayer* self) { return resetLevel_hook(self); }

    /// @brief Installs the hook for PlayLayer::resetLevel.
    SETUP_HOOK("PlayLayer::resetLevel", void, resetLevel, gd::PlayLayer*)

    // PlayLayer::addObject

    inline static uintptr_t addObject_addr = 0x0;
    inline static std::function<void(gd::PlayLayer*, gd::GameObject*)> addObject_hook;

    /// @brief Calls the original PlayLayer::addObject function.
    inline static void addObject(gd::PlayLayer* self, gd::GameObject* object) {
        return reinterpret_cast<void (__thiscall *)(gd::PlayLayer*, gd::GameObject*)>(addObject_addr)(self, object);
    }

    /// @brief Wrapper for the PlayLayer::addObject hook.
    inline void __fastcall addObjectHook(gd::PlayLayer* self, int, gd::GameObject* object) { return addObject_hook(self, object); }

    /// @brief Installs the hook for PlayLayer::addObject.
    SETUP_HOOK("PlayLayer::addObject", void, addObject, gd::PlayLayer*, gd::GameObject*)

    // PlayLayer::destroyPlayer

    inline static uintptr_t destroyPlayer_addr = 0x0;
    inline static std::function<void(gd::PlayLayer*, gd::PlayerObject*, gd::GameObject*)> destroyPlayer_hook;

    /// @brief Calls the original PlayLayer::destroyPlayer function.
    inline static void destroyPlayer(gd::PlayLayer* self, gd::PlayerObject* player, gd::GameObject* object) {
        return reinterpret_cast<void (__thiscall *)(gd::PlayLayer*, gd::PlayerObject*, gd::GameObject*)>(destroyPlayer_addr)(self, player, object);
    }

    /// @brief Wrapper for the PlayLayer::destroyPlayer hook.
    inline void __fastcall destroyPlayerHook(gd::PlayLayer* self, int, gd::PlayerObject* player, gd::GameObject* object) {
        return destroyPlayer_hook(self, player, object);
    }

    /// @brief Installs the hook for PlayLayer::destroyPlayer.
    SETUP_HOOK("PlayLayer::destroyPlayer", void, destroyPlayer, gd::PlayLayer*, gd::PlayerObject*, gd::GameObject*)
}