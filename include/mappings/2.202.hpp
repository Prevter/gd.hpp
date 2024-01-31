#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_202
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x279df0},

        {"PlayLayer::init", 0x2da660},
        {"PlayLayer::update", 0x1BA700},
        {"PlayLayer::~PlayLayer", 0x2DA240},
        {"PlayLayer::resetLevel", 0x2e8200},
        {"PlayLayer::levelComplete", 0x2DBC80},
        {"PlayLayer::onQuit", 0x2e9550},
        {"PlayLayer::destroyPlayer", 0x2E4840},
        {"PlayLayer::addObject", 0x2dfab0},
        {"PlayLayer::destroyObject", 0x19bf90},
        {"PlayLayer::pickupCoin", 0x19c140},
        {"PlayLayer::setStartPosObject", 0x198e10},
        {"PlayLayer::startMusic", 0x2e9470},
        {"PlayLayer::resetLevelFromStart", 0x2e8160},
        {"PlayLayer::markCheckpoint", 0x2E6630},

        {"LevelEditorLayer::init", 0x238460},

        {"EditorPauseLayer::onExitEditor", 0xa2df0},

        {"GameManager::sharedState", 0x120860},
        {"GameManager::getGameVariable", 0x127a50},
        {"GameManager::setGameVariable", 0x127800},

        {"GameStatsManager::isItemUnlocked", 0x1756A0},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"GJBaseGameLayer::init", 0x18F210},
        {"GJBaseGameLayer::handleButton", 0x1B59A0},
    };

    inline std::map<std::string, std::string> signatures = {
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
    };
}