#ifndef AP_BIT_HPP
#define AP_BIT_HPP

#include <ap/trait.hpp>
#include <ap/core/operator.hpp>

namespace ap                                 {
    template <opc C, can::bit T, can::bit U> 
        requires is::opc::bit<C>
    struct op<C, T, U>
        : public bit <op <C, T, U>>,
          public ari <op <C, T, U>> { 
            T self;
            U arg;

            op (T self, U arg) 
                : ari <op <C, T, U>> (*this),
                  bit <op <C, T, U>> (*this),
                  self(self),
                  arg (arg)
            {}
    };

    template <opc C, can::bit T> 
        requires is::opc::bit<C>
    struct op<C, T>
        : public bit <op <C, T>>,
          public ari <op <C, T>> {
            T self;

            op (T self) 
                : ari <op <C, T>> (*this),
                  bit <op <C, T>> (*this),
                  self(self)
            {}
    };

    template <opc C, can::bit_eq T, can::bit U> 
        requires is::opc::bit_eq<C>
    struct op<C, T, U>
        : public bit_eq<op <C, T, U>>,
          public bit   <op <C, T, U>>,

          public ari_eq<op <C, T, U>>,
          public ari   <op <C, T, U>> { 
            T self;
            U arg;

            op (T self, U arg)
                : ari_eq <op <C, T, U>> (*this),
                  bit_eq <op <C, T, U>> (*this),

                  ari    <op <C, T, U>> (*this),
                  bit    <op <C, T, U>> (*this),

                  self (self),
                  arg  (arg)
            {}
    };
}

#endif
