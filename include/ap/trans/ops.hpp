#ifndef AP_TRANS_OPS_HPP
#define AP_TRANS_OPS_HPP

#include <ap/meta/meta.hpp>
#include <ap/core/core.hpp>

#include "ops/ari.hpp"
#include "ops/bit.hpp"
#include "ops/cmp.hpp"
#include "ops/ord.hpp"

namespace ap::trans {
    template <typename T, typename... Arg>
    class ops <T, Arg...> : public Arg... {
    public:
        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::ari_eq<C>;
        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::bit_eq<C>;

        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::ari<C>;
        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::bit<C>;
        template <ap::opc C, typename T1>              auto operator()(ap::op<C, T1>)     requires is::opc::bit<C>;

        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires (C == opc::move);
        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::cmp <C>;
        template <ap::opc C, typename T1, typename T2> auto operator()(ap::op<C, T1, T2>) requires is::opc::ord <C>;

        auto operator ()(is::var_t           auto self) { return ap::name(self); }
        auto operator ()(std::floating_point auto self) { return self; }
        auto operator ()(std::integral       auto self) { return self; }

        ops (T, Arg...) : Arg()... {}
    };

    template <typename T, typename... Arg> ops(T, Arg...) -> ops<T, Arg...>;
}

namespace ap::trans                                                                           {
    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::ari_eq<C> {
                auto ops = T::ops();

                T::self (ops, (*this)(op.self));
                if constexpr (C == opc::add_eq) this->add_eq (ops);
                if constexpr (C == opc::sub_eq) this->sub_eq (ops);
                if constexpr (C == opc::mul_eq) this->mul_eq (ops);
                if constexpr (C == opc::div_eq) this->div_eq (ops);
                if constexpr (C == opc::mod_eq) this->mod_eq (ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::bit_eq<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::bit_and_eq) this->bit_and_eq(ops);
                if constexpr (C == opc::bit_or_eq)  this->bit_or_eq (ops);
                if constexpr (C == opc::bit_xor_eq) this->bit_xor_eq(ops);
                
                T::arg(ops, (*this) (op.arg));
                return ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::ari<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::add) this->add (ops);
                if constexpr (C == opc::sub) this->sub (ops);
                if constexpr (C == opc::mul) this->mul (ops);
                if constexpr (C == opc::div) this->div (ops);
                if constexpr (C == opc::mod) this->mod (ops);

                T::arg(ops, (*this) (op.arg));
                return ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::bit<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::bit_and) this->bit_and(ops);
                if constexpr (C == opc::bit_or)  this->bit_or (ops);
                if constexpr (C == opc::bit_xor) this->bit_xor(ops);
                if constexpr (C == opc::bit_shl) this->bit_shl(ops);
                if constexpr (C == opc::bit_shr) this->bit_shr(ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1> op) requires is::opc::bit<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::bit_not) this->bit_not(ops);
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::ord<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::ord_ge) this->ord_ge(ops);
                if constexpr (C == opc::ord_gt) this->ord_gt(ops);
                if constexpr (C == opc::ord_le) this->ord_le(ops);
                if constexpr (C == opc::ord_lt) this->ord_lt(ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::cmp<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::cmp_eq) this->cmp_eq(ops);
                if constexpr (C == opc::cmp_ne) this->cmp_ne(ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires (C == opc::move) {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                this->mov    (ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }
}

#endif
