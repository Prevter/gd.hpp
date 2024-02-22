#pragma once

#include "../internal.hpp"
#include "GJDropDownLayer.hpp"

namespace gd {
    class OptionsLayer : public GJDropDownLayer {
    public:
        inline static OptionsLayer *create() {
            SETUP_METHOD(OptionsLayer*, "OptionsLayer::create", __stdcall);
            return method();
        }
    };
}