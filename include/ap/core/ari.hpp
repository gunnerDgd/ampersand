#ifndef AP_ARI_HPP
#define AP_ARI_HPP

#include <ap/trait.hpp>
#include <ap/core/operator.hpp>

namespace ap                                {
    template <opc C, can::ari T, can::ari U> 
        requires is::opc::ari<C>
    struct op<C, T, U>
        : public ari <op <C, T, U>> {
            T self;
            U arg;

            op(T self, U arg) 
                : ari <op <C, T, U>> (*this),
                  self(self), 
                  arg (arg)
            {}
    };

    template <opc C, can::ari_eq T, can::ari U> 
        requires is::opc::ari_eq<C>
    struct op<C, T, U>
        : public ari_eq<op <C, T, U>>,
          public ari   <op <C, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <C, T, U>>(*this),
                  ari   <op <C, T, U>>(*this),
                  self(self),
                  arg (arg)
            {}
    };
}

#endif
