#pragma once

#include "../internal.hpp"

namespace gd {
    class FMODAudioEngine {
    public:
        inline static FMODAudioEngine *sharedEngine() {
            SETUP_METHOD(FMODAudioEngine*, "FMODAudioEngine::sharedEngine", __stdcall);
            return method();
        }

        SETUP_MEMBER(::FMOD::System*, m_system, "FMODAudioEngine::m_system")
    };
}