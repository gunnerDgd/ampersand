#ifndef AP_OPERATOR_IDX_HPP
#define AP_OPERATOR_IDX_HPP

#include <ap/trait.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>

namespace ap                            {
    template <typename T>
    class idx                           {
        using sub_t = T&;
        sub_t sub;
    public:
        idx (sub_t self) : sub (self) {};

        template <typename U> auto operator[](U arg) { return op<opc::idx, T, U> ( sub, arg ); }
    };
}

#endif
