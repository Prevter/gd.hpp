#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_113
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"MenuLayer::init", 0x1907B0},

        {"PlayLayer::init", 0x1FB780},
        {"PlayLayer::update", 0x2029C0},
        {"PlayLayer::~PlayLayer", 0x1FAFC0},
        {"PlayLayer::resetLevel", 0x20BF00},
        {"PlayLayer::levelComplete", 0x1FD3D0},
        {"PlayLayer::onQuit", 0x20D810},
        {"PlayLayer::destroyPlayer", 0x20A1A0},
        {"PlayLayer::addObject", 0x2017E0},
        // {"PlayLayer::destroyObject", 0}, 
        // {"PlayLayer::pickupCoin", 0},
        // {"PlayLayer::setStartPosObject", 0}, // TODO: inline function
        {"PlayLayer::startMusic", 0x20C8F0},
        // {"PlayLayer::resetLevelFromStart", 0x2EA090}, 
        {"PlayLayer::markCheckpoint", 0x20B450},

        // {"LevelEditorLayer::init", 0x15EE00}, // TODO: fix changed params

        {"EditorPauseLayer::onExitEditor", 0x75660},

        {"GameManager::sharedState", 0xC4A50},
        {"GameManager::getGameVariable", 0xC9D30},
        {"GameManager::setGameVariable", 0xC9B50},

        {"GameStatsManager::isItemUnlocked", 0xFBB80},

        {"CCCircleWave::init", 0x16CD0},
        {"CCCircleWave::draw", 0x17100},

        // {"GJBaseGameLayer::init", 0x10B020},
        // {"GJBaseGameLayer::handleButton", 0x1B69F0},
    };

    inline std::map<std::string, std::string> signatures = {
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
    };
}