#ifndef AP_FLOAT_HPP
#define AP_FLOAT_HPP

#include <type_traits>

namespace ap::types {
    struct f32_t {};
    struct f64_t {};
}

namespace ap                 {
    extern types::f32_t f32_t;
    extern types::f64_t f64_t;
}

#endif
