#include <map>
#include <string>

namespace gd::maps::v2_201
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x279ca0},

        {"PlayLayer::init", 0x2da4d0},
        {"PlayLayer::update", 0x1BA540},
        {"PlayLayer::~PlayLayer", 0x2DA0B0},
        {"PlayLayer::resetLevel", 0x2e8070},
        {"PlayLayer::levelComplete", 0x2DBAE0},
        {"PlayLayer::onExit", 0x2e93c0},
        {"PlayLayer::death", 0x2E46C0},
        {"PlayLayer::addObject", 0x2df940},
        {"PlayLayer::destroyObject", 0x19bdc0},
        {"PlayLayer::pickupCoin", 0x19bf70},
        {"PlayLayer::setStartPosObject", 0x19bdc0},
        {"PlayLayer::startMusic", 0x2e92e0},
        {"PlayLayer::removeAllCheckpoints", 0x2e7fd0},

        {"LevelEditorLayer::init", 0x238310},
        {"LevelEditorLayer::onExit", 0xa2df0},

        {"GameManager::sharedState", 0x120860},
        {"GameManager::getGameVariable", 0x127a50},
        {"GameManager::setGameVariable", 0x127800},

        {"GameStatsManager::isItemUnlocked", 0x1754C0},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"UILayer::onCheck", 0x2E64B0},

        {"GJBaseGameLayer::init", 0x18F040},
        {"GJBaseGameLayer::handleInput", 0x1B57E0},
    };
}