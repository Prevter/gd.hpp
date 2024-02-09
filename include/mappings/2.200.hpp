#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_200
{
    inline std::map<std::string, uintptr_t> addresses = {
        // {"AppDelegate::applicationWillEnterForeground", 0x5B530},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"EditorPauseLayer::onExitEditor", 0xA23C0},

        {"GameManager::sharedState", 0x11f720},
        {"GameManager::getGameVariable", 0x126920},
        {"GameManager::setGameVariable", 0x1266d0},
        {"GameManager::m_customFPSTarget", 0x384},

        {"GameObject::m_objectID", 0x384},
        {"GameObject::m_startPosition", 0x340},

        {"GameStatsManager::isItemUnlocked", 0x173D10},

        {"GJBaseGameLayer::init", 0x18CC80},
        {"GJBaseGameLayer::handleButton", 0x1B2880},

        {"GJGameLevel::m_autoLevel", 0x308},
        {"GJGameLevel::m_demon", 0x2EC},
        {"GJGameLevel::m_demonDifficulty", 0x2F8},
        {"GJGameLevel::m_levelLength", 0x2CC},
        {"GJGameLevel::m_stars", 0x2FC},
        {"GJGameLevel::m_normalPercent", 0x29C},
        {"GJGameLevel::m_levelName", 0x118},
        {"GJGameLevel::m_levelID", 0x10C},
        {"GJGameLevel::m_objectCount", 0x224},
        {"GJGameLevel::m_creatorName", 0x160},
        {"GJGameLevel::m_difficulty", 0x210},
        {"GJGameLevel::m_ratingsSum", 0x238},

        {"LevelEditorLayer::init", 0x2349D0},

        {"MenuLayer::init", 0x276700},

        {"PlayLayer::init", 0x2d69a0},
        {"PlayLayer::update", 0x1B75E0},
        {"PlayLayer::~PlayLayer", 0x2D6580},
        {"PlayLayer::resetLevel", 0x2e42b0},
        {"PlayLayer::levelComplete", 0x2D7F30},
        {"PlayLayer::onQuit", 0x2e5650},
        {"PlayLayer::destroyPlayer", 0x2E0A90},
        {"PlayLayer::addObject", 0x2DBD30},
        {"PlayLayer::destroyObject", 0x198F70},
        {"PlayLayer::pickupCoin", 0x199120},
        {"PlayLayer::setStartPosObject", 0x195fc0},
        {"PlayLayer::startMusic", 0x2e5570},
        {"PlayLayer::resetLevelFromStart", 0x2e4210},
        {"PlayLayer::markCheckpoint", 0x2E2880},
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