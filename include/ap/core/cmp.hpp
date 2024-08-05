#ifndef AP_CMP_HPP
#define AP_CMP_HPP

#include <ap/trait.hpp>
#include <ap/core/operator/boolean.hpp>
#include <ap/core/operator/ord.hpp>
#include <ap/core/operator/cmp.hpp>

namespace ap                                {
    template <opc C, can::cmp T, can::cmp U>
        requires is::opc::cmp<C>
    struct op<C, T, U>
        : public cmp <op <C, T, U>> {
            T self;
            U arg;

            op (T self, U arg)
                : cmp <op <C, T, U>> (*this),

                  self (self),
                  arg  (arg)
            {}
    };
}

#endif
