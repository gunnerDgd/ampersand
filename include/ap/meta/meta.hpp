#ifndef AP_META_META_HPP
#define AP_META_META_HPP

#include <string_view>
#include <optional>
#include <variant>

namespace ap::meta                     {
    enum class type_id : std::uint64_t {
        u64, i64,
        u32, i32,
        u16, i16,
        u8 , i8 ,

        f64, f32,
        pack,
        none
    };
}

namespace ap::meta {
    class func;
    class pack;
    class src;
    class var;
    class num;
    class ope;
    class op;
    class fn;
}

namespace ap::meta                                     {
    std::variant <std::string_view, type_id> type(var&);
    std::optional<std::string_view>          self(var&);
    std::optional<std::string_view>          name(var&);
}

namespace ap::meta            {
    std::uint64_t as_u64(num&);
    std::uint32_t as_u32(num&);
    std::uint16_t as_u16(num&);
    std::uint8_t  as_u8 (num&);

    std::int64_t  as_i64(num&);
    std::int32_t  as_i32(num&);
    std::int16_t  as_i16(num&);
    std::int8_t   as_i8 (num&);

    double        as_f64(num&);
    float         as_f32(num&);

    type_id       type  (num&);
}

namespace ap::meta {
    template <typename T, typename U>      op move(T, U);
    template <typename T>                  op push(T);
    template <typename T>                  op pop (T);

    template <typename T, typename... Arg> op call(T, Arg...);
    template <typename T>                  op ret (T);

    template <typename T, typename U>      op add_eq(T, U);
    template <typename T, typename U>      op sub_eq(T, U);
    template <typename T, typename U>      op mul_eq(T, U);
    template <typename T, typename U>      op div_eq(T, U);
    template <typename T, typename U>      op mod_eq(T, U);

    template <typename T, typename U>      op add(T, U);
    template <typename T, typename U>      op sub(T, U);
    template <typename T, typename U>      op mul(T, U);
    template <typename T, typename U>      op div(T, U);
    template <typename T, typename U>      op mod(T, U);

    template <typename T, typename U>      op bit_and(T, U);
    template <typename T, typename U>      op bit_or (T, U);
    template <typename T, typename U>      op bit_xor(T, U);
    template <typename T>                  op bit_not(T);

    template <typename T, typename U>      op bit_shl(T, U);
    template <typename T, typename U>      op bit_shr(T, U);

    template <typename T, typename U>      op bit_and_eq(T, U);
    template <typename T, typename U>      op bit_or_eq (T, U);
    template <typename T, typename U>      op bit_xor_eq(T, U);

    template <typename T, typename U>      op bool_and(T, U);
    template <typename T, typename U>      op bool_or (T, U);
    template <typename T>                  op bool_not(T);

    template <typename T, typename U>      op cmp_eq(T, U);
    template <typename T, typename U>      op cmp_ne(T, U);

    template <typename T, typename U>      op ord_lt(T, U);
    template <typename T, typename U>      op ord_le(T, U);
    template <typename T, typename U>      op ord_gt(T, U);
    template <typename T, typename U>      op ord_ge(T, U);
}

#endif
