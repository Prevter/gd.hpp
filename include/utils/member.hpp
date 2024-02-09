// utils/member.hpp
// ~~~~~~~~~~~~~~~~
// Contains definition for BindableMember class, which
// is used to dynamically find/edit members of classes.
// ~~~~~~~~~~~~~~~~

#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>
#include <stdexcept>

namespace gd::utils
{
    /// @brief Bindable member class
    /// @tparam T Type of the member
    template <typename T>
    class BindableMember
    {
    public:
        /// @brief Get offset of the member
        /// @return Offset of the member
        inline uintptr_t getOffset() const noexcept
        {
            return m_offset;
        }

        /// @brief Get address of the member
        /// @return Address of the member
        inline uintptr_t getAddress(void *parent) const
        {
            if (m_offset == 0xFFFFFFFF)
            {
                throw std::runtime_error("Member not initialized");
            }

            return reinterpret_cast<uintptr_t>(parent) + m_offset;
        }

        inline T *getPointer(void *parent) const
        {
            return reinterpret_cast<T *>(getAddress(parent));
        }

        inline T get(void *parent) const
        {
            return *getPointer(parent);
        }

        inline void set(void *parent, T value) const
        {
            *getPointer(parent) = value;
        }

        /// @brief Create bindable member
        /// @param offset Offset of the member
        BindableMember(uintptr_t offset)
            : m_offset(offset)
        {
        }

        BindableMember()
        {
            m_offset = 0xFFFFFFFF;
        }

    private:
        uintptr_t m_offset = 0xFFFFFFFF;
    };
}