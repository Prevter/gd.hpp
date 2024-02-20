#pragma once

#include <cstdint>
#include <string>

namespace gd::utils {
    /// @brief Find the address of a symbol in a module.
    /// @param module The name of the module.
    /// @param symbol The name of the symbol.
    /// @return The address of the symbol or nullptr if it was not found.
    uintptr_t findSymbol(const std::string &module, const std::string &symbol);
}