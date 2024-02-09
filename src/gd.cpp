#include <gd.hpp>
#include <utils/versions.hpp>

#define FIND_METHOD_SIGNATURE(name, hook, signature)                                    \
    if (maps::signatures.find(#name) == maps::signatures.end())                         \
    {                                                                                   \
        throw std::runtime_error("Failed to find signature for " + std::string(#name)); \
    }                                                                                   \
    uintptr_t address = utils::findExport(base, maps::signatures[#name]);               \
    if (!address)                                                                       \
    {                                                                                   \
        throw std::runtime_error("Failed to find address for " + std::string(#name));   \
    }

namespace gd
{
    template <typename R, typename S, typename... Args>
    void initMethod(utils::BindableMethod<R, S, Args...> &method, const char *name, S hook, gd::utils::MethodType type = gd::utils::MethodType::THISCALL)
    {
        if (maps::addresses.find(name) == maps::addresses.end())
        {
            printf("[gd.hpp] Failed to find address for %s\n", name);
            throw std::runtime_error("Failed to find address for " + std::string(name));
        }

        method.initialize(base + maps::addresses[name], hook, type, nullptr);
    }

    template <typename R, typename S, typename... Args>
    void initMethodSignature(
        utils::BindableMethod<R, S, Args...> &method,
        const char *name, S hook, uintptr_t base,
        gd::utils::MethodType type = gd::utils::MethodType::THISCALL,
        std::function<R(Args...)> override = nullptr)
    {
        if (maps::signatures.find(name) == maps::signatures.end())
        {
            printf("[gd.hpp] Failed to find signature for %s\n", name);
            throw std::runtime_error("Failed to find signature for " + std::string(name));
        }
        uintptr_t address = utils::findExport(base, maps::signatures[name]);
        if (!address)
        {
            printf("[gd.hpp] Failed to find address for %s\n", name);
            throw std::runtime_error("Failed to find address for " + std::string(name));
        }
        method.initialize(address, hook, type, override);
    }

    void init()
    {
        FILE *stream;
        freopen_s(&stream, "CONOUT$", "w", stdout);

        base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
        cocosBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));
        fmodBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("fmod.dll"));

        auto version = gd::utils::Version(gd::utils::getVersion());

        gd::maps::init();

        /// cocos2d-x
        // Global namespace
        initMethodSignature(cocos2d::ccGLBlendFunc, "cocos2d::ccGLBlendFunc", &hooks::ccGLBlendFunc, cocosBase, gd::utils::MethodType::CDECLCALL);
        initMethodSignature(cocos2d::ccGLBindTexture2D, "cocos2d::ccGLBindTexture2D", &hooks::ccGLBindTexture2D, cocosBase, gd::utils::MethodType::CDECLCALL);

        // CCEGLView
        initMethodSignature(cocos2d::CCEGLView::swapBuffers, "cocos2d::CCEGLView::swapBuffers", &hooks::CCEGLView_swapBuffers, cocosBase);
        initMethodSignature(cocos2d::CCEGLView::pollEvents, "cocos2d::CCEGLView::pollEvents", &hooks::CCEGLView_pollEvents, cocosBase);
        if (version >= "2.204")
        {
            initMethodSignature(cocos2d::CCEGLView::toggleFullScreen, "cocos2d::CCEGLView::toggleFullScreen", &hooks::CCEGLView_toggleFullScreen, cocosBase);
        }
        else
        {
            FIND_METHOD_SIGNATURE(
                cocos2d::CCEGLView::toggleFullScreen,
                &hooks::CCEGLView_toggleFullScreen_old,
                void(__thiscall *)(gd::cocos2d::CCEGLView *, int, bool, bool));

            cocos2d::CCEGLView::toggleFullScreen.initialize(
                address,
                reinterpret_cast<void(__fastcall *)(gd::cocos2d::CCEGLView *, int, bool, bool)>(&hooks::CCEGLView_toggleFullScreen_old),
                gd::utils::MethodType::THISCALL,
                [](cocos2d::CCEGLView *self, int fullscreen, bool borderless) -> void
                {
                    auto addr = gd::cocos2d::CCEGLView::toggleFullScreen.getCurrentAddress();
                    reinterpret_cast<void(__thiscall *)(gd::cocos2d::CCEGLView *, int, bool)>(addr)(self, fullscreen, borderless);
                });
        }

        // CCDirector
        initMethodSignature(cocos2d::CCDirector::sharedDirector, "cocos2d::CCDirector::sharedDirector", &hooks::CCDirector_sharedDirector, cocosBase, gd::utils::MethodType::CDECLCALL);
        initMethodSignature(cocos2d::CCDirector::getWinSize, "cocos2d::CCDirector::getWinSize", &hooks::CCDirector_getWinSize, cocosBase);
        initMethodSignature(cocos2d::CCDirector::getOpenGLView, "cocos2d::CCDirector::getOpenGLView", &hooks::CCDirector_getOpenGLView, cocosBase);
        initMethodSignature(cocos2d::CCDirector::getDeltaTime, "cocos2d::CCDirector::getDeltaTime", &hooks::CCDirector_getDeltaTime, cocosBase);

        /// Geometry Dash
        // AppDelegate
        initMethod(AppDelegate::applicationWillEnterForeground, "AppDelegate::applicationWillEnterForeground", &hooks::AppDelegate_applicationWillEnterForeground);

        // CCCircleWave
        initMethod(CCCircleWave::init, "CCCircleWave::init", &hooks::CCCircleWave_init);
        initMethod(CCCircleWave::draw, "CCCircleWave::draw", &hooks::CCCircleWave_draw);

        // EditorPauseLayer
        initMethod(EditorPauseLayer::onExitEditor, "EditorPauseLayer::onExitEditor", &hooks::EditorPauseLayer_onExitEditor);

        // GameManager
        initMethod(GameManager::sharedState, "GameManager::sharedState", &hooks::GameManager_sharedState, gd::utils::MethodType::STDCALL);
        initMethod(GameManager::getGameVariable, "GameManager::getGameVariable", &hooks::GameManager_getGameVariable);
        initMethod(GameManager::setGameVariable, "GameManager::setGameVariable", &hooks::GameManager_setGameVariable);
        GameManager::init_m_customFPSTarget("GameManager::m_customFPSTarget");

        // GameObject
        GameObject::init_m_objectID("GameObject::m_objectID");
        GameObject::init_m_startPosition("GameObject::m_startPosition");

        // GameStatsManager
        initMethod(GameStatsManager::isItemUnlocked, "GameStatsManager::isItemUnlocked", &hooks::GameStatsManager_isItemUnlocked);

        // GJBaseGameLayer
        initMethod(GJBaseGameLayer::init, "GJBaseGameLayer::init", &hooks::GJBaseGameLayer_init);
        initMethod(GJBaseGameLayer::handleButton, "GJBaseGameLayer::handleButton", &hooks::GJBaseGameLayer_handleButton);

        // GJGameLevel
        GJGameLevel::init_m_autoLevel("GJGameLevel::m_autoLevel");
        GJGameLevel::init_m_creatorName("GJGameLevel::m_creatorName");
        GJGameLevel::init_m_demon("GJGameLevel::m_demon");
        GJGameLevel::init_m_demonDifficulty("GJGameLevel::m_demonDifficulty");
        GJGameLevel::init_m_difficulty("GJGameLevel::m_difficulty");
        GJGameLevel::init_m_levelID("GJGameLevel::m_levelID");
        GJGameLevel::init_m_levelName("GJGameLevel::m_levelName");
        GJGameLevel::init_m_normalPercent("GJGameLevel::m_normalPercent");
        GJGameLevel::init_m_ratingsSum("GJGameLevel::m_ratingsSum");
        GJGameLevel::init_m_stars("GJGameLevel::m_stars");

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