// classes/FMODAudioEngine.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for FMODAudioEngine class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "../fmod/fmod.hpp"

namespace gd {
    class FMODAudioEngine
    {
    public:
        INIT_METHOD(FMODAudioEngine, sharedEngine, FMODAudioEngine*, FMODAudioEngine*(__stdcall*)());

        INIT_MEMBER(::FMOD::System*, m_system);
    };
}

namespace gd::hooks {
    inline FMODAudioEngine *__stdcall FMODAudioEngine_sharedEngine()
    {
        if (!FMODAudioEngine::sharedEngine.isHooked())
            return FMODAudioEngine::sharedEngine();

        auto hook = FMODAudioEngine::sharedEngine.getHook();
        return hook();
    }
}