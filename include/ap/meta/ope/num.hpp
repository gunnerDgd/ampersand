#ifndef AP_META_NUM_HPP
#define AP_META_NUM_HPP

#include <ap/trans/trans.hpp>
#include <ap/meta/meta.hpp>

#include <type_traits>
#include <concepts>

namespace ap::meta           {
    class num                {
        using idx_t = type_id;
        idx_t idx;
        union                {
            std::int64_t  i64;
            std::int32_t  i32;
            std::int16_t  i16;
            std::int8_t   i8;

            std::uint64_t u64;
            std::uint32_t u32;
            std::uint16_t u16;
            std::uint8_t  u8;

            double        f64;
            float         f32;
        };

        template <typename... T> friend class trans::boolean;
        template <typename... T> friend class trans::func;
        template <typename... T> friend class trans::mem;
        template <typename... T> friend class trans::ari;
        template <typename... T> friend class trans::bit;
        template <typename... T> friend class trans::cmp;
        template <typename... T> friend class trans::ord;

        template <typename... T> friend class trans::pack;
        template <typename... T> friend class trans::var;
        template <typename... T> friend class trans::ops;
        template <typename... T> friend class trans::op;
        template <typename... T> friend class trans::fn;
        
        friend std::uint64_t as_u64(num&);
        friend std::uint32_t as_u32(num&);
        friend std::uint16_t as_u16(num&);
        friend std::uint8_t  as_u8 (num&);

        friend std::int64_t  as_i64(num&);
        friend std::int32_t  as_i32(num&);
        friend std::int16_t  as_i16(num&);
        friend std::int8_t   as_i8 (num&);

        friend double        as_f64(num&);
        friend float         as_f32(num&);

        friend type_id       type  (num&);
    public:
        num (std::floating_point auto arg) {
            using arg_t = decltype (arg);

            if constexpr (std::same_as<arg_t, double>) { idx = idx_t::f64; f64 = arg; }
            if constexpr (std::same_as<arg_t, float>)  { idx = idx_t::f32; f32 = arg; }
        }

        num (std::integral auto arg)    {
            using arg_t = decltype (arg);

            if constexpr (std::same_as<arg_t, std::int64_t>)  { idx = idx_t::i64; i64 = arg; }
            if constexpr (std::same_as<arg_t, std::int32_t>)  { idx = idx_t::i32; i32 = arg; }
            if constexpr (std::same_as<arg_t, std::int16_t>)  { idx = idx_t::i16; i16 = arg; }
            if constexpr (std::same_as<arg_t, std::int8_t>)   { idx = idx_t::i8 ; i8  = arg; }

            if constexpr (std::same_as<arg_t, std::uint64_t>) { idx = idx_t::u64; u64 = arg; }
            if constexpr (std::same_as<arg_t, std::uint32_t>) { idx = idx_t::u32; u32 = arg; }
            if constexpr (std::same_as<arg_t, std::uint16_t>) { idx = idx_t::u16; u16 = arg; }
            if constexpr (std::same_as<arg_t, std::uint8_t>)  { idx = idx_t::u8 ; u8 = arg; }
        }
    };
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

#endif
