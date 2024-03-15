#pragma once

#include "mappings.hpp"
#include "utils.hpp"

#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>

#define SETUP_METHOD(returnType, symbol, callingConvention, ...) \
    auto offset = ::gd::findOffset(symbol);                   \
    if (offset == 0x8086FFFF)                                               \
        throw std::runtime_error("Failed to find " symbol " offset."); \
    auto method = reinterpret_cast<returnType(callingConvention *)(__VA_ARGS__)>(offset)

#define SETUP_METHOD_SIG(returnType, symbol, callingConvention, ...) \
    auto offset = ::gd::findSignature(symbol);                   \
    if (offset == 0x8086FFFF)                                               \
        throw std::runtime_error("Failed to find " symbol " offset."); \
    auto method = reinterpret_cast<returnType(callingConvention *)(__VA_ARGS__)>(offset)

#define SETUP_MEMBER(type, name, symbol) \
    inline type &name() {                 \
        auto offset = ::gd::getOffset(symbol); \
        if (offset == 0x8086FFFF)                       \
            throw std::runtime_error("Failed to find " symbol " offset."); \
        return *reinterpret_cast<type *>(this + offset); \
    }                                    \
    inline void name(type value) {          \
        auto offset = ::gd::getOffset(symbol); \
        if (offset == 0x8086FFFF)                       \
            throw std::runtime_error("Failed to find " symbol " offset."); \
        *reinterpret_cast<type *>(this + offset) = value; \
    }


namespace gd {

    inline std::unordered_map<std::string, uintptr_t> addressCache;


    /// @brief Get the current version of the game.
    /// @return The version of the game.
    inline const std::string &getVersion() {
        static std::map<uint32_t, std::string> versionMap = {
                {0,          "unknown"},
                {1419173053, "1.900"},
                {1419880840, "1.910"},
                {1421745341, "1.920"},
                {1440638199, "2.000"},
                {1440643927, "2.001"},
                {1443053232, "2.010"},
                {1443077847, "2.011"},
                {1443077847, "2.020"},
                {1484612867, "2.100"},
                {1484626658, "2.101"},
                {1484737207, "2.102"},
                {1510526914, "2.110"},
                {1510538091, "2.111"},
                {1510619253, "2.112"},
                {1511220108, "2.113"},
                {1702921605, "2.200"},
                {1704582672, "2.201"},
                {1704601266, "2.202"},
                {1704948277, "2.203"},
                {1705041028, "2.204"},
        };

        HMODULE module = GetModuleHandleA(nullptr);
        auto dos_header = (PIMAGE_DOS_HEADER) module;

        if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
            return versionMap[0];
        }

        auto nt_headers = (PIMAGE_NT_HEADERS) ((uint8_t *) module + dos_header->e_lfanew);
        if (nt_headers->Signature != IMAGE_NT_SIGNATURE) {
            return versionMap[0];
        }

        uint32_t timestamp = nt_headers->FileHeader.TimeDateStamp;
        auto version = versionMap.find(timestamp);
        if (version != versionMap.end()) {
            return version->second;
        }

        return versionMap[0];
    }

    inline uintptr_t getOffset(const std::string &name) {
        if (addressCache.find(name) != addressCache.end())
            return addressCache[name];

        const auto &version = getVersion();
        auto versionMap = gd::maps::getForVersion(version);

        // if the version is not found, return INTPTR_MAX
        if (versionMap.find(name) == versionMap.end())
            return INTPTR_MAX;

        auto offset = versionMap.at(name);
        addressCache[name] = offset;
        return offset;
    }

    /// @brief Find current offset for a given symbol.
    /// @param name The name of the symbol. (e.g. "PlayLayer::resetLevel")
    /// @return The offset of the symbol.
    inline uintptr_t findOffset(const std::string &name, const char *module = nullptr) {
        if (addressCache.find(name) != addressCache.end())
            return addressCache.at(name);

        auto offset = getOffset(name);
        auto address = gd::utils::getByOffset(offset, module);
        addressCache[name] = address;
        return address;
    }

    /// @brief Find current offset for a given signature.
    /// @param name The name of the symbol. (e.g. "cocos2d::CCDirector::sharedDirector")
    /// @return The offset of the symbol.
    inline uintptr_t findSignature(const std::string &name) {
        if (addressCache.find(name) != addressCache.end())
            return addressCache.at(name);

        const auto &version = getVersion();
        auto versionMap = gd::maps::getSignaturesForVersion(version);

        // if the version is not found, return INTPTR_MAX
        if (versionMap.find(name) == versionMap.end())
            return INTPTR_MAX;

        auto signature = versionMap.at(name);
        auto address = gd::utils::findSymbol(signature.symbol, signature.module);
        addressCache[name] = address;
        return address;
    }

    /// @brief Helper class for version comparison. (Version("2.204") <= "2.205")
    class Version {
    public:
        explicit Version(const std::string &version) {
            auto parts = split(version);
            if (parts.size() != 2)
                throw std::runtime_error("Invalid version format.");

            major = std::stoi(parts[0]);
            minor = std::stoi(parts[1]);
        }

        inline bool operator>=(const Version &other) const {
            return major > other.major || (major == other.major && minor >= other.minor);
        }

        inline bool operator<=(const Version &other) const {
            return major < other.major || (major == other.major && minor <= other.minor);
        }

        inline bool operator>(const Version &other) const {
            return major > other.major || (major == other.major && minor > other.minor);
        }

        inline bool operator<(const Version &other) const {
            return major < other.major || (major == other.major && minor < other.minor);
        }

        inline bool operator==(const Version &other) const {
            return major == other.major && minor == other.minor;
        }

        inline bool operator!=(const Version &other) const {
            return major != other.major || minor != other.minor;
        }

        [[nodiscard]] inline std::string str() const {
            return std::to_string(major) + "." + std::to_string(minor);
        }

        // Comparison operators for std::string
        inline bool operator>=(const std::string &other) const {
            return *this >= Version(other);
        }

        inline bool operator<=(const std::string &other) const {
            return *this <= Version(other);
        }

        inline bool operator>(const std::string &other) const {
            return *this > Version(other);
        }

        inline bool operator<(const std::string &other) const {
            return *this < Version(other);
        }

        inline bool operator==(const std::string &other) const {
            return *this == Version(other);
        }

        inline bool operator!=(const std::string &other) const {
            return *this != Version(other);
        }

    private:
        inline static std::vector<std::string> split(const std::string &s) {
            std::vector<std::string> parts;
            std::string part;
            std::istringstream stream(s);
            while (std::getline(stream, part, '.')) {
                parts.push_back(part);
            }
            return parts;
        }

        int major;
        int minor;
    };

}