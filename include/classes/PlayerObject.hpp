// classes/PlayerObject.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for PlayerObject class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class PlayerObject
    {
    public:
        INIT_METHOD(PlayerObject, playDeathEffect, void, void(__fastcall *)(PlayerObject *), PlayerObject *);
        INIT_METHOD(PlayerObject, update, void, void(__fastcall *)(PlayerObject *, int, float), PlayerObject *, float);
        INIT_METHOD(PlayerObject, toggleVisibility, void, void(__fastcall *)(PlayerObject *, int, bool), PlayerObject *, bool);
        INIT_METHOD(PlayerObject, resetStreak, void, void(__fastcall *)(PlayerObject *), PlayerObject *);
        INIT_METHOD(PlayerObject, stopDashing, void, void(__fastcall *)(PlayerObject *), PlayerObject *);
        INIT_METHOD(PlayerObject, playerDestroyed, void, void(__fastcall *)(PlayerObject *, int, bool), PlayerObject *, bool);
        INIT_METHOD(PlayerObject, doReversePlayer, void, void(__fastcall *)(PlayerObject *, int, bool), PlayerObject *, bool);
        INIT_METHOD(PlayerObject, flipGravity, void, void(__fastcall *)(PlayerObject *, int, bool, bool), PlayerObject *, bool, bool);

        INIT_MEMBER(double, m_yAccel)
        INIT_MEMBER(double, m_xAccel)
        INIT_MEMBER(float, m_playerSpeed)
        INIT_MEMBER(float, m_playerSize)
        INIT_MEMBER(bool, m_isShip)
        INIT_MEMBER(bool, m_isBird)
        INIT_MEMBER(bool, m_isBall)
        INIT_MEMBER(bool, m_isDart)
        INIT_MEMBER(bool, m_isRobot)
        INIT_MEMBER(bool, m_isSpider)
        INIT_MEMBER(bool, m_isJetpack)
        INIT_MEMBER(bool, m_isSwing)
        INIT_MEMBER(bool, m_isHolding)
        INIT_MEMBER(bool, m_isSliding)
    };
}

namespace gd::hooks
{
    inline void __fastcall PlayerObject_playDeathEffect(PlayerObject *self)
    {
        if (!PlayerObject::playDeathEffect.isHooked())
            return PlayerObject::playDeathEffect(self);

        auto hook = PlayerObject::playDeathEffect.getHook();
        return hook(self);
    }

    inline void __fastcall PlayerObject_update(PlayerObject *self, int, float dt)
    {
        if (!PlayerObject::update.isHooked())
            return PlayerObject::update(self, dt);

        auto hook = PlayerObject::update.getHook();
        return hook(self, dt);
    }

    inline void __fastcall PlayerObject_toggleVisibility(PlayerObject *self, int, bool visible)
    {
        if (!PlayerObject::toggleVisibility.isHooked())
            return PlayerObject::toggleVisibility(self, visible);

        auto hook = PlayerObject::toggleVisibility.getHook();
        return hook(self, visible);
    }

    inline void __fastcall PlayerObject_resetStreak(PlayerObject *self)
    {
        if (!PlayerObject::resetStreak.isHooked())
            return PlayerObject::resetStreak(self);

        auto hook = PlayerObject::resetStreak.getHook();
        return hook(self);
    }

    inline void __fastcall PlayerObject_stopDashing(PlayerObject *self)
    {
        if (!PlayerObject::stopDashing.isHooked())
            return PlayerObject::stopDashing(self);

        auto hook = PlayerObject::stopDashing.getHook();
        return hook(self);
    }

    inline void __fastcall PlayerObject_playerDestroyed(PlayerObject *self, int, bool v1)
    {
        if (!PlayerObject::playerDestroyed.isHooked())
            return PlayerObject::playerDestroyed(self, v1);

        auto hook = PlayerObject::playerDestroyed.getHook();
        return hook(self, v1);
    }

    inline void __fastcall PlayerObject_doReversePlayer(PlayerObject *self, int, bool v1)
    {
        if (!PlayerObject::doReversePlayer.isHooked())
            return PlayerObject::doReversePlayer(self, v1);

        auto hook = PlayerObject::doReversePlayer.getHook();
        return hook(self, v1);
    }

    inline void __fastcall PlayerObject_flipGravity(PlayerObject *self, int, bool v1, bool v2)
    {
        if (!PlayerObject::flipGravity.isHooked())
            return PlayerObject::flipGravity(self, v1, v2);

        auto hook = PlayerObject::flipGravity.getHook();
        return hook(self, v1, v2);
    }
}