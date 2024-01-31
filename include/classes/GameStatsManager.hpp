// classes/GameStatsManager.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GameStatsManager class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"

namespace gd
{
    class GameStatsManager : public BindableClassBase
    {
    public:
        inline static utils::BindableMethod<bool, bool(__fastcall *)(GameStatsManager *, int, int, int), GameStatsManager *, int, int> isItemUnlocked;
    };
}

namespace gd::hooks
{
    inline bool __fastcall GameStatsManager_isItemUnlocked(GameStatsManager *self, int, int itemType, int itemId)
    {
        if (!GameStatsManager::isItemUnlocked.isHooked())
            return GameStatsManager::isItemUnlocked(self, itemType, itemId);

        auto hook = GameStatsManager::isItemUnlocked.getHook();
        return hook(self, itemType, itemId);
    }
}
