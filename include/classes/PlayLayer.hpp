// classes/PlayLayer.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for PlayLayer class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class GJGameLevel;
    class GameObject;
    class PlayerObject;

    class PlayLayer : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(PlayLayer *, int, GJGameLevel *, bool, bool), PlayLayer *, GJGameLevel *, bool, bool> init;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, float), PlayLayer *, float> update;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *), PlayLayer *> destructor;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *), PlayLayer *> resetLevel;
        // levelComplete
        inline static utils::BindableMethod<int, int(__fastcall *)(PlayLayer *), PlayLayer *> onQuit;
        // destroyPlayer
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, GameObject *), PlayLayer *, GameObject *> addObject;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, GameObject *), PlayLayer *, GameObject *> destroyObject;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, GameObject *), PlayLayer *, GameObject *> pickupCoin;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, GameObject *), PlayLayer *, GameObject *> setStartPosObject;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *), PlayLayer *> startMusic;
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *), PlayLayer *> resetLevelFromStart;
        // markCheckpoint
        inline static utils::BindableMethod<void, void(__fastcall *)(PlayLayer *, int, bool), PlayLayer *, bool> togglePracticeMode;

        INIT_MEMBER(bool, m_isPracticeMode)
        INIT_MEMBER(void *, m_startPosCheckpoint)
        INIT_MEMBER(int, m_jumps)
        INIT_MEMBER(int, m_attempts)
        INIT_MEMBER(bool, m_isAlive)
        INIT_MEMBER(bool, m_isDead)
        INIT_MEMBER(PlayerObject *, m_player1)
        INIT_MEMBER(PlayerObject *, m_player2)
        INIT_MEMBER(GJGameLevel *, m_level)
        INIT_MEMBER(double, m_time)
        INIT_MEMBER(bool, m_dualMode)
        INIT_MEMBER(bool, m_hasCompleted)

    private:
        friend void init();
    };
}

namespace gd::hooks
{
    inline bool __fastcall PlayLayer_init(PlayLayer *self, int, GJGameLevel *level, bool v1, bool v2)
    {
        if (!PlayLayer::init.isHooked())
            return PlayLayer::init(self, level, v1, v2);

        auto hook = PlayLayer::init.getHook();
        return hook(self, level, v1, v2);
    }

    inline void __fastcall PlayLayer_resetLevel(PlayLayer *self)
    {
        if (!PlayLayer::resetLevel.isHooked())
            return PlayLayer::resetLevel(self);

        auto hook = PlayLayer::resetLevel.getHook();
        return hook(self);
    }

    inline int __fastcall PlayLayer_onQuit(PlayLayer *self)
    {
        if (!PlayLayer::onQuit.isHooked())
            return PlayLayer::onQuit(self);

        auto hook = PlayLayer::onQuit.getHook();
        return hook(self);
    }

    inline void __fastcall PlayLayer_destructor(PlayLayer *self)
    {
        if (!PlayLayer::destructor.isHooked())
            return PlayLayer::destructor(self);

        auto hook = PlayLayer::destructor.getHook();
        return hook(self);
    }

    inline void __fastcall PlayLayer_update(PlayLayer *self, int, float dt)
    {
        if (!PlayLayer::update.isHooked())
            return PlayLayer::update(self, dt);

        auto hook = PlayLayer::update.getHook();
        return hook(self, dt);
    }

    inline void __fastcall PlayLayer_togglePracticeMode(PlayLayer *self, int, bool toggle)
    {
        if (!PlayLayer::togglePracticeMode.isHooked())
            return PlayLayer::togglePracticeMode(self, toggle);

        auto hook = PlayLayer::togglePracticeMode.getHook();
        return hook(self, toggle);
    }

    inline void __fastcall PlayLayer_resetLevelFromStart(PlayLayer *self)
    {
        if (!PlayLayer::resetLevelFromStart.isHooked())
            return PlayLayer::resetLevelFromStart(self);

        auto hook = PlayLayer::resetLevelFromStart.getHook();
        return hook(self);
    }

    inline void __fastcall PlayLayer_addObject(PlayLayer *self, int, GameObject *object)
    {
        if (!PlayLayer::addObject.isHooked())
            return PlayLayer::addObject(self, object);

        auto hook = PlayLayer::addObject.getHook();
        return hook(self, object);
    }

    inline void __fastcall PlayLayer_destroyObject(PlayLayer *self, int, GameObject *object)
    {
        if (!PlayLayer::destroyObject.isHooked())
            return PlayLayer::destroyObject(self, object);

        auto hook = PlayLayer::destroyObject.getHook();
        return hook(self, object);
    }

    inline void __fastcall PlayLayer_setStartPosObject(PlayLayer *self, int, GameObject *object)
    {
        if (!PlayLayer::setStartPosObject.isHooked())
            return PlayLayer::setStartPosObject(self, object);

        auto hook = PlayLayer::setStartPosObject.getHook();
        return hook(self, object);
    }

    inline void __fastcall PlayLayer_pickupCoin(PlayLayer *self, int, GameObject *object)
    {
        if (!PlayLayer::pickupCoin.isHooked())
            return PlayLayer::pickupCoin(self, object);

        auto hook = PlayLayer::pickupCoin.getHook();
        return hook(self, object);
    }

    inline void __fastcall PlayLayer_startMusic(PlayLayer *self)
    {
        if (!PlayLayer::startMusic.isHooked())
            return PlayLayer::startMusic(self);

        auto hook = PlayLayer::startMusic.getHook();
        return hook(self);
    }
}