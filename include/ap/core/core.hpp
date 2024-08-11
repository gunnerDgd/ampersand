#ifndef AP_CORE_CORE_HPP
#define AP_CORE_CORE_HPP

#include <ap/trait.hpp>

namespace ap::types {
    struct bool_t;

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

namespace ap                                 {
    template <opc C, typename... T> struct op;

    template <typename... T> class pack;
    template <typename... T> class var;
    template <typename... T> class fn;
}

namespace ap                                            {
    template <is::num_t T>  auto type(const ap::var<T>&);
    template <is::pack_t T> auto type(const ap::var<T>&);

    template <typename... T> auto name(const ap::pack<T...>&);
    template <typename... T> auto name(const ap::fn  <T...>&);
    template <is::pack_t T>  auto name(const ap::var<T>&);
    template <is::num_t T>   auto name(const ap::var<T>&);
    

    template <is::pack_t P, typename T>     auto self(const ap::var<ap::var<P>, ap::var<T>>&);
    template <std::size_t I, is::pack_t  T> auto sub (const ap::var<T>&);
    template <std::size_t I, typename... T> auto sub (const ap::pack<T...>&);
    template <std::size_t I, typename... T> auto arg (const ap::fn  <T...>&);
}

namespace ap                                                                                          {
   // For var<is::pack_T T>
    template <typename... P, is::pack_t T>                auto type(const ap::var<var<P...>, var<T>>&);
    template <typename... P, is::pack_t T>                auto name(const ap::var<var<P...>, var<T>>&);
    template <std::size_t I, typename... P, is::pack_t T> auto sub (const ap::var<var<P...>, var<T>>&);

    // For var<is::var_t T, is::var_t U>
    template <typename... P, typename T> auto self(const ap::var<ap::var<P...>, ap::var<T>>&);

    // For var<is::bool_t T>, var <is::int_t T> and var <is::float_t T>

    template <typename... P, is::bool_t T> auto name(const ap::var<var<P...>, var<T>>&);
    template <typename... P, is::num_t T>  auto name(const ap::var<var<P...>, var<T>>&);
    template <typename... P, is::bool_t T> auto type(const ap::var<var<P...>, var<T>>&);
    template <typename... P, is::num_t T>  auto type(const ap::var<var<P...>, var<T>>&);
}

namespace ap                                                {
    template <is::pack_t T1> auto type(const ap::var<T1[]>&);
    template <is::pack_t T1> auto name(const ap::var<T1[]>&);
    template <is::pack_t T1> auto len (const ap::var<T1[]>&);

    template <is::num_t T1> auto type(const ap::var<T1[]>&);
    template <is::num_t T1> auto name(const ap::var<T1[]>&);
    template <is::num_t T1> auto len (const ap::var<T1[]>&);
}

namespace ap                           {
    template <typename T> class boolean;
    template <typename T> class call;
    template <typename T> class move;

    template <typename T> class ari_eq;
    template <typename T> class bit_eq;
    template <typename T> class ari;
    template <typename T> class bit;
}

#endif
