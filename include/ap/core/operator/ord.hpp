#ifndef AP_OPERATOR_ORD_HPP
#define AP_OPERATOR_ORD_HPP

#include "ap/trait/opc.hpp"

namespace ap                              {
    template <typename T>
    class ord                             {
        template <typename... F> class var;
        using sub_t = T&;
        sub_t sub;
    public:
        ord (sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator<  (U arg) { return op<opc::ord_lt, T, U> { sub, arg }; }
        template <typename U> auto operator<= (U arg) { return op<opc::ord_le, T, U> { sub, arg }; }
        template <typename U> auto operator>  (U arg) { return op<opc::ord_gt, T, U> { sub, arg }; }
        template <typename U> auto operator>= (U arg) { return op<opc::ord_ge, T, U> { sub, arg }; }
    };
}

#endif
