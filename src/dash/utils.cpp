#include <dash/utils.hpp>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace gd::utils {
    uintptr_t findSymbol(const std::string &module, const std::string &symbol) {
        auto moduleHandle = GetModuleHandleA(module.c_str());
        if (!moduleHandle) {
            return 0;
        }

        auto symbolAddress = reinterpret_cast<uintptr_t>(GetProcAddress(moduleHandle, symbol.c_str()));
        if (!symbolAddress) {
            return 0;
        }

        return symbolAddress;
    }
}