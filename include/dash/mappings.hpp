#pragma once

#include "internal.hpp"

#include <unordered_map>
#include <string>

/// @brief Contains methods for getting the offsets and addresses for each version.
namespace gd::maps {

    /// @brief Get the addresses for the current version.
    /// @param version The version to get the addresses for.
    /// @return An unordered map containing the addresses for each symbol.
    const std::unordered_map<std::string, uintptr_t>& getForVersion(const std::string& version);

    /// @brief Get the signatures for the current version.
    /// @param version The version to get the signatures for.
    /// @return An unordered map containing the signatures for each symbol.
    const std::unordered_map<std::string, Signature>& getSignaturesForVersion(const std::string& version);

}
