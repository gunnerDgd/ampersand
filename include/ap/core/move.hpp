#ifndef AP_MOVE_HPP
#define AP_MOVE_HPP

#include "ap/trait.hpp"

#include <ap/core/operator/move.hpp>
#include <ap/core/operator/ari.hpp>
#include <ap/core/operator/bit.hpp>

namespace ap                          {
    template <is::int_t T, typename U>
        requires can::move <ap::var<T>, U>
    struct op <opc::move, ap::var<T>, U>                        
        : public ari_eq <op <opc::move, ap::var<T>, U>>,
          public bit_eq <op <opc::move, ap::var<T>, U>>,

          public ari <op <opc::move, ap::var<T>, U>>,
          public bit <op <opc::move, ap::var<T>, U>> {
            ap::var<T> self;
            U          arg;

            op(ap::var<T> self, U arg)
                : ari_eq<op <opc::move, ap::var<T>, U>>(*this),
                  bit_eq<op <opc::move, ap::var<T>, U>>(*this),

                  ari<op <opc::move, ap::var<T>, U>>(*this),
                  bit<op <opc::move, ap::var<T>, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, typename U>
        requires can::move <ap::var<T>, U>
    struct op <opc::move, ap::var<T>, U>
        : public ari_eq <op <opc::move, ap::var<T>, U>>,
          public ari    <op <opc::move, ap::var<T>, U>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, U arg)
                : ari_eq<op <opc::move, ap::var<T>, U>>(*this),
                  ari   <op <opc::move, ap::var<T>, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::pack_t T>
    struct op <opc::move, ap::var<T>, ap::var<T>> {
        ap::var<T> self;
        ap::var<T> arg;

        op (ap::var<T> self, ap::var<T> arg)
            : self (self),
              arg  (arg)
        {}
    };
}



namespace ap                                                    {
    template <is::int_t T, typename U, typename V>
        requires can::move <ap::var<T>, U>
    struct op <opc::move, op < opc::idx, ap::var<T[]>, V >, U>

        : public ari_eq <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>,
          public bit_eq <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>,

          public ari <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>,
          public bit <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>> {
            op<opc::idx, ap::var<T[]>, V> self;
            U                             arg;

            op(op<opc::idx, ap::var<T[]>, V> self, U arg)
                : ari_eq<op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),
                  bit_eq<op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),

                  ari<op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),
                  bit<op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, typename U, typename V>
        requires can::move <op < opc::idx, ap::var<T>>, U>
    struct op <opc::move,   op < opc::idx, ap::var<T[]>, V >, U>
        : public ari_eq <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>,
          public ari    <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>
                                                                     {
            op<opc::idx, ap::var<T[]>, V> self;
            ap::var<U>                    arg;

            op(op<opc::idx, ap::var<T[]>, V> self, U arg)
                : ari_eq<op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),
                  ari   <op <opc::move, op<opc::idx, ap::var<T[]>, V>, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::pack_t T, typename U>
    struct op <opc::move, op<opc::idx, ap::var<T[]>, U>, ap::var<T>>
                                          {
        op<opc::idx, ap::var<T[]>, U> self;
        ap::var<T>                    arg;

        op (op<opc::idx, ap::var<T[]>, U> self, ap::var<T> arg)
            : self (self),
              arg  (arg)
        {}
    };
}

#endif
