#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_113
{
    inline std::map<std::string, uintptr_t> addresses = {
        // {"AppDelegate::applicationWillEnterForeground", 0x5B530},

        {"CCCircleWave::init", 0x16CD0},
        {"CCCircleWave::draw", 0x17100},

        {"EditorPauseLayer::onExitEditor", 0x75660},

        {"GameManager::sharedState", 0xC4A50},
        {"GameManager::getGameVariable", 0xC9D30},
        {"GameManager::setGameVariable", 0xC9B50},
        // {"GameManager::m_customFPSTarget", 0x384},

        {"GameObject::m_objectID", 0x384},
        {"GameObject::m_startPosition", 0x340},

        {"GameStatsManager::isItemUnlocked", 0xFBB80},

        // {"GJBaseGameLayer::init", 0x18F210},
        // {"GJBaseGameLayer::handleButton", 0x1B59A0},

        {"GJGameLevel::m_autoLevel", 0x30C},
        {"GJGameLevel::m_demon", 0x2F0},
        {"GJGameLevel::m_demonDifficulty", 0x2FC},
        {"GJGameLevel::m_levelLength", 0x2D0},
        {"GJGameLevel::m_stars", 0x300},
        {"GJGameLevel::m_normalPercent", 0x2A0},
        {"GJGameLevel::m_levelName", 0x118},
        {"GJGameLevel::m_levelID", 0x10C},
        {"GJGameLevel::m_objectCount", 0x224},
        {"GJGameLevel::m_creatorName", 0x160},
        {"GJGameLevel::m_difficulty", 0x210},
        {"GJGameLevel::m_ratingsSum", 0x238},

        // {"LevelEditorLayer::init", 0x15EE00}, // TODO: fix changed params

        {"MenuLayer::init", 0x1907B0},

        {"PlayLayer::init", 0x1FB780},
        {"PlayLayer::update", 0x2029C0},
        {"PlayLayer::~PlayLayer", 0x1FAFC0},
        {"PlayLayer::resetLevel", 0x20BF00},
        {"PlayLayer::levelComplete", 0x1FD3D0},
        {"PlayLayer::onQuit", 0x20D810},
        {"PlayLayer::destroyPlayer", 0x20A1A0},
        {"PlayLayer::addObject", 0x2017E0},
        // {"PlayLayer::destroyObject", 0x19bf90},
        // {"PlayLayer::pickupCoin", 0x19c140},
        // {"PlayLayer::setStartPosObject", 0}, // TODO: inline function
        {"PlayLayer::startMusic", 0x20C8F0},
        // {"PlayLayer::resetLevelFromStart", 0x2e8160},
        {"PlayLayer::markCheckpoint", 0x20B450},
        // {"PlayLayer::togglePracticeMode", 0x2EAD30},
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
    };

    inline std::map<std::string, std::string> signatures = {
        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::toggleFullScreen", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z"},
    };
}