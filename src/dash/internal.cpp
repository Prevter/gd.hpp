#include <dash/internal.hpp>
#include <dash/mappings.hpp>
#include <dash/utils.hpp>

#include <unordered_map>
#include <string>
#include <map>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace gd {

    std::unordered_map<std::string, uintptr_t> addressCache;
    std::string gameVersion;

    uintptr_t findOffset(const std::string &name){
        if (addressCache.find(name) != addressCache.end())
            return addressCache[name];

        const auto& version = getVersion();
        auto versionMap = gd::maps::getForVersion(version);

        // if the version is not found, return 0
        if (versionMap.find(name) == versionMap.end())
            return 0;

        auto address = versionMap.at(name);
        addressCache[name] = address;
        return address;
    }

    uintptr_t findSignature(const std::string &name) {
        if (addressCache.find(name) != addressCache.end())
            return addressCache[name];

        const auto& version = getVersion();
        auto versionMap = gd::maps::getSignaturesForVersion(version);

        // if the version is not found, return 0
        if (versionMap.find(name) == versionMap.end())
            return 0;

        auto signature = versionMap.at(name);
        auto address = gd::utils::findSymbol(signature.module, signature.symbol);
        addressCache[name] = address;
        return address;
    }

    const std::string &getVersion() {
        if (!gameVersion.empty())
            return gameVersion;

        std::map<uint32_t, std::string> versionMap = {
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
        auto dos_header = (PIMAGE_DOS_HEADER)module;

        if (dos_header->e_magic != IMAGE_DOS_SIGNATURE)
        {
            gameVersion = "unknown";
            return gameVersion;
        }

        auto nt_headers = (PIMAGE_NT_HEADERS)((uint8_t *)module + dos_header->e_lfanew);
        if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
        {
            gameVersion = "unknown";
            return gameVersion;
        }

        uint32_t timestamp = nt_headers->FileHeader.TimeDateStamp;
        auto version = versionMap.find(timestamp);
        if (version != versionMap.end())
        {
            gameVersion = version->second;
            return gameVersion;
        }

        gameVersion = "unknown";
        return gameVersion;
    }
}