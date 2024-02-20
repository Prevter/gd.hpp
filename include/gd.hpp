#pragma once

#include <cstdint>
#include <string>

namespace gd {
    /// @brief Find current offset for a given symbol.
    /// @param name The name of the symbol.
    /// @return The offset of the symbol.
    uintptr_t findOffset(const std::string &name);

    /// @brief Find current offset for a given signature.
    /// @param signature The signature of the symbol.
    /// @return The offset of the symbol.
    uintptr_t findSignature(const std::string &signature);

    /// @brief Get the current version of the game.
    /// @return The version of the game.
    const std::string &getVersion();
}