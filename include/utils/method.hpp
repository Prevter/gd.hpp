// utils/method.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for BindableMethod class, which
// is used to create hooks for methods of classes with dynamic
// type.
// ~~~~~~~~~~~~~~~~

#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

namespace gd::utils
{
    enum class HookResult
    {
        SUCCESS,
        ADDRESS_NULL,
        HOOK_ADDRESS_NULL,
        ALREADY_HOOKED
    };

    enum class UnhookResult
    {
        SUCCESS,
        ADDRESS_NULL,
        NOT_HOOKED
    };

    enum class MethodType
    {
        THISCALL,
        FASTCALL,
        STDCALL,
        CDECLCALL
    };

    /// @brief Create hook
    /// @param target Target address
    /// @param hook Hook address
    /// @param original Original address
    inline std::function<void(void *, void *, void **)> CreateHook = nullptr;

    /// @brief Remove hook
    /// @param target Target address
    inline std::function<void(void *)> RemoveHook = nullptr;

    /// @brief Bindable method class
    /// @tparam R Return type of the method
    /// @tparam S Signature for the hook method
    /// @tparam Args Arguments of the original method
    template <typename R, typename S, typename... Args>
    class BindableMethod
    {
    public:
        /// @brief Get original method address
        /// @return Original method address
        uintptr_t getAddress() const
        {
            return m_originalAddress;
        }

        /// @brief Get address to trampoline method
        /// @return Address to trampoline method
        uintptr_t getCurrentAddress() const
        {
            return m_currentAddress;
        }

        /// @brief Get hook method
        /// @return Hook method
        std::function<R(Args...)> &getHook()
        {
            return m_hook;
        }

        /// @brief Create a new hook for the method
        /// @param hook Hook method
        /// @return Hook result
        HookResult hook(R (*hook)(Args...))
        {
            if (m_hooked)
                return HookResult::ALREADY_HOOKED;

            if (m_originalAddress == 0)
                return HookResult::ADDRESS_NULL;

            if (m_hookedMethod == nullptr)
                return HookResult::HOOK_ADDRESS_NULL;

            m_currentAddress = m_originalAddress;

            CreateHook(
                (void *)m_originalAddress,
                (void *)m_hookedMethod,
                (void **)&m_currentAddress);

            m_hooked = true;

            m_hook = hook;
            return HookResult::SUCCESS;
        }

        /// @brief Remove hook from the method
        /// @return True if hook was removed, false otherwise
        UnhookResult unhook()
        {
            if (!m_hooked)
                return UnhookResult::NOT_HOOKED;

            if (m_originalAddress == 0)
                return UnhookResult::ADDRESS_NULL;

            RemoveHook((void *)m_originalAddress);

            m_hooked = false;

            return UnhookResult::SUCCESS;
        }

        /// @brief Check if the method is hooked
        /// @return True if the method is hooked, false otherwise
        bool isHooked() const
        {
            return m_hooked;
        }

        /// @brief Call the original method
        /// @param args Arguments of the original method
        /// @return Return value of the original method
        R call(Args... args)
        {
            if (m_override)
                return m_override(args...);

            switch (m_type)
            {
            case MethodType::FASTCALL:
                return reinterpret_cast<R(__fastcall *)(Args...)>(m_currentAddress)(args...);
            case MethodType::STDCALL:
                return reinterpret_cast<R(__stdcall *)(Args...)>(m_currentAddress)(args...);
            case MethodType::CDECLCALL:
                return reinterpret_cast<R(__cdecl *)(Args...)>(m_currentAddress)(args...);
            default:
                return reinterpret_cast<R(__thiscall *)(Args...)>(m_currentAddress)(args...);
            }
        }

        /// @brief Call the original method
        /// @param args Arguments of the original method
        /// @return Return value of the original method
        R operator()(Args... args)
        {
            return call(args...);
        }

        /// @brief Construct a new BindableMethod object
        /// @param address Address of the method
        /// @param hook Hook method
        BindableMethod(uintptr_t address, S hook, MethodType type = MethodType::THISCALL, std::function<R(Args...)> override = nullptr)
            : m_originalAddress(address), m_currentAddress(address), m_hookedMethod(hook), m_type(type), m_override(override)
        {
        }

        /// @brief Default empty constructor
        BindableMethod() = default;

    private:
        uintptr_t m_currentAddress, m_originalAddress;
        bool m_hooked = false;
        std::function<R(Args...)> m_hook;
        S m_hookedMethod = nullptr;
        std::function<R(Args...)> m_override;
        MethodType m_type;
    };
}
