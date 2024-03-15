#pragma once

#define SETUP_HOOK(signature, returnType, name, ...) \
inline static HookResult name(                           \
        const std::function<returnType(__VA_ARGS__)> &hook,      \
        const std::function<void(void *, void *, void **)> &createHook) {\
    auto address = findOffset(signature);\
    if (address > 0x80000000) return {nullptr, Status::ADDRESS_NULL};\
    name##_hook = hook;\
    createHook(reinterpret_cast<void *>(address),\
               reinterpret_cast<void *>(&name##Hook),\
               reinterpret_cast<void **>(&name##_addr)); \
    return {reinterpret_cast<void *>(name##_addr), Status::OK};\
}

#define SETUP_HOOK_SIG(signature, returnType, name, ...) \
inline static HookResult name(                           \
        const std::function<returnType(__VA_ARGS__)> &hook,      \
        const std::function<void(void *, void *, void **)> &createHook) {\
    auto address = findSignature(signature);\
    if (address > 0x80000000) return {nullptr, Status::ADDRESS_NULL};\
    name##_hook = hook;\
    createHook(reinterpret_cast<void *>(address),\
               reinterpret_cast<void *>(&name##Hook),\
               reinterpret_cast<void **>(&name##_addr)); \
    return {reinterpret_cast<void *>(name##_addr), Status::OK};\
}

#include <functional>
#include <utility>

#include "../internal.hpp"

namespace gd::hook {
    enum class Status {
        OK,
        ADDRESS_NULL
    };

    struct HookResult {
        void *address;
        Status status;
    };
}