#ifndef AP_TRAIT_INT_HPP
#define AP_TRAIT_INT_HPP

#include <type_traits>

namespace ap::types {
    struct i64_t;
    struct u64_t;

    struct i32_t;
    struct u32_t;

    struct i16_t;
    struct u16_t;

    struct i8_t;
    struct u8_t;

    struct f32_t;
    struct f64_t;
}

namespace ap::is::details                                         {
    template <typename T> struct int_t : std::false_type {};

    template <> struct int_t<ap::types::i8_t>  : std::true_type {};
    template <> struct int_t<ap::types::i16_t> : std::true_type {};
    template <> struct int_t<ap::types::i32_t> : std::true_type {};
    template <> struct int_t<ap::types::i64_t> : std::true_type {};

    template <> struct int_t<ap::types::u8_t>  : std::true_type {};
    template <> struct int_t<ap::types::u16_t> : std::true_type {};
    template <> struct int_t<ap::types::u32_t> : std::true_type {};
    template <> struct int_t<ap::types::u64_t> : std::true_type {};
}

namespace ap::is                                                  {
    template <typename T> concept int_t = details::int_t<T>::value;
}

#endif
