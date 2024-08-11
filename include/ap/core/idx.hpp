#ifndef AP_IDX_HPP
#define AP_IDX_HPP

#include <ap/core/operator.hpp>
#include <ap/trait.hpp>

namespace ap                                          {
    template <is::int_t T, typename U>
    struct op<opc::idx, ap::var<T[]>, U> 
        : public ari_eq  <op <opc::idx, ap::var<T[]>, U>>,
          public bit_eq  <op <opc::idx, ap::var<T[]>, U>>,

          public ari     <op <opc::idx, ap::var<T[]>, U>>,
          public bit     <op <opc::idx, ap::var<T[]>, U>>,

          public move    <op <opc::idx, ap::var<T[]>, U>>,

          public boolean <op <opc::idx, ap::var<T[]>, U>>,
          public cmp     <op <opc::idx, ap::var<T[]>, U>>,
          public ord     <op <opc::idx, ap::var<T[]>, U>>
                                                        {
        ap::var<T[]> self;
        U            arg;
        
        
        op(ap::var<T[]> self, U idx)
            : ari_eq  <op <opc::idx, ap::var<T[]>, U>> (*this),
              bit_eq  <op <opc::idx, ap::var<T[]>, U>> (*this),

              ari     <op <opc::idx, ap::var<T[]>, U>> (*this),
              bit     <op <opc::idx, ap::var<T[]>, U>> (*this),

              move    <op <opc::idx, ap::var<T[]>, U>> (*this),

              boolean <op <opc::idx, ap::var<T[]>, U>> (*this),
              cmp     <op <opc::idx, ap::var<T[]>, U>> (*this),
              ord     <op <opc::idx, ap::var<T[]>, U>> (*this),

              self (self),
              arg  (idx)
                {}

        auto 
            operator=(auto arg)                                                            {
                auto&  self = static_cast<ap::move<op <opc::idx, ap::var<T[]>, U>>&>(*this);
                return self = arg;
        }
    };
}

#endif
