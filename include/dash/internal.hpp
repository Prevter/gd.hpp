#pragma once

#include "../gd.hpp"

#include <string>
#include <stdexcept>

#define CC_SYM(symbol) Signature(#symbol, "libcocos2d.dll")
#define FM_SYM(symbol) Signature(#symbol, "fmod.dll")

#define SETUP_METHOD(returnType, symbol, callingConvention, ...) \
    auto offset = ::gd::findOffset(symbol);                   \
    if (offset == 0)                                               \
        throw std::runtime_error("Failed to find " symbol " offset."); \
    auto method = reinterpret_cast<returnType(callingConvention *)(__VA_ARGS__)>(offset)

#define SETUP_METHOD_SIG(returnType, symbol, callingConvention, ...) \
    auto offset = ::gd::findSignature(symbol);                   \
    if (offset == 0)                                               \
        throw std::runtime_error("Failed to find " symbol " offset."); \
    auto method = reinterpret_cast<returnType(callingConvention *)(__VA_ARGS__)>(offset)

#define SETUP_MEMBER(type, name, symbol) \
    inline type &name() {                 \
        auto offset = ::gd::findOffset(symbol); \
        if (offset == 0)                       \
            throw std::runtime_error("Failed to find " symbol " offset."); \
        return *reinterpret_cast<type *>(this + offset); \
    }                                    \
    inline void name(type value) {          \
        auto offset = ::gd::findOffset(symbol); \
        if (offset == 0)                       \
            throw std::runtime_error("Failed to find " symbol " offset."); \
        *reinterpret_cast<type *>(this + offset) = value; \
    }


namespace gd {

    /// @brief Find current offset for a given symbol.
    /// @param name The name of the symbol. (e.g. "PlayLayer::resetLevel")
    /// @return The offset of the symbol.
    uintptr_t findOffset(const std::string &name);

    /// @brief Find current offset for a given signature.
    /// @param name The name of the symbol. (e.g. "cocos2d::CCDirector::sharedDirector")
    /// @return The offset of the symbol.
    uintptr_t findSignature(const std::string &name);

    /// @brief Get the current version of the game.
    /// @return The version of the game.
    const std::string &getVersion();

    struct Signature {
        const char *symbol;
        const char *module;

        Signature(const char *symbol, const char *module) : symbol(symbol), module(module) {}
    };

}