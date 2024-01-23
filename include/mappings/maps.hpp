// mappings/maps.hpp
// ~~~~~~~~~~~~~~~~
// Responsible for loading the correct mappings for the current version.
// ~~~~~~~~~~~~~~~~

#pragma once

#include "2.113.hpp"
#include "2.200.hpp"
#include "2.201.hpp"
#include "2.202.hpp"
#include "2.203.hpp"
#include "2.204.hpp"

#include "../utils/version.hpp"

namespace gd::maps
{
    inline std::map<std::string, uintptr_t> addresses;

    /// @brief Initialize the mappings for the current version.
    void init()
    {
        auto version = utils::getVersion();

        if (version == "2.113")
        {
            addresses = maps::v2_113::addresses;
        }
        else if (version == "2.200")
        {
            addresses = maps::v2_200::addresses;
        }
        else if (version == "2.201")
        {
            addresses = maps::v2_201::addresses;
        }
        else if (version == "2.202")
        {
            addresses = maps::v2_202::addresses;
        }
        else if (version == "2.203")
        {
            addresses = maps::v2_203::addresses;
        }
        else if (version == "2.204")
        {
            addresses = maps::v2_204::addresses;
        }
        else
        {
            // unknown version, so we will use pattern scanning
            // to find the addresses
            // TODO: implement pattern scanning
        }
    }
}