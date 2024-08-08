#ifndef AP_MOVE_HPP
#define AP_MOVE_HPP

#include "ap/trait.hpp"

#include <ap/core/operator/move.hpp>
#include <ap/core/operator/ari.hpp>
#include <ap/core/operator/bit.hpp>

namespace ap                          {
    template <is::int_t T, is::num_t U>
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit_eq <op <opc::move, ap::var<T>, ap::var<U>>>,

          public ari <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  ari<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, is::num_t U>
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public ari    <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  ari   <op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };


    template <is::int_t T, std::integral U>
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit_eq <op <opc::move, ap::var<T>, ap::var<U>>>,

          public ari <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  ari<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, std::integral U>
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public ari    <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  ari   <op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };


    template <is::int_t T, std::floating_point U >
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit_eq <op <opc::move, ap::var<T>, ap::var<U>>>,

          public ari <op <opc::move, ap::var<T>, ap::var<U>>>,
          public bit <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  ari<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  bit<op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, std::floating_point U>
    struct op <opc::move, ap::var<T>, ap::var<U>>
        : public ari_eq <op <opc::move, ap::var<T>, ap::var<U>>>,
          public ari    <op <opc::move, ap::var<T>, ap::var<U>>> {
            ap::var<T> self;
            ap::var<U> arg;

            op(ap::var<T> self, ap::var<U> arg)
                : ari_eq<op <opc::move, ap::var<T>, ap::var<U>>>(*this),
                  ari   <op <opc::move, ap::var<T>, ap::var<U>>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::pack_t T>
    struct op <opc::move, ap::var<T>, ap::var<T>> {
        ap::var<T> self;
        T arg;

        op (ap::var<T> self, ap::var<T> arg)
            : self (self),
              arg  (arg)
        {}
    };
}

#endif
