#pragma once

#include "../internal.hpp"
#include "../special/SeedValue.hpp"

namespace gd {
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

    class GJGameLevel {
    public:
        SETUP_MEMBER(bool, m_autoLevel, "GJGameLevel::m_autoLevel")
        SETUP_MEMBER(bool, m_demon, "GJGameLevel::m_demon")
        SETUP_MEMBER(int, m_demonDifficulty, "GJGameLevel::m_demonDifficulty")
        SETUP_MEMBER(GJLevelLength, m_levelLength, "GJGameLevel::m_levelLength")
        SETUP_MEMBER(int, m_stars, "GJGameLevel::m_stars")
        SETUP_MEMBER(int, m_normalPercent, "GJGameLevel::m_normalPercent")
        SETUP_MEMBER(std::string, m_levelName, "GJGameLevel::m_levelName")
        SETUP_MEMBER(SeedValueRSV, m_levelID, "GJGameLevel::m_levelID")
        SETUP_MEMBER(SeedValueRSV, m_objectCount, "GJGameLevel::m_objectCount")
        SETUP_MEMBER(std::string, m_creatorName, "GJGameLevel::m_creatorName")
        SETUP_MEMBER(GJDifficulty, m_difficulty, "GJGameLevel::m_difficulty")
        SETUP_MEMBER(int, m_ratingsSum, "GJGameLevel::m_ratingsSum")
        SETUP_MEMBER(float, m_timestamp, "GJGameLevel::m_timestamp")
    };
}