#pragma once

#include "../internal.hpp"

#include <cstdint>
#include <string>
#include <unordered_map>

/// @brief Contains the mappings for version 2.204.
namespace gd::maps::v2_204 {
    inline std::unordered_map<std::string, uintptr_t> addresses = {
            {"cocos2d::CCEGLView::m_fMouseX",               0xBC},
            {"cocos2d::CCEGLView::m_fMouseY",               0xC0},

            {"cocos2d::CCTexture2D::m_uName",               0x44},

            {"AppDelegate::applicationWillEnterForeground", 0x5B530},
            {"AppDelegate::applicationDidFinishLaunching",  0x5B320},
            {"AppDelegate::applicationDidEnterBackground",  0x5B4F0},
            {"AppDelegate::applicationWillBecomeActive",    0x5B4D0},
            {"AppDelegate::applicationWillBecomeActive",    0x5B4E0},
            {"AppDelegate::trySaveGame",                    0x5B790},

            {"CCCircleWave::init",                          0x232F0},
            {"CCCircleWave::draw",                          0x23840},

            {"EditorPauseLayer::onExitEditor",              0xA2EF0},

            {"FMODAudioEngine::sharedEngine",               0x32bf0},
            {"FMODAudioEngine::m_system",                   0x190},

            {"GameManager::sharedState",                    0x121540},
            {"GameManager::getGameVariable",                0x128730},
            {"GameManager::setGameVariable",                0x1284E0},
            {"GameManager::updateCustomFPS",                0x12EC60},
            {"GameManager::m_customFPSTarget",              0x384},
            {"GameManager::m_playLayer",                    0x198},
            {"GameManager::m_levelEditorLayer",             0x19C},
            {"GameManager::m_gameLayer",                    0x1A0},
            {"GameManager::m_menuLayer",                    0x1A8},

            {"GameObject::m_objectID",                      0x384},
            {"GameObject::m_startPosition",                 0x340},

            {"GameStatsManager::isItemUnlocked",            0x176570},

            {"GJBaseGameLayer::init",                       0x190290},
            {"GJBaseGameLayer::handleButton",               0x1B69F0},

            {"GJGameLevel::m_autoLevel",                    0x30C},
            {"GJGameLevel::m_demon",                        0x2F0},
            {"GJGameLevel::m_demonDifficulty",              0x2FC},
            {"GJGameLevel::m_levelLength",                  0x2D0},
            {"GJGameLevel::m_stars",                        0x300},
            {"GJGameLevel::m_normalPercent",                0x2A0},
            {"GJGameLevel::m_levelName",                    0x118},
            {"GJGameLevel::m_levelID",                      0x10C},
            {"GJGameLevel::m_objectCount",                  0x224},
            {"GJGameLevel::m_creatorName",                  0x160},
            {"GJGameLevel::m_difficulty",                   0x210},
            {"GJGameLevel::m_ratingsSum",                   0x238},

            {"LevelEditorLayer::init",                      0x239A70},

            {"MenuLayer::init",                             0x27B450},

            {"PlayLayer::init",                             0x2DC4A0},
            {"PlayLayer::update",                           0x1BB780},
            {"PlayLayer::~PlayLayer",                       0x2DC080},
            {"PlayLayer::resetLevel",                       0x2EA130},
            {"PlayLayer::levelComplete",                    0x2DDB60},
            {"PlayLayer::onQuit",                           0x2EB480},
            {"PlayLayer::destroyPlayer",                    0x2E6730},
            {"PlayLayer::addObject",                        0x2E19B0},
            {"PlayLayer::destroyObject",                    0x19CF50},
            {"PlayLayer::pickupCoin",                       0x19D100},
            {"PlayLayer::setStartPosObject",                0x199E90},
            {"PlayLayer::startMusic",                       0x2EB3A0},
            {"PlayLayer::resetLevelFromStart",              0x2EA090},
            {"PlayLayer::markCheckpoint",                   0x2E8550},
            {"PlayLayer::togglePracticeMode",               0x2EAD30},
            {"PlayLayer::m_isPracticeMode",                 0x2A7C},
            {"PlayLayer::m_startPosCheckpoint",             0x2E14},
            {"PlayLayer::m_jumps",                          0x2EA4},
            {"PlayLayer::m_attempts",                       0x29AC},
            {"PlayLayer::m_isAlive",                        0x2DA0},
            {"PlayLayer::m_isDead",                         0x2AC0},
            {"PlayLayer::m_player1",                        0x878},
            {"PlayLayer::m_player2",                        0x87C},
            {"PlayLayer::m_level",                          0x5E0},
            {"PlayLayer::m_time",                           0x2EF0},
            {"PlayLayer::m_dualMode",                       0x36E},
            {"PlayLayer::m_hasCompleted",                   0x2C28},
    };

    inline std::unordered_map<std::string, Signature> signatures = {
            // Cocos2d
            {"cocos2d::CCApplication::sharedApplication",    CC_SYM("?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCApplication::toggleVerticalSync",   CC_SYM("?toggleVerticalSync@CCApplication@cocos2d@@QAEX_N@Z")},

            {"cocos2d::CCDirector::sharedDirector",          CC_SYM("?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCDirector::getWinSize",              CC_SYM("?getWinSize@CCDirector@cocos2d@@QAE?AVCCSize@2@XZ")},
            {"cocos2d::CCDirector::getOpenGLView",           CC_SYM("?getOpenGLView@CCDirector@cocos2d@@QAEPAVCCEGLView@2@XZ")},
            {"cocos2d::CCDirector::getDeltaTime",            CC_SYM("?getDeltaTime@CCDirector@cocos2d@@UAEMXZ")},

            {"cocos2d::CCEGLView::pollEvents",               CC_SYM("?pollEvents@CCEGLView@cocos2d@@QAEXXZ")},
            {"cocos2d::CCEGLView::swapBuffers",              CC_SYM("?swapBuffers@CCEGLView@cocos2d@@UAEXXZ")},
            {"cocos2d::CCEGLView::toggleFullScreen",         CC_SYM("?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N0@Z")},
            {"cocos2d::CCEGLView::getFrameSize",             CC_SYM("?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N0@Z")},
            {"cocos2d::CCEGLView::getWindow",                CC_SYM("?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ")},
            {"cocos2d::CCEGLView::sharedOpenGLView",         CC_SYM("?sharedOpenGLView@CCEGLView@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCEGLView::showCursor",               CC_SYM("?showCursor@CCEGLView@cocos2d@@QAEX_N@Z")},

            {"cocos2d::ccGLBlendFunc",                       CC_SYM("?ccGLBlendFunc@cocos2d@@YAXII@Z")},
            {"cocos2d::ccGLBindTexture2D",                   CC_SYM("?ccGLBindTexture2D@cocos2d@@YAXI@Z")},

            {"cocos2d::CCGLProgram::use",                    CC_SYM("?use@CCGLProgram@cocos2d@@QAEXXZ")},
            {"cocos2d::CCGLProgram::setUniformsForBuiltins", CC_SYM("?setUniformsForBuiltins@CCGLProgram@cocos2d@@QAEXXZ")},

            {"cocos2d::CCScheduler::update",                 CC_SYM("?update@CCScheduler@cocos2d@@UAEXM@Z")},

            {"cocos2d::CCShaderCache::sharedShaderCache",    CC_SYM("?sharedShaderCache@CCShaderCache@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCShaderCache::programForKey",        CC_SYM("?programForKey@CCShaderCache@cocos2d@@QAEPAVCCGLProgram@2@PBD@Z")},

            {"cocos2d::CCTexture2D::constructor",            CC_SYM("??0CCTexture2D@cocos2d@@QAE@XZ")},
            {"cocos2d::CCTexture2D::initWithData",           CC_SYM("?initWithData@CCTexture2D@cocos2d@@QAE_NPBXW4CCTexture2DPixelFormat@2@IIABVCCSize@2@@Z")},

            // FMOD
            {"FMOD::ChannelControl::setVolume",              FM_SYM("?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z")},
    };
}