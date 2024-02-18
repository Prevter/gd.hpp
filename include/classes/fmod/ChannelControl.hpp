// classes/fmod/ChannelControl.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for FMOD::ChannelControl class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../../utils/class.hpp"
#include "../../fmod/fmod.hpp"

namespace gd::FMOD
{
    class ChannelControl
    {
    public:
        INIT_METHOD(FMOD::ChannelControl, setVolume, FMOD_RESULT, FMOD_RESULT(__stdcall *)(::FMOD::Channel*, float), ::FMOD::Channel*, float);
    };
}

namespace gd::hooks {
    inline FMOD_RESULT __stdcall ChannelControl_setVolume(::FMOD::Channel* channel, float volume)
    {
        if (!gd::FMOD::ChannelControl::setVolume.isHooked())
            return gd::FMOD::ChannelControl::setVolume(channel, volume);

        auto hook = gd::FMOD::ChannelControl::setVolume.getHook();
        return hook(channel, volume);
    }
}