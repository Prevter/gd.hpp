#pragma once

#include "internal.hpp"

#include <unordered_map>
#include <string>

// Maps for all versions
#include <dash/mappings/patterns.hpp>
#include <dash/mappings/2204.hpp>
#include <dash/mappings/2203.hpp>
#include <dash/mappings/2202.hpp>
// #include <dash/mappings/2201.hpp>
// #include <dash/mappings/2200.hpp>
// #include <dash/mappings/2113.hpp>

#include <cstdio>

/// @brief Contains methods for getting the offsets and addresses for each version.
namespace gd::maps {
    /// @brief Get the addresses for the current version.
    /// @param version The version to get the addresses for.
    /// @return An unordered map containing the addresses for each symbol.
    inline const std::unordered_map<std::string, uintptr_t> &getForVersion(const std::string &version) {
        if (version == "2.204") {
            return v2_204::addresses;
        } else if (version == "2.203") {
            return v2_203::addresses;
        } else if (version == "2.202") {
            return v2_202::addresses;
        // } else if (version == "2.201") {
        //     return v2_201::addresses;
        // } else if (version == "2.200") {
        //     return v2_200::addresses;
        // } else if (version == "2.113") {
        //     return v2_113::addresses;
        } else {
            // return patterns::addresses;
        }

        return v2_204::addresses;
    }

    /// @brief Get the signatures for the current version.
    /// @param version The version to get the signatures for.
    /// @return An unordered map containing the signatures for each symbol.
    inline const std::unordered_map<std::string, Signature> &getSignaturesForVersion(const std::string &version) {
        if (version == "2.204") {
            return v2_204::signatures;
        } else if (version == "2.203") {
            return v2_203::signatures;
        } else if (version == "2.202") {
            return v2_202::signatures;
        // } else if (version == "2.201") {
        //     return v2_201::signatures;
        // } else if (version == "2.200") {
        //     return v2_200::signatures;
        // } else if (version == "2.113") {
        //     return v2_113::signatures;
        } else {
            // return patterns::signatures;
        }

        return v2_204::signatures;
    }

}
