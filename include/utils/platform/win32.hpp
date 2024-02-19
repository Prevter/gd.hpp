// utils/platform/win32.hpp
// ~~~~~~~~~~~~~~~~
// Contains platform-specific includes for Windows.
// ~~~~~~~~~~~~~~~~

#pragma once

#include <string>
#include <map>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace gd::utils
{
    /// @brief Get the current version of the game.
    /// @return Current version of the game.
    inline std::string getVersion()
    {
        std::map<uint32_t, std::string> version_map = {
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

        HMODULE module = GetModuleHandleA(NULL);
        auto dos_header = (PIMAGE_DOS_HEADER)module;

        if (dos_header->e_magic != IMAGE_DOS_SIGNATURE)
        {
            return "Unknown";
        }

        auto nt_headers = (PIMAGE_NT_HEADERS)((uint8_t *)module + dos_header->e_lfanew);
        if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
        {
            return "Unknown";
        }

        uint32_t timestamp = nt_headers->FileHeader.TimeDateStamp;
        auto version = version_map.find(timestamp);
        if (version != version_map.end())
        {
            return version->second;
        }

        return "Unknown";
    }

    inline uint32_t findExport(uintptr_t base, const std::string &name)
    {
        return reinterpret_cast<uint32_t>(GetProcAddress(reinterpret_cast<HMODULE>(base), name.c_str()));
    }
}