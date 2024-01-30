# gd.hpp
A version-agnostic C++ library for Geometry Dash

Supported versions: **2.113** - **2.204**+

> **Note:** This library is still in development and does not have all features implemented yet. If you're going to use it, please make sure to update it regularly.

## Features
- [x] Supports Geometry Dash from 2.113 all the way to latest versions.
- [x] Build once, run everywhere. No need to build for each game version.
- [x] Custom hooking system that makes it easy to implement new hooks.
- [ ] In case the game updates, it will try to find the new addresses automatically.

## TODO
- [ ] Add more hooks/members.
- [ ] Add more examples.
- [ ] Create a wiki.
- [ ] Make hooking system more robust.
- [ ] Add support for more versions.

## Usage
### Including the library
Library uses CMake to build, so you can just add it as a submodule to your project and use `add_subdirectory` to include it.
```cmake
add_subdirectory(libs/gd.hpp) # or wherever you put it
```
Make sure to set the C++ standard to at least C++17.
```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```
Then link it to your target.
```cmake
target_link_libraries(my_project PRIVATE gd.hpp)
```
### Using the library
Now you can use the library.
Here's a small example that unlocks "Practice Music Sync":
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

        gd::GameStatsManager::isItemUnlocked.hook(
            [](gd::GameStatsManager *self, int itemType, int itemId)
            {
                // Unlock "Practice Music Sync"
                if (itemType == 12 && itemId == 17)
                    return true;

                // Call original function
                return gd::GameStatsManager::isItemUnlocked(self, itemType, itemId);
            });
    }
    return TRUE;
}
```

Compiling this will result in a DLL, that when injected into any version of Geometry Dash, will unlock "Practice Music Sync" option in the pause settings.