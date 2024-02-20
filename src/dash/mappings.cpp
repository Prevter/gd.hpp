#include <dash/mappings.hpp>

// Maps for all versions
#include <dash/mappings/patterns.hpp>
#include <dash/mappings/2204.hpp>
// #include <dash/mappings/2203.hpp>
// #include <dash/mappings/2202.hpp>
// #include <dash/mappings/2201.hpp>
// #include <dash/mappings/2200.hpp>
// #include <dash/mappings/2113.hpp>

namespace gd::maps {

    const std::unordered_map<std::string, uintptr_t> &getForVersion(const std::string &version) {
        if (version == "2.204") {
            return v2_204::addresses;
        }
            // else if (version == "2.203") {
            //     return v2_203::addresses;
            // }
            // else if (version == "2.202") {
            //     return v2_202::addresses;
            // }
            // else if (version == "2.201") {
            //     return v2_201::addresses;
            // }
            // else if (version == "2.200") {
            //     return v2_200::addresses;
            // }
            // else if (version == "2.113") {
            //     return v2_113::addresses;
            // }
        else {
            // return patterns::addresses;
        }
    }

    const std::unordered_map<std::string, Signature> &getSignaturesForVersion(const std::string &version) {
        if (version == "2.204") {
            return v2_204::signatures;
        }
            // else if (version == "2.203") {
            //     return v2_203::signatures;
            // }
            // else if (version == "2.202") {
            //     return v2_202::signatures;
            // }
            // else if (version == "2.201") {
            //     return v2_201::signatures;
            // }
            // else if (version == "2.200") {
            //     return v2_200::signatures;
            // }
            // else if (version == "2.113") {
            //     return v2_113::signatures;
            // }
        else {
            // return patterns::signatures;
        }
    }

}