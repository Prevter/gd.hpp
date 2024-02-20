#pragma once

#define CC_SYM(symbol) Signature(symbol, "libcocos2d.dll")
#define FM_SYM(symbol) Signature(symbol, "fmod.dll")

namespace gd::maps {

    struct Signature {
        const char *symbol;
        const char *module;

        Signature(const char *symbol, const char *module) : symbol(symbol), module(module) {}
    };

}