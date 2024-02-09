#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_201
{
    inline std::map<std::string, uintptr_t> addresses = {
        // {"AppDelegate::applicationWillEnterForeground", 0x5B530},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"EditorPauseLayer::onExitEditor", 0xa2df0},

        {"GameManager::sharedState", 0x120860},
        {"GameManager::getGameVariable", 0x127a50},
        {"GameManager::setGameVariable", 0x127800},
        {"GameManager::m_customFPSTarget", 0x384},

        {"GameObject::m_objectID", 0x384},
        {"GameObject::m_startPosition", 0x340},

        {"GameStatsManager::isItemUnlocked", 0x1754C0},

        {"GJBaseGameLayer::init", 0x18F040},
        {"GJBaseGameLayer::handleButton", 0x1B57E0},

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

        {"LevelEditorLayer::init", 0x238310},

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
        {"PlayLayer::togglePracticeMode", 0x2e8c70},
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
        {"cocos2d::CCDirector::sharedDirector", "?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ"},
        {"cocos2d::CCDirector::getWinSize", "?getWinSize@CCDirector@cocos2d@@QAE?AVCCSize@2@XZ"},
        {"cocos2d::CCDirector::getOpenGLView", "?getOpenGLView@CCDirector@cocos2d@@QAEPAVCCEGLView@2@XZ"},
        {"cocos2d::CCDirector::getDeltaTime", "?getDeltaTime@CCDirector@cocos2d@@UAEMXZ"},

        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::toggleFullScreen", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z"},

        {"cocos2d::ccGLBlendFunc", "?ccGLBlendFunc@cocos2d@@YAXII@Z"},
        {"cocos2d::ccGLBindTexture2D", "?ccGLBindTexture2D@cocos2d@@YAXI@Z"},
    };
}