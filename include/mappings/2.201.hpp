#pragma once

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
        {"PlayLayer::onQuit", 0x2e93c0},
        {"PlayLayer::destroyPlayer", 0x2E46C0},
        {"PlayLayer::addObject", 0x2df940},
        {"PlayLayer::destroyObject", 0x19bdc0},
        {"PlayLayer::pickupCoin", 0x19bf70},
        {"PlayLayer::setStartPosObject", 0x19bdc0},
        {"PlayLayer::startMusic", 0x2e92e0},
        {"PlayLayer::resetLevelFromStart", 0x2e7fd0},
        {"PlayLayer::markCheckpoint", 0x2E64B0},

        {"LevelEditorLayer::init", 0x238310},

        {"EditorPauseLayer::onExitEditor", 0xa2df0},

        {"GameManager::sharedState", 0x120860},
        {"GameManager::getGameVariable", 0x127a50},
        {"GameManager::setGameVariable", 0x127800},

        {"GameStatsManager::isItemUnlocked", 0x1754C0},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"GJBaseGameLayer::init", 0x18F040},
        {"GJBaseGameLayer::handleButton", 0x1B57E0},
    };

    inline std::map<std::string, std::string> signatures = {
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
    };
}