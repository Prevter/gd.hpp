// classes/GJGameLevel.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for GJGameLevel class.
// ~~~~~~~~~~~~~~~~

#pragma once
#include "../utils/class.hpp"
#include "cocos/CCGeometry.hpp"
#include "../types/SeedValue.hpp"
#include <string>

namespace gd
{
    enum class GJDifficulty
    {
        Auto,
        Easy,
        Normal,
        Hard,
        Harder,
        Insane,
        Demon,
        DemonEasy,
        DemonMedium,
        DemonInsane,
        DemonExtreme
    };

    enum class GJLevelType
    {
        Local = 1,
        Editor,
        Saved
    };

    enum class GJLevelLength
    {
        Tiny,
        Short,
        Medium,
        Long,
        XL,
        Platformer
    };

    class GJGameLevel
    {
        INIT_MEMBER(bool, m_autoLevel)
        INIT_MEMBER(bool, m_demon)
        INIT_MEMBER(int, m_demonDifficulty)
        INIT_MEMBER(GJLevelLength, m_levelLength)
        INIT_MEMBER(int, m_stars)
        INIT_MEMBER(int, m_normalPercent)
        INIT_MEMBER(std::string, m_levelName)
        INIT_MEMBER(SeedValueRSV, m_levelID)
        INIT_MEMBER(SeedValueRSV, m_objectCount)
        INIT_MEMBER(std::string, m_creatorName)
        INIT_MEMBER(GJDifficulty, m_difficulty)
        INIT_MEMBER(int, m_ratingsSum)

    private:
        friend void init();
    };
}

namespace gd::hooks
{
}
