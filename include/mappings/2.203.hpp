#include <map>
#include <string>

namespace gd::maps::v2_203
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x27b2e0},

        {"PlayLayer::init", 0x2dbf30},
        {"PlayLayer::update", 0x1BB620},
        {"PlayLayer::~PlayLayer", 0x2DBB10},
        {"PlayLayer::resetLevel", 0x2e9b40},
        {"PlayLayer::levelComplete", 0x2DD590},
        {"PlayLayer::onExit", 0x2eae90},
        {"PlayLayer::death", 0x2E6160},
        {"PlayLayer::addObject", 0x2e13d0},
        {"PlayLayer::destroyObject", 0x19ce40},
        {"PlayLayer::pickupCoin", 0x19cff0},
        {"PlayLayer::setStartPosObject", 0x199da0},
        {"PlayLayer::startMusic", 0x2eadb0},
        {"PlayLayer::removeAllCheckpoints", 0x2e9aa0},

        {"LevelEditorLayer::init", 0x239900},
        {"LevelEditorLayer::onExit", 0xa2ec0},

        {"GameManager::sharedState", 0x121530},
        {"GameManager::getGameVariable", 0x128720},
        {"GameManager::setGameVariable", 0x1284d0},

        {"GameStatsManager::isItemUnlocked", 0x176570},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"UILayer::onCheck", 0x2E7F60},

        {"GJBaseGameLayer::init", 0x190290},
        {"GJBaseGameLayer::handleInput", 0x1B68C0},
    };
}