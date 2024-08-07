#include <ap/meta/ope/num.hpp>

namespace ap::meta                                     {
    std::uint64_t as_u64(num& self) { return self.u64; }
    std::uint32_t as_u32(num& self) { return self.u32; }
    std::uint16_t as_u16(num& self) { return self.u16; }
    std::uint8_t  as_u8 (num& self) { return self.u8; }

    std::int64_t  as_i64(num& self) { return self.i64; }
    std::int32_t  as_i32(num& self) { return self.i32; }
    std::int16_t  as_i16(num& self) { return self.i16; }
    std::int8_t   as_i8 (num& self) { return self.i8; }

    double        as_f64(num& self) { return self.f64; }
    float         as_f32(num& self) { return self.f32; }

    type_id       type  (num& self) { return self.idx; }
}