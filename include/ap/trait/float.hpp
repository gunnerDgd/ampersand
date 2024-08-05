#ifndef AP_TRAIT_FLOAT_HPP
#define AP_TRAIT_FLOAT_HPP

#include <type_traits>

namespace ap    {
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

namespace ap::is::details                                                        {
    template <typename T> struct float_t { static constexpr bool value = false; };

    template <> struct float_t<ap::f32_t> { static constexpr bool value = true; };
    template <> struct float_t<ap::f64_t> { static constexpr bool value = true; };
}

namespace ap::is                                                      {
    template <typename T> concept float_t = details::float_t<T>::value;
}

namespace std                                                                       {
    template <> struct common_type<ap::f64_t, ap::u64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::u32_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::u16_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::u8_t>  { using type = ap::f64_t; };

    template <> struct common_type<ap::f64_t, ap::i64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::i32_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::i16_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::i8_t>  { using type = ap::f64_t; };

    template <> struct common_type<ap::f64_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::f64_t, ap::f32_t> { using type = ap::f64_t; };


    template <> struct common_type<ap::f32_t, ap::u64_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::u32_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::u16_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::u8_t>  { using type = ap::f32_t; };

    template <> struct common_type<ap::f32_t, ap::i64_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::i32_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::i16_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::i8_t>  { using type = ap::f32_t; };

    template <> struct common_type<ap::f32_t, ap::f32_t> { using type = ap::f32_t; };
    template <> struct common_type<ap::f32_t, ap::f64_t> { using type = ap::f64_t; };
}

#endif
