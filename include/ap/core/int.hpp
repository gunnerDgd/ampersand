#ifndef AP_INT_HPP
#define AP_INT_HPP

#include <type_traits>

namespace ap       {
    struct i64_t {};
    struct u64_t {};

    struct i32_t {};
    struct u32_t {};

    struct i16_t {};
    struct u16_t {};

    struct i8_t {};
    struct u8_t {};

    extern i8_t  i8;
    extern u8_t  u8;

    extern i16_t i16;
    extern u16_t u16;

    extern i32_t i32;
    extern u32_t u32;

    extern i64_t i64;
    extern u64_t u64;
}

#endif
