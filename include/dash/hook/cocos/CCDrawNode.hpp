#pragma once

#include "../hook.hpp"
#include "../../bindings/cocos/CCDrawNode.hpp"

namespace gd::hook::CCDrawNode {

    // CCDrawNode::drawPolygon

    inline static uintptr_t drawPolygon_addr = 0x0;
    inline static std::function<bool (cocos2d::CCDrawNode *, cocos2d::CCPoint *, unsigned int, const cocos2d::_ccColor4F &, float, const cocos2d::ccColor4F &)> drawPolygon_hook;

    /// @brief Calls the original CCDrawNode::drawPolygon function.
    inline static bool drawPolygon(cocos2d::CCDrawNode *self, cocos2d::CCPoint *vertex, unsigned int count, const cocos2d::_ccColor4F &fillColor, float borderWidth, const cocos2d::ccColor4F &borderColor) {
        return reinterpret_cast<bool (__thiscall *)(cocos2d::CCDrawNode *, cocos2d::CCPoint *, unsigned int, const cocos2d::_ccColor4F &, float, const cocos2d::ccColor4F &)>(drawPolygon_addr)(self, vertex, count, fillColor, borderWidth, borderColor);
    }

    /// @brief Wrapper for the CCDrawNode::drawPolygon hook.
    inline bool __fastcall drawPolygonHook(cocos2d::CCDrawNode *self, int, cocos2d::CCPoint *vertex, unsigned int count, const cocos2d::_ccColor4F &fillColor, float borderWidth, const cocos2d::ccColor4F &borderColor) {
        return drawPolygon_hook(self, vertex, count, fillColor, borderWidth, borderColor);
    }

    /// @brief Installs the hook for CCDrawNode::drawPolygon.
    SETUP_HOOK_SIG("cocos2d::CCDrawNode::drawPolygon", bool, drawPolygon, cocos2d::CCDrawNode *, cocos2d::CCPoint *, unsigned int, const cocos2d::_ccColor4F &, float, const cocos2d::ccColor4F &)

    // CCDrawNode::drawCircle

    inline static uintptr_t drawCircle_addr = 0x0;
    inline static std::function<bool (cocos2d::CCDrawNode *, cocos2d::CCPoint const &, float, cocos2d::_ccColor4F const &, float, cocos2d::_ccColor4F const &, unsigned int)> drawCircle_hook;

    /// @brief Calls the original CCDrawNode::drawCircle function.
    inline static bool drawCircle(cocos2d::CCDrawNode *self, cocos2d::CCPoint const &position, float radius, cocos2d::_ccColor4F const &color, float borderWidth, cocos2d::_ccColor4F const &borderColor, unsigned int segments) {
        return reinterpret_cast<bool (__thiscall *)(cocos2d::CCDrawNode *, cocos2d::CCPoint const &, float, cocos2d::_ccColor4F const &, float, cocos2d::_ccColor4F const &, unsigned int)>(drawCircle_addr)(self, position, radius, color, borderWidth, borderColor, segments);
    }

    /// @brief Wrapper for the CCDrawNode::drawCircle hook.
    inline bool __fastcall drawCircleHook(cocos2d::CCDrawNode *self, int, cocos2d::CCPoint const &position, float radius, cocos2d::_ccColor4F const &color, float borderWidth, cocos2d::_ccColor4F const &borderColor, unsigned int segments) {
        return drawCircle_hook(self, position, radius, color, borderWidth, borderColor, segments);
    }

    /// @brief Installs the hook for CCDrawNode::drawCircle.
    SETUP_HOOK_SIG("cocos2d::CCDrawNode::drawCircle", bool, drawCircle, cocos2d::CCDrawNode *, cocos2d::CCPoint const &, float, cocos2d::_ccColor4F const &, float, cocos2d::_ccColor4F const &, unsigned int)
}