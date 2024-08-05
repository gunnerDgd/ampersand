#ifndef AP_MOVE_HPP
#define AP_MOVE_HPP

#include "ap/trait.hpp"

#include <ap/core/operator/move.hpp>
#include <ap/core/operator/ari.hpp>
#include <ap/core/operator/bit.hpp>

namespace ap                          {
    template <is::int_t T, is::num_t U>
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public bit_eq <op <opc::move, T, U>>,

          public ari <op <opc::move, T, U>>,
          public bit <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  bit_eq<op <opc::move, T, U>>(*this),

                  ari<op <opc::move, T, U>>(*this),
                  bit<op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, is::num_t U>
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public ari    <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  ari   <op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };


    template <is::int_t T, std::integral U>
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public bit_eq <op <opc::move, T, U>>,

          public ari <op <opc::move, T, U>>,
          public bit <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  bit_eq<op <opc::move, T, U>>(*this),

                  ari<op <opc::move, T, U>>(*this),
                  bit<op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, std::integral U>
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public ari    <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  ari   <op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };


    template <is::int_t T, std::floating_point U >
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public bit_eq <op <opc::move, T, U>>,

          public ari <op <opc::move, T, U>>,
          public bit <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  bit_eq<op <opc::move, T, U>>(*this),

                  ari<op <opc::move, T, U>>(*this),
                  bit<op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::float_t T, std::floating_point U>
    struct op <opc::move, T, U>
        : public ari_eq <op <opc::move, T, U>>,
          public ari    <op <opc::move, T, U>> {
            T self;
            U arg;

            op(T self, U arg)
                : ari_eq<op <opc::move, T, U>>(*this),
                  ari   <op <opc::move, T, U>>(*this),

                  self(self),
                  arg (arg)
            {}
    };

    template <is::pack_t T>
    struct op <opc::move, T, T> {
        T self;
        T arg;

        op (T self, T arg)
            : self (self),
              arg  (arg)
        {}
    };
}

#endif
