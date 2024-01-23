#include <map>
#include <string>

namespace gd::maps::v2_200
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x276700},

        {"PlayLayer::init", 0x2d69a0},
        {"PlayLayer::update", 0x1B75E0},
        {"PlayLayer::~PlayLayer", 0x2D6580},
        {"PlayLayer::resetLevel", 0x2e42b0},
        {"PlayLayer::levelComplete", 0x2D7F30},
        {"PlayLayer::onExit", 0x2e5650},
        {"PlayLayer::death", 0x2E0A90},
        {"PlayLayer::addObject", 0x2DBD30},
        {"PlayLayer::destroyObject", 0x198F70},
        {"PlayLayer::pickupCoin", 0x199120},
        {"PlayLayer::setStartPosObject", 0x195fc0},
        {"PlayLayer::startMusic", 0x2e5570},
        {"PlayLayer::removeAllCheckpoints", 0x2e4210},

        {"LevelEditorLayer::init", 0x2349D0},
        {"LevelEditorLayer::onExit", 0xA23C0},

        {"GameManager::sharedState", 0x11f720},
        {"GameManager::getGameVariable", 0x126920},
        {"GameManager::setGameVariable", 0x1266d0},

        {"GameStatsManager::isItemUnlocked", 0x173D10},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"UILayer::onCheck", 0x2E2880},

        {"GJBaseGameLayer::init", 0x18CC80},
        {"GJBaseGameLayer::handleInput", 0x1B2880},
    };
}