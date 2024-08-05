#ifndef AP_META_NUM_HPP
#define AP_META_NUM_HPP

#include <type_traits>
#include <concepts>

namespace ap::meta                 {
    class num                      {
        using idx_t = std::uint64_t;
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
    public:
        num (std::floating_point auto arg) {
            using arg_t = decltype (arg);

            if constexpr (std::same_as<arg_t, double>) { idx = 8; f64 = arg; }
            if constexpr (std::same_as<arg_t, float>)  { idx = 9; f32 = arg; }
        }

        num (std::integral auto arg)    {
            using arg_t = decltype (arg);

            if constexpr (std::same_as<arg_t, std::int64_t>)  { idx = 0; i64 = arg; }
            if constexpr (std::same_as<arg_t, std::int32_t>)  { idx = 1; i32 = arg; }
            if constexpr (std::same_as<arg_t, std::int16_t>)  { idx = 2; i16 = arg; }
            if constexpr (std::same_as<arg_t, std::int8_t>)   { idx = 3; i8  = arg; }

            if constexpr (std::same_as<arg_t, std::uint64_t>) { idx = 4; u64 = arg; }
            if constexpr (std::same_as<arg_t, std::uint32_t>) { idx = 5; u32 = arg; }
            if constexpr (std::same_as<arg_t, std::uint16_t>) { idx = 6; u16 = arg; }
            if constexpr (std::same_as<arg_t, std::uint8_t>)  { idx = 7; u8 = arg; }
        }
    };
}

#endif
