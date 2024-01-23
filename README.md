# gd.hpp
A Version-agnostic C++ library for Geometry Dash

> **Note:** This library is still in development and is not ready for use yet. Anything can change at any time.

## Features
- [x] Supports Geometry Dash from 2.113 all the way to latest versions.
- [x] Build once, run everywhere. No need to build for each game version.
- [x] Custom hooking system that makes it easy to implement new hooks.
- [ ] Allows all mods to hook into the same function without conflicts. (WIP)

## Usage
### Including the library
Library uses CMake to build, so you can just add it as a submodule to your project and use `add_subdirectory` to include it.
```cmake
add_subdirectory(libs/gd.hpp) # or wherever you put it
```
Then link it to your target.
```cmake
target_link_libraries(my_project PRIVATE gd.hpp)
```
### Using the library
Now you can use the library.
Here's a small example that shows a message box when main menu is loaded.
```cpp
#include <gd.hpp>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <MinHook.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        // Initialize minhook
        MH_Initialize();

        // Initialize gd.hpp
        gd::init();
        gd::setHookCreation([](void *target, void *detour, void **original)
                            { MH_CreateHook(target, detour, original); MH_EnableHook(target); });
        gd::setHookRemoval([](void *target)
                           { MH_DisableHook(target); MH_RemoveHook(target); });

        // Hook gd::MenuLayer::init
        gd::MenuLayer::init.hook(
            [](gd::MenuLayer *self)
            {
                MessageBoxA(nullptr, "Hello, Geometry Dash!", "My Mod", MB_OK);
                return gd::MenuLayer::init(self);
            });
    }
    return TRUE;
}
```

Compiling this will result in a DLL, that when injected into any version of Geometry Dash, will show a message box when main menu is loaded.