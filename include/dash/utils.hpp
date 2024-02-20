#pragma once

#include <cstdint>
#include <string>

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

namespace gd::utils {
    /// @brief Find the address of a symbol in a module.
    /// @param module The name of the module.
    /// @param symbol The name of the symbol.
    /// @return The address of the symbol or nullptr if it was not found.
    inline uintptr_t findSymbol(const char *symbol, const char *module) {
        auto moduleHandle = GetModuleHandleA(module);
        if (!moduleHandle) {
            return 0;
        }

        auto symbolAddress = reinterpret_cast<uintptr_t>(GetProcAddress(moduleHandle, symbol));
        if (!symbolAddress) {
            return 0;
        }

        return symbolAddress;
    }

    inline uintptr_t getByOffset(uintptr_t offset, const char *module) {
        auto moduleHandle = GetModuleHandleA(module);
        if (!moduleHandle) {
            return 0;
        }

        return reinterpret_cast<uintptr_t>(moduleHandle) + offset;
    }
}