#pragma once

#include "../../internal.hpp"

namespace gd::cocos2d {
    class CCDictionary {
    public:
        inline void removeObjectForKey(const std::string& key) {
            SETUP_METHOD(void, "cocos2d::CCDictionary::removeObjectForKey", __thiscall, CCDictionary*, const std::string&);
            method(this, key);
        }
    };
}