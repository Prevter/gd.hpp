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

#define INIT_MEMBER(type, member)                                                                \
private:                                                                                         \
    inline static utils::BindableMember<type> member##_bind;                                     \
    inline static void init_##member(const char *name) { initMember(member##_bind, name); }      \
                                                                                                 \
public:                                                                                          \
    inline type member() { return member##_bind.get(reinterpret_cast<void *>(this)); }           \
    inline void member(type value) { member##_bind.set(reinterpret_cast<void *>(this), value); } \
    inline type *member##_ptr() { return member##_bind.getPointer(reinterpret_cast<void *>(this)); }

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
        uintptr_t getOffset() const
        {
            return m_offset;
        }

        /// @brief Get address of the member
        /// @return Address of the member
        uintptr_t getAddress(void *parent) const
        {
            return reinterpret_cast<uintptr_t>(parent) + m_offset;
        }

        T *getPointer(void *parent) const
        {
            return reinterpret_cast<T *>(getAddress(parent));
        }

        T get(void *parent) const
        {
            return *getPointer(parent);
        }

        void set(void *parent, T value) const
        {
            *getPointer(parent) = value;
        }

        /// @brief Create bindable member
        /// @param offset Offset of the member
        BindableMember(uintptr_t offset)
            : m_offset(offset)
        {
        }

        BindableMember() = default;

    private:
        uintptr_t m_offset = 0;
    };
}