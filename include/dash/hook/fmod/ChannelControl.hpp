#pragma once

#include "../hook.hpp"
#include "../../../fmod/fmod.hpp"

namespace gd::hook::ChannelControl {

    // FMOD::ChannelControl::setVolume

    inline static uintptr_t setVolume_addr = 0x0;
    inline static std::function<FMOD_RESULT(FMOD::Channel*, float)> setVolume_hook;

    /// @brief Calls the original FMOD::ChannelControl::setVolume function.
    inline static FMOD_RESULT setVolume(FMOD::Channel* channel, float volume) {
        return reinterpret_cast<FMOD_RESULT (__stdcall *)(FMOD::Channel*, float)>(setVolume_addr)(channel, volume);
    }

    /// @brief Wrapper for the FMOD::ChannelControl::setVolume hook.
    inline FMOD_RESULT __stdcall setVolumeHook(FMOD::Channel* channel, float volume) { return setVolume_hook(channel, volume); }

    /// @brief Installs the hook for FMOD::ChannelControl::setVolume.
    SETUP_HOOK_SIG("FMOD::ChannelControl::setVolume", FMOD_RESULT, setVolume, FMOD::Channel*, float)

}