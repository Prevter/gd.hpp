#include <gd.hpp>

namespace gd
{
    template <typename R, typename S, typename... Args>
    void initMethod(utils::BindableMethod<R, S, Args...> &method, const char *name, S hook)
    {
        if (maps::addresses.find(name) == maps::addresses.end())
        {
            printf("[gd.hpp] Failed to find address for %s\n", name);
        }

        method = utils::BindableMethod<R, S, Args...>(base + gd::maps::addresses[name], hook);
    }

    template <typename R, typename S, typename... Args>
    void initMethodSignature(utils::BindableMethod<R, S, Args...> &method, const char *name, S hook, uintptr_t base)
    {
        if (maps::signatures.find(name) == maps::signatures.end())
            return;

        auto address = utils::findExport(base, maps::signatures[name]);

        if (!address)
            return;

        method = utils::BindableMethod<R, S, Args...>(address, hook);
    }

    void init()
    {
        base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        cocosBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));
        fmodBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("fmod.dll"));

        gd::maps::init();

        /// cocos2d-x
        // CCEGLView
        initMethodSignature(cocos2d::CCEGLView::swapBuffers, "cocos2d::CCEGLView::swapBuffers", &hooks::CCEGLView_swapBuffers, cocosBase);
        initMethodSignature(cocos2d::CCEGLView::pollEvents, "cocos2d::CCEGLView::pollEvents", &hooks::CCEGLView_pollEvents, cocosBase);

        /// Geometry Dash
        // AppDelegate
        initMethod(AppDelegate::applicationWillEnterForeground, "AppDelegate::applicationWillEnterForeground", &hooks::AppDelegate_applicationWillEnterForeground);

        // CCCircleWave
        initMethod(CCCircleWave::init, "CCCircleWave::init", &hooks::CCCircleWave_init);
        initMethod(CCCircleWave::draw, "CCCircleWave::draw", &hooks::CCCircleWave_draw);

        // EditorPauseLayer
        initMethod(EditorPauseLayer::onExitEditor, "EditorPauseLayer::onExitEditor", &hooks::EditorPauseLayer_onExitEditor);

        // GameManager
        initMethod(GameManager::sharedState, "GameManager::sharedState", &hooks::GameManager_sharedState);
        initMethod(GameManager::getGameVariable, "GameManager::getGameVariable", &hooks::GameManager_getGameVariable);
        initMethod(GameManager::setGameVariable, "GameManager::setGameVariable", &hooks::GameManager_setGameVariable);
        GameManager::init_m_customFPSTarget("GameManager::m_customFPSTarget");

        // GameStatsManager
        initMethod(GameStatsManager::isItemUnlocked, "GameStatsManager::isItemUnlocked", &hooks::GameStatsManager_isItemUnlocked);

        // GJBaseGameLayer
        initMethod(GJBaseGameLayer::init, "GJBaseGameLayer::init", &hooks::GJBaseGameLayer_init);
        initMethod(GJBaseGameLayer::handleButton, "GJBaseGameLayer::handleButton", &hooks::GJBaseGameLayer_handleButton);

        // LevelEditorLayer
        initMethod(LevelEditorLayer::init, "LevelEditorLayer::init", &hooks::LevelEditorLayer_init);

        // MenuLayer
        initMethod(MenuLayer::init, "MenuLayer::init", &hooks::MenuLayer_init);

        // PlayLayer
        initMethod(PlayLayer::init, "PlayLayer::init", &hooks::PlayLayer_init);
        initMethod(PlayLayer::update, "PlayLayer::update", &hooks::PlayLayer_update);
        initMethod(PlayLayer::destructor, "PlayLayer::~PlayLayer", &hooks::PlayLayer_destructor);
        initMethod(PlayLayer::resetLevel, "PlayLayer::resetLevel", &hooks::PlayLayer_resetLevel);
        // initMethod(PlayLayer::levelComplete, "PlayLayer::levelComplete", &hooks::PlayLayer_levelComplete);
        initMethod(PlayLayer::onQuit, "PlayLayer::onQuit", &hooks::PlayLayer_onQuit);
        // initMethod(PlayLayer::destroyPlayer, "PlayLayer::destroyPlayer", &hooks::PlayLayer_destroyPlayer);
        initMethod(PlayLayer::addObject, "PlayLayer::addObject", &hooks::PlayLayer_addObject);
        initMethod(PlayLayer::destroyObject, "PlayLayer::destroyObject", &hooks::PlayLayer_destroyObject);
        initMethod(PlayLayer::pickupCoin, "PlayLayer::pickupCoin", &hooks::PlayLayer_pickupCoin);
        initMethod(PlayLayer::setStartPosObject, "PlayLayer::setStartPosObject", &hooks::PlayLayer_setStartPosObject);
        initMethod(PlayLayer::startMusic, "PlayLayer::startMusic", &hooks::PlayLayer_startMusic);
        initMethod(PlayLayer::resetLevelFromStart, "PlayLayer::resetLevelFromStart", &hooks::PlayLayer_resetLevelFromStart);
        // initMethod(PlayLayer::markCheckpoint, "PlayLayer::markCheckpoint", &hooks::PlayLayer_markCheckpoint);
        initMethod(PlayLayer::togglePracticeMode, "PlayLayer::togglePracticeMode", &hooks::PlayLayer_togglePracticeMode);
        PlayLayer::init_m_isPracticeMode("PlayLayer::m_isPracticeMode");
        PlayLayer::init_m_startPosCheckpoint("PlayLayer::m_startPosCheckpoint");
        PlayLayer::init_m_jumps("PlayLayer::m_jumps");
        PlayLayer::init_m_attempts("PlayLayer::m_attempts");
        PlayLayer::init_m_isAlive("PlayLayer::m_isAlive");
        PlayLayer::init_m_isDead("PlayLayer::m_isDead");
        PlayLayer::init_m_player1("PlayLayer::m_player1");
        PlayLayer::init_m_player2("PlayLayer::m_player2");
        PlayLayer::init_m_level("PlayLayer::m_level");
        PlayLayer::init_m_time("PlayLayer::m_time");
        PlayLayer::init_m_dualMode("PlayLayer::m_dualMode");
        PlayLayer::init_m_hasCompleted("PlayLayer::m_hasCompleted");
    }
}