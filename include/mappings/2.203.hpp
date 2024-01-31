#pragma once

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
        {"PlayLayer::onQuit", 0x2eae90},
        {"PlayLayer::destroyPlayer", 0x2E6160},
        {"PlayLayer::addObject", 0x2e13d0},
        {"PlayLayer::destroyObject", 0x19ce40},
        {"PlayLayer::pickupCoin", 0x19cff0},
        {"PlayLayer::setStartPosObject", 0x199da0},
        {"PlayLayer::startMusic", 0x2eadb0},
        {"PlayLayer::resetLevelFromStart", 0x2e9aa0},
        {"PlayLayer::markCheckpoint", 0x2E7F60},

        {"LevelEditorLayer::init", 0x239900},

        {"EditorPauseLayer::onExitEditor", 0xA2EC0},

        {"GameManager::sharedState", 0x121530},
        {"GameManager::getGameVariable", 0x128720},
        {"GameManager::setGameVariable", 0x1284d0},

        {"GameStatsManager::isItemUnlocked", 0x176570},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"GJBaseGameLayer::init", 0x190290},
        {"GJBaseGameLayer::handleButton", 0x1B68C0},
    };

    inline std::map<std::string, std::string> signatures = {
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
    };
}