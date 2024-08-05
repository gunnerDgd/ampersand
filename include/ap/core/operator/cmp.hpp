#ifndef AP_OPERATOR_CMP_HPP
#define AP_OPERATOR_CMP_HPP

#include "ap/trait/opc.hpp"

namespace ap                              {
    template <typename T>
    class cmp                             {
        template <typename... F> class var;
        using sub_t = T&;
        sub_t sub;
    public:
        cmp (sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator!= (U arg) { return op<opc::cmp_ne, T, U> { sub, arg }; }
        template <typename U> auto operator== (U arg) { return op<opc::cmp_eq, T, U> { sub, arg }; }
    };
}

#endif
