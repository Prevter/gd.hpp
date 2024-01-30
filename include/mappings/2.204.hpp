#include <map>
#include <string>

namespace gd::maps::v2_204
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x27B450},

        {"PlayLayer::init", 0x2DC4A0},
        {"PlayLayer::update", 0x1BB780},
        {"PlayLayer::~PlayLayer", 0x2DC080},
        {"PlayLayer::resetLevel", 0x2EA130},
        {"PlayLayer::levelComplete", 0x2DDB60},
        {"PlayLayer::onExit", 0x2EB480},
        {"PlayLayer::death", 0x2E6730},
        {"PlayLayer::addObject", 0x2E19B0},
        {"PlayLayer::destroyObject", 0x19CF50},
        {"PlayLayer::pickupCoin", 0x19D100},
        {"PlayLayer::setStartPosObject", 0x199E90},
        {"PlayLayer::startMusic", 0x2EB3A0},
        {"PlayLayer::removeAllCheckpoints", 0x2EA090},
        {"PlayLayer::m_isPracticeMode", 0x2A7C},
        {"PlayLayer::m_startPosCheckpoint", 0x2E14},
        {"PlayLayer::m_jumps", 0x2EA4},
        {"PlayLayer::m_attempts", 0x29AC},
        {"PlayLayer::m_isAlive", 0x2DA0},
        {"PlayLayer::m_isDead", 0x2AC0},
        {"PlayLayer::m_player1", 0x878},
        {"PlayLayer::m_player2", 0x87C},
        {"PlayLayer::m_level", 0x5E0},
        {"PlayLayer::m_time", 0x2EF0},
        {"PlayLayer::m_dualMode", 0x36E},
        {"PlayLayer::m_hasCompleted", 0x2C28},

        {"LevelEditorLayer::init", 0x239A70},
        {"LevelEditorLayer::onExit", 0xA2EF0},

        {"GameManager::sharedState", 0x121540},
        {"GameManager::getGameVariable", 0x128730},
        {"GameManager::setGameVariable", 0x1284E0},
        {"GameManager::m_customFPSTarget", 0x384},

        {"GameStatsManager::isItemUnlocked", 0x176570},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"UILayer::onCheck", 0x2E8550},

        {"GJBaseGameLayer::init", 0x190290},
        {"GJBaseGameLayer::handleInput", 0x1B69F0},
    };
}