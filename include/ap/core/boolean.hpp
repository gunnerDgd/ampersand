#ifndef AP_BOOLEAN_HPP
#define AP_BOOLEAN_HPP

#include <ap/core/operator.hpp>
#include <ap/trait.hpp>

namespace ap                                        {
    template <opc C, can::boolean T, can::boolean U>
        requires is::opc::boolean<C>
    struct op<C, T, U>
        : public boolean<op <C, T, U>> {
            T self;
            U arg;

            op (T self, U arg)
                :  boolean <op <C, T, U>> (*this),
                   self (self),
                   arg  (arg)
            {}
    };

    template <opc C, can::boolean T>
        requires is::opc::boolean<C>
    struct op<C, T>
        : public boolean<op <C, T>> {
            T self;

            op (T self)
                :  boolean <op <C, T>> (*this),
                   self (self)
            {}
    };
}

#endif
