#pragma once

#include "signature.hpp"

#include <cstdint>
#include <string>
#include <unordered_map>

/// @brief Contains the mappings for version 2.204.
namespace gd::maps::v2_204 {
    inline std::unordered_map<std::string, uintptr_t> addresses = {
            {"cocos2d::CCEGLView::m_fMouseX",               0xBC},
            {"cocos2d::CCEGLView::m_fMouseY",               0xC0},

            {"cocos2d::CCTexture2D::m_uName",               0x44},

            {"cocos2d::CCDirector::m_runningScene",         0xcc},

            {"AppDelegate::applicationWillEnterForeground", 0x5B530},
            {"AppDelegate::applicationDidFinishLaunching",  0x5B320},
            {"AppDelegate::applicationDidEnterBackground",  0x5B4F0},
            {"AppDelegate::applicationWillBecomeActive",    0x5B4D0},
            {"AppDelegate::applicationWillResignActive",    0x5B4E0},
            {"AppDelegate::trySaveGame",                    0x5B790},

            {"CCCircleWave::init",                          0x232F0},
            {"CCCircleWave::draw",                          0x23840},

            {"EditorPauseLayer::onExitEditor",              0xA2EF0},

            {"FMODAudioEngine::sharedEngine",               0x32bf0},
            {"FMODAudioEngine::m_system",                   0x190},

            {"GameLevelManager::sharedState",               0xf3a00},
            {"GameLevelManager::saveLevel",                 0xf8130},

            {"GameManager::sharedState",                    0x121540},
            {"GameManager::getGameVariable",                0x128730},
            {"GameManager::setGameVariable",                0x1284E0},
            {"GameManager::updateCustomFPS",                0x12EC60},
            {"GameManager::m_customFPSTarget",              0x384},
            {"GameManager::m_playLayer",                    0x198},
            {"GameManager::m_levelEditorLayer",             0x19C},
            {"GameManager::m_gameLayer",                    0x1A0},
            {"GameManager::m_menuLayer",                    0x1A8},
            {"GameManager::m_playerName",                   0x1D0},

            {"GameObject::getObjectRect",                   0x13A570},
            {"GameObject::m_objectID",                      0x384},
            {"GameObject::m_startPosition",                 0x340},

            {"GameStatsManager::sharedState",               0x167d90},
            {"GameStatsManager::isItemUnlocked",            0x176570},
            {"GameStatsManager::uncompleteLevel",           0x170400},
            {"GameStatsManager::m_verifiedUserCoins",       0x1D8},

            {"GJDropDownLayer::showLayer",                  0x1D6B70},

            {"GJBaseGameLayer::init",                       0x190290},
            {"GJBaseGameLayer::update",                     0x1BB780},
            {"GJBaseGameLayer::destroyObject",              0x19CF50},
            {"GJBaseGameLayer::pickupItem",                 0x19D100},
            {"GJBaseGameLayer::setStartPosObject",          0x199E90},
            {"GJBaseGameLayer::resetCamera",                0x1C22B0},
            {"GJBaseGameLayer::handleButton",               0x1B69F0},
            {"GJBaseGameLayer::processCommands",            0x1BD240},
            {"GJBaseGameLayer::m_isPracticeMode",           0x2A7C},
            {"GJBaseGameLayer::m_startPosCheckpoint",       0x2E14},
            {"GJBaseGameLayer::m_jumps",                    0x2EA4},
            {"GJBaseGameLayer::m_attempts",                 0x29AC},
            {"GJBaseGameLayer::m_isAlive",                  0x2DA0},
            {"GJBaseGameLayer::m_isDead",                   0x2AC0},
            {"GJBaseGameLayer::m_player1",                  0x878},
            {"GJBaseGameLayer::m_player2",                  0x87C},
            {"GJBaseGameLayer::m_level",                    0x5E0},
            {"GJBaseGameLayer::m_time",                     0x2EF0},
            {"GJBaseGameLayer::m_dualMode",                 0x36E},
            {"GJBaseGameLayer::m_hasCompleted",             0x2C28},
            {"GJBaseGameLayer::m_gameState",                0x148},
            {"GJBaseGameLayer::m_objects",                  0x884},
            {"GJBaseGameLayer::m_dTime",                    0x328},
            {"GJBaseGameLayer::m_isFlipped",                0x36e},
            {"GJBaseGameLayer::m_isTestMode",               0x2AAC},

            {"GJGameLevel::getCoinKey",                     0x114220},
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
            {"GJGameLevel::m_timestamp",                    0x414},
            {"GJGameLevel::m_bestTime",                     0x450},
            {"GJGameLevel::m_practicePercent",              0x2C4},
            {"GJGameLevel::m_newNormalPercent2",            0x2B8},
            {"GJGameLevel::m_orbCompletion",                0x2AC},
            {"GJGameLevel::m_54",                           0x44C},
            {"GJGameLevel::m_k111",                         0x458},
            {"GJGameLevel::m_bestPoints",                   0x454},
            {"GJGameLevel::m_coins",                        0x310},

            {"GJGameState::m_cameraScale",                  0x0},
            {"GJGameState::m_targetCameraScale",            0x4},
            {"GJGameState::m_cameraAngle",                  0x17C},
            {"GJGameState::m_targetCameraAngle",            0x180},
            {"GJGameState::m_stepSpeed",                    0x1F8},
            {"GJGameState::m_cameraPosition",               0x214},

            {"LevelSettingsObject::m_resetCamera",          0x16B},

            {"LevelEditorLayer::init",                      0x239A70},

            {"MenuGameLayer::update",                       0x279c60},
            {"MenuGameLayer::tryJump",                      0x2799A0},
            {"MenuGameLayer::m_playerObject",               0x154},

            {"MenuLayer::init",                             0x27B450},

            {"OptionsLayer::create",                        0x2B01C0},

            {"PlayerObject::pushButton",                    0x2d1d30},
            {"PlayerObject::releaseButton",                 0x2d1f70},
            {"PlayerObject::flipGravity",                   0x2d36e0},
            {"PlayerObject::m_position",                    0x854},
            {"PlayerObject::m_yAccel",                      0x790},
            {"PlayerObject::m_xAccel",                      0x630},
            {"PlayerObject::m_playerSpeed",                 0x7E4},
            {"PlayerObject::m_playerSize",                  0x7E0},
            {"PlayerObject::m_isShip",                      0x7A9},
            {"PlayerObject::m_isBird",                      0x7AA},
            {"PlayerObject::m_isBall",                      0x7AB},
            {"PlayerObject::m_isDart",                      0x7AC},
            {"PlayerObject::m_isRobot",                     0x7AD},
            {"PlayerObject::m_isSpider",                    0x7AE},
            {"PlayerObject::m_isJetpack",                   0x920},
            {"PlayerObject::m_isSwing",                     0x7B4},
            {"PlayerObject::m_isHolding",                   0x775},
            {"PlayerObject::m_isSliding",                   0x7FC},
            {"PlayerObject::m_iconSpriteSecondary",         0x5f0},
            {"PlayerObject::m_isUpsideDown",                0x7AF},
            {"PlayerObject::m_isDead",                      0x7b0},

            {"PlayLayer::init",                             0x2DC4A0},
            {"PlayLayer::~PlayLayer",                       0x2DC080},
            {"PlayLayer::resetLevel",                       0x2EA130},
            {"PlayLayer::levelComplete",                    0x2DDB60},
            {"PlayLayer::onQuit",                           0x2EB480},
            {"PlayLayer::destroyPlayer",                    0x2E6730},
            {"PlayLayer::addObject",                        0x2E19B0},
            {"PlayLayer::startMusic",                       0x2EB3A0},
            {"PlayLayer::resetLevelFromStart",              0x2EA090},
            {"PlayLayer::markCheckpoint",                   0x2E8550},
            {"PlayLayer::togglePracticeMode",               0x2EAD30},
            {"PlayLayer::playEndAnimationToPos",            0x2dfe00},
            {"PlayLayer::playPlatformerEndAnimationToPos",  0x2e05e0},
            {"PlayLayer::getCurrentPercentInt",             0x2e6680},
            {"PlayLayer::postUpdate",                       0x2E7220},
            {"PlayLayer::updateDebugDraw",                  0x1986F0},
            {"PlayLayer::m_debugDrawNode",                  0x2d70},

            {"StartPosObject::m_levelSettings",             0x678},
    };

    inline std::unordered_map<std::string, Signature> signatures = {
            // Cocos2d
            {"cocos2d::CCApplication::sharedApplication",    CC_SYM("?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCApplication::toggleVerticalSync",   CC_SYM("?toggleVerticalSync@CCApplication@cocos2d@@QAEX_N@Z")},

            {"cocos2d::CCArray::count",                      CC_SYM("?count@CCArray@cocos2d@@QBEIXZ")},

            {"cocos2d::CCDictionary::removeObjectForKey",    CC_SYM("?removeObjectForKey@CCDictionary@cocos2d@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z")},

            {"cocos2d::CCDirector::sharedDirector",          CC_SYM("?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCDirector::getWinSize",              CC_SYM("?getWinSize@CCDirector@cocos2d@@QAE?AVCCSize@2@XZ")},
            {"cocos2d::CCDirector::getOpenGLView",           CC_SYM("?getOpenGLView@CCDirector@cocos2d@@QAEPAVCCEGLView@2@XZ")},
            {"cocos2d::CCDirector::getDeltaTime",            CC_SYM("?getDeltaTime@CCDirector@cocos2d@@UAEMXZ")},

            {"cocos2d::CCDrawNode::clear",                   CC_SYM("?clear@CCDrawNode@cocos2d@@QAEXXZ")},
            {"cocos2d::CCDrawNode::drawPolygon",             CC_SYM("?drawPolygon@CCDrawNode@cocos2d@@QAE_NPAVCCPoint@2@IABU_ccColor4F@2@M1@Z")},

            {"cocos2d::CCEGLView::pollEvents",               CC_SYM("?pollEvents@CCEGLView@cocos2d@@QAEXXZ")},
            {"cocos2d::CCEGLView::swapBuffers",              CC_SYM("?swapBuffers@CCEGLView@cocos2d@@UAEXXZ")},
            {"cocos2d::CCEGLView::toggleFullScreen",         CC_SYM("?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N0@Z")},
            {"cocos2d::CCEGLView::getWindow",                CC_SYM("?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ")},
            {"cocos2d::CCEGLView::sharedOpenGLView",         CC_SYM("?sharedOpenGLView@CCEGLView@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCEGLView::showCursor",               CC_SYM("?showCursor@CCEGLView@cocos2d@@QAEX_N@Z")},

            {"cocos2d::ccGLBlendFunc",                       CC_SYM("?ccGLBlendFunc@cocos2d@@YAXII@Z")},
            {"cocos2d::ccGLBindTexture2D",                   CC_SYM("?ccGLBindTexture2D@cocos2d@@YAXI@Z")},

            {"cocos2d::CCGLProgram::use",                    CC_SYM("?use@CCGLProgram@cocos2d@@QAEXXZ")},
            {"cocos2d::CCGLProgram::setUniformsForBuiltins", CC_SYM("?setUniformsForBuiltins@CCGLProgram@cocos2d@@QAEXXZ")},

            {"cocos2d::CCLabelBMFont::create",               CC_SYM("?create@CCLabelBMFont@cocos2d@@SAPAV12@PBD0@Z")},
            {"cocos2d::CCLabelBMFont::setCString",           CC_SYM("?setCString@CCLabelBMFont@cocos2d@@UAEXPBD@Z")},
            {"cocos2d::CCLabelBMFont::setAlignment",         CC_SYM("?setAlignment@CCLabelBMFont@cocos2d@@UAEXW4CCTextAlignment@2@@Z")},
            {"cocos2d::CCLabelBMFont::setScale",             CC_SYM("?setScale@CCLabelBMFont@cocos2d@@UAEXM@Z")},
            {"cocos2d::CCLabelBMFont::setAnchorPoint",       CC_SYM("?setAnchorPoint@CCLabelBMFont@cocos2d@@UAEXABVCCPoint@2@@Z")},

            {"cocos2d::CCNode::addChild",                    CC_SYM("?addChild@CCNode@cocos2d@@UAEXPAV12@@Z")},
            {"cocos2d::CCNode::removeChild",                 CC_SYM("?removeChild@CCNode@cocos2d@@UAEXPAV12@@Z")},
            {"cocos2d::CCNode::setZOrder",                   CC_SYM("?setZOrder@CCNode@cocos2d@@UAEXH@Z")},
            {"cocos2d::CCNode::setPosition",                 CC_SYM("?setPosition@CCNode@cocos2d@@UAEXABVCCPoint@2@@Z")},
            {"cocos2d::CCNode::setVisible",                  CC_SYM("?setVisible@CCNode@cocos2d@@UAEX_N@Z")},

            {"cocos2d::CCScheduler::update",                 CC_SYM("?update@CCScheduler@cocos2d@@UAEXM@Z")},

            {"cocos2d::CCShaderCache::sharedShaderCache",    CC_SYM("?sharedShaderCache@CCShaderCache@cocos2d@@SAPAV12@XZ")},
            {"cocos2d::CCShaderCache::programForKey",        CC_SYM("?programForKey@CCShaderCache@cocos2d@@QAEPAVCCGLProgram@2@PBD@Z")},

            {"cocos2d::CCTexture2D::constructor",            CC_SYM("??0CCTexture2D@cocos2d@@QAE@XZ")},
            {"cocos2d::CCTexture2D::initWithData",           CC_SYM("?initWithData@CCTexture2D@cocos2d@@QAE_NPBXW4CCTexture2DPixelFormat@2@IIABVCCSize@2@@Z")},

            // FMOD
            {"FMOD::ChannelControl::setVolume",              FM_SYM("?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z")},
    };
}