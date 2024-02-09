#include "../utils/method.hpp"
#include "../utils/member.hpp"
#include "../gd.hpp"
#include "../mappings/maps.hpp"

#define INIT_MEMBER(type, member)                                                                \
private:                                                                                         \
    inline static utils::BindableMember<type> member##_bind;                                     \
                                                                                                 \
public:                                                                                          \
    inline type member() { return member##_bind.get(reinterpret_cast<void *>(this)); }           \
    inline void member(type value) { member##_bind.set(reinterpret_cast<void *>(this), value); } \
    inline static void init_##member(const char *name)                                           \
    {                                                                                            \
        if (gd::maps::addresses.find(name) == gd::maps::addresses.end())                         \
            return;                                                                              \
        member##_bind = utils::BindableMember<type>(gd::maps::addresses[name]);                  \
    }                                                                                            \
    inline type *member##_ptr() { return member##_bind.getPointer(reinterpret_cast<void *>(this)); }

#define INIT_METHOD(class, name, ...) \
    inline static gd::utils::BindableMethod<__VA_ARGS__> name = utils::BindableMethod<__VA_ARGS__>(#class "::" #name)

#define INIT_METHOD_IMPL(class, name, ...) \
    gd::utils::BindableMethod<__VA_ARGS__> class ::name = utils::BindableMethod<__VA_ARGS__>(#class "::" #name)

#define INIT_GMETHOD(name, ...) \
    extern gd::utils::BindableMethod<__VA_ARGS__> name

#define INIT_GMETHOD_IMPL(class, name, ...) \
    gd::utils::BindableMethod<__VA_ARGS__> name = utils::BindableMethod<__VA_ARGS__>(#class "::" #name)

// namespace gd
// {
//     template <typename T>
//     inline void initMember(utils::BindableMember<T> &member, const char *name)
//     {
//         if (gd::maps::addresses.find(name) == gd::maps::addresses.end())
//             return;

//         member = utils::BindableMember<T>(gd::maps::addresses[name]);
//     }
// }