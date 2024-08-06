#ifndef AP_TRAIT_FLOAT_HPP
#define AP_TRAIT_FLOAT_HPP

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

    struct f64_t;
    struct f32_t;
}

namespace ap::is::details                                           {
    template <typename T> struct float_t : std::false_type {};

    template <> struct float_t<ap::types::f32_t> : std::true_type {};
    template <> struct float_t<ap::types::f64_t> : std::true_type {};
}

namespace ap::is                                                      {
    template <typename T> concept float_t = details::float_t<T>::value;
}


#endif
