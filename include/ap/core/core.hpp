#ifndef AP_CORE_CORE_HPP
#define AP_CORE_CORE_HPP

#include <ap/trait.hpp>

namespace ap        {
    struct boolean_t;

    struct f64_t;
    struct f32_t;

    struct i64_t;
    struct u64_t;

    struct i32_t;
    struct u32_t;

    struct i16_t;
    struct u16_t;

    struct i8_t;
    struct u8_t;
}

namespace ap                                {
    template <opc C, typename... T> class op;

    template <typename... T> class pack;
    template <typename... T> class var;
}

namespace ap                                            {
    template <is::num_t T>  auto type(const ap::var<T>&);
    template <is::pack_t T> auto type(const ap::var<T>&);

    template <typename... T> auto name(const ap::pack<T...>&);
    template <is::pack_t T>  auto name(const ap::var<T>&);
    template <is::num_t T>   auto name(const ap::var<T>&);
    

    template <is::pack_t P, typename T>     auto self(const ap::var<ap::var<P>, ap::var<T>>&);
    template <std::size_t I, is::pack_t  T> auto sub (const ap::var<T>&);
    template <std::size_t I, typename... T> auto sub (const ap::pack<T...>&);
}

namespace ap                          {
    template <typename T> class ari_eq;
    template <typename T> class bit_eq;
    template <typename T> class ari;
    template <typename T> class bit;
}

#endif
