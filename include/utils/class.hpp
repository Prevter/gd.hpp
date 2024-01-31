#pragma once
#include "../gd.hpp"
#include "../utils/method.hpp"
#include "../utils/member.hpp"

namespace gd
{
    template <typename T>
    inline void initMember(utils::BindableMember<T> &member, const char *name)
    {
        if (maps::addresses.find(name) == maps::addresses.end())
            return;

        member = utils::BindableMember<T>(gd::maps::addresses[name]);
    }

    class BindableClassBase
    {
    };
}