#pragma once

#include <map>
#include <string>

namespace gd::maps::v2_204
{
    inline std::map<std::string, uintptr_t> addresses = {
        {"cocos2d::CCEGLView::m_fMouseX", 0xBC},
        {"cocos2d::CCEGLView::m_fMouseY", 0xC0},

        {"cocos2d::CCTexture2D::m_uName", 0x44},

        {"AppDelegate::applicationWillEnterForeground", 0x5B530},
        {"AppDelegate::applicationDidFinishLaunching", 0x5B320},
        {"AppDelegate::applicationDidEnterBackground", 0x5B4F0},
        {"AppDelegate::applicationWillBecomeActive", 0x5B4D0},
        {"AppDelegate::applicationWillBecomeActive", 0x5B4E0},
        {"AppDelegate::trySaveGame", 0x5B790},

        {"CCCircleWave::init", 0x232F0},
        {"CCCircleWave::draw", 0x23840},

        {"EditorPauseLayer::onExitEditor", 0xA2EF0},

        {"FMODAudioEngine::sharedEngine", 0x32bf0},
        {"FMODAudioEngine::m_system", 0x190},

        {"GameManager::sharedState", 0x121540},
        {"GameManager::getGameVariable", 0x128730},
        {"GameManager::setGameVariable", 0x1284E0},
        {"GameManager::m_customFPSTarget", 0x384},

        {"GameObject::m_objectID", 0x384},
        {"GameObject::m_startPosition", 0x340},

        {"GameStatsManager::isItemUnlocked", 0x176570},

        {"GJBaseGameLayer::init", 0x190290},
        {"GJBaseGameLayer::handleButton", 0x1B69F0},

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

        {"LevelEditorLayer::init", 0x239A70},

        {"MenuLayer::init", 0x27B450},

        {"PlayLayer::init", 0x2DC4A0},
        {"PlayLayer::update", 0x1BB780},
        {"PlayLayer::~PlayLayer", 0x2DC080},
        {"PlayLayer::resetLevel", 0x2EA130},
        {"PlayLayer::levelComplete", 0x2DDB60},
        {"PlayLayer::onQuit", 0x2EB480},
        {"PlayLayer::destroyPlayer", 0x2E6730},
        {"PlayLayer::addObject", 0x2E19B0},
        {"PlayLayer::destroyObject", 0x19CF50},
        {"PlayLayer::pickupCoin", 0x19D100},
        {"PlayLayer::setStartPosObject", 0x199E90},
        {"PlayLayer::startMusic", 0x2EB3A0},
        {"PlayLayer::resetLevelFromStart", 0x2EA090},
        {"PlayLayer::markCheckpoint", 0x2E8550},
        {"PlayLayer::togglePracticeMode", 0x2EAD30},
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
        // Cocos2d
        {"cocos2d::CCDirector::sharedDirector", "?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ"},
        {"cocos2d::CCDirector::getWinSize", "?getWinSize@CCDirector@cocos2d@@QAE?AVCCSize@2@XZ"},
        {"cocos2d::CCDirector::getOpenGLView", "?getOpenGLView@CCDirector@cocos2d@@QAEPAVCCEGLView@2@XZ"},
        {"cocos2d::CCDirector::getDeltaTime", "?getDeltaTime@CCDirector@cocos2d@@UAEMXZ"},

        {"cocos2d::CCEGLView::pollEvents", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ"},
        {"cocos2d::CCEGLView::swapBuffers", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ"},
        {"cocos2d::CCEGLView::toggleFullScreen", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N0@Z"},
        {"cocos2d::CCEGLView::getFrameSize", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N0@Z"},
        {"cocos2d::CCEGLView::getWindow", "?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ"},
        {"cocos2d::CCEGLView::sharedOpenGLView", "?sharedOpenGLView@CCEGLView@cocos2d@@SAPAV12@XZ"},
        {"cocos2d::CCEGLView::showCursor", "?showCursor@CCEGLView@cocos2d@@QAEX_N@Z"},

        {"cocos2d::ccGLBlendFunc", "?ccGLBlendFunc@cocos2d@@YAXII@Z"},
        {"cocos2d::ccGLBindTexture2D", "?ccGLBindTexture2D@cocos2d@@YAXI@Z"},

        {"cocos2d::CCGLProgram::use", "?use@CCGLProgram@cocos2d@@QAEXXZ"},
        {"cocos2d::CCGLProgram::setUniformsForBuiltins", "?setUniformsForBuiltins@CCGLProgram@cocos2d@@QAEXXZ"},

        {"cocos2d::CCScheduler::update", "?update@CCScheduler@cocos2d@@UAEXM@Z"},

        {"cocos2d::CCShaderCache::sharedShaderCache", "?sharedShaderCache@CCShaderCache@cocos2d@@SAPAV12@XZ"},
        {"cocos2d::CCShaderCache::programForKey", "?programForKey@CCShaderCache@cocos2d@@QAEPAVCCGLProgram@2@PBD@Z"},

        {"cocos2d::CCTexture2D::constructor", "??0CCTexture2D@cocos2d@@QAE@XZ"},
        {"cocos2d::CCTexture2D::initWithData", "?initWithData@CCTexture2D@cocos2d@@QAE_NPBXW4CCTexture2DPixelFormat@2@IIABVCCSize@2@@Z"},

        // FMOD
        {"FMOD::ChannelControl::setVolume", "?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z"},
    };
}
