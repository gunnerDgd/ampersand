#ifndef AP_INT_HPP
#define AP_INT_HPP

#include <type_traits>

namespace ap::types {
    struct i64_t {};
    struct u64_t {};

    struct i32_t {};
    struct u32_t {};

    struct i16_t {};
    struct u16_t {};

    struct i8_t {};
    struct u8_t {};
}

namespace ap                 {
    extern types::i64_t i64_t;
    extern types::u64_t u64_t;

    extern types::i32_t i32_t;
    extern types::u32_t u32_t;

    extern types::i16_t i16_t;
    extern types::u16_t u16_t;

    extern types::i8_t  i8_t;
    extern types::u8_t  u8_t;
}

#endif
