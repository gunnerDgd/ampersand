#ifndef AP_TRAIT_INT_HPP
#define AP_TRAIT_INT_HPP

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

    struct f32_t;
    struct f64_t;
}

namespace ap::is::details                                                       {
    template <typename T> struct int_t  { static constexpr bool value = false; };

    template <> struct int_t<ap::i8_t>  { static constexpr bool value = true; };
    template <> struct int_t<ap::i16_t> { static constexpr bool value = true; };
    template <> struct int_t<ap::i32_t> { static constexpr bool value = true; };
    template <> struct int_t<ap::i64_t> { static constexpr bool value = true; };

    template <> struct int_t<ap::u8_t>  { static constexpr bool value = true; };
    template <> struct int_t<ap::u16_t> { static constexpr bool value = true; };
    template <> struct int_t<ap::u32_t> { static constexpr bool value = true; };
    template <> struct int_t<ap::u64_t> { static constexpr bool value = true; };
}

namespace ap::is                                                  {
    template <typename T> concept int_t = details::int_t<T>::value;
}

namespace std                                                                       {
    template <> struct common_type<ap::i64_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::i64_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::i64_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i64_t, ap::i32_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i64_t, ap::i16_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i64_t, ap::i8_t>  { using type = ap::i64_t; };

    template <> struct common_type<ap::i64_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::i64_t, ap::u32_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i64_t, ap::u16_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i64_t, ap::u8_t>  { using type = ap::i64_t; };


    template <> struct common_type<ap::i32_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::i32_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::i32_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i32_t, ap::i32_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::i32_t, ap::i16_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::i32_t, ap::i8_t>  { using type = ap::i32_t; };

    template <> struct common_type<ap::i32_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::i32_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::i32_t, ap::u16_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::i32_t, ap::u8_t>  { using type = ap::i32_t; };


    template <> struct common_type<ap::i16_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::i16_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::i16_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i16_t, ap::i32_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::i16_t, ap::i16_t> { using type = ap::i16_t; };
    template <> struct common_type<ap::i16_t, ap::i8_t>  { using type = ap::i16_t; };

    template <> struct common_type<ap::i16_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::i16_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::i16_t, ap::u16_t> { using type = ap::u16_t; };
    template <> struct common_type<ap::i16_t, ap::u8_t>  { using type = ap::i16_t; };


    template <> struct common_type<ap::i8_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::i8_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::i8_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::i8_t, ap::i32_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::i8_t, ap::i16_t> { using type = ap::i16_t; };
    template <> struct common_type<ap::i8_t, ap::i8_t>  { using type = ap::i8_t; };

    template <> struct common_type<ap::i8_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::i8_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::i8_t, ap::u16_t> { using type = ap::u16_t; };
    template <> struct common_type<ap::i8_t, ap::u8_t>  { using type = ap::u8_t; };
}

namespace std                                                                       {
    template <> struct common_type<ap::u64_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::u64_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::u64_t, ap::i64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::i32_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::i16_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::i8_t>  { using type = ap::u64_t; };

    template <> struct common_type<ap::u64_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::u32_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::u16_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u64_t, ap::u8_t>  { using type = ap::u64_t; };


    template <> struct common_type<ap::u32_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::u32_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::u32_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::u32_t, ap::i32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u32_t, ap::i16_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u32_t, ap::i8_t>  { using type = ap::u32_t; };

    template <> struct common_type<ap::u32_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u32_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u32_t, ap::u16_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u32_t, ap::u8_t>  { using type = ap::u32_t; };


    template <> struct common_type<ap::u16_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::u16_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::u16_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::u16_t, ap::i32_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::u16_t, ap::i16_t> { using type = ap::u16_t; };
    template <> struct common_type<ap::u16_t, ap::i8_t>  { using type = ap::u16_t; };

    template <> struct common_type<ap::u16_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u16_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u16_t, ap::u16_t> { using type = ap::u16_t; };
    template <> struct common_type<ap::u16_t, ap::u8_t>  { using type = ap::u16_t; };


    template <> struct common_type<ap::u8_t, ap::f64_t> { using type = ap::f64_t; };
    template <> struct common_type<ap::u8_t, ap::f32_t> { using type = ap::f32_t; };

    template <> struct common_type<ap::u8_t, ap::i64_t> { using type = ap::i64_t; };
    template <> struct common_type<ap::u8_t, ap::i32_t> { using type = ap::i32_t; };
    template <> struct common_type<ap::u8_t, ap::i16_t> { using type = ap::i16_t; };
    template <> struct common_type<ap::u8_t, ap::i8_t>  { using type = ap::u8_t; };

    template <> struct common_type<ap::u8_t, ap::u64_t> { using type = ap::u64_t; };
    template <> struct common_type<ap::u8_t, ap::u32_t> { using type = ap::u32_t; };
    template <> struct common_type<ap::u8_t, ap::u16_t> { using type = ap::u16_t; };
    template <> struct common_type<ap::u8_t, ap::u8_t>  { using type = ap::u8_t; };
}

#endif
