#ifndef AP_ORD_HPP
#define AP_ORD_HPP

#include <ap/trait.hpp>
#include <ap/core/operator/boolean.hpp>
#include <ap/core/operator/ord.hpp>
#include <ap/core/operator/cmp.hpp>

namespace ap                                {
    template <opc C, can::ord T, can::ord U>
        requires is::opc::ord<C>
    struct op<C, T, U>
        : public ord <op <C, T, U>>,
          public cmp <op <C, T, U>> {
            T self;
            U arg;

            op (T self, U arg)
                : ord <op <C, T, U>> (*this),
                  cmp <op <C, T, U>> (*this),

                  self (self),
                  arg  (arg)
            {}
    };
}

#endif
