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
                if constexpr (C == opc::add_eq) add_eq (ops);
                if constexpr (C == opc::sub_eq) sub_eq (ops);
                if constexpr (C == opc::mul_eq) mul_eq (ops);
                if constexpr (C == opc::div_eq) div_eq (ops);
                if constexpr (C == opc::mod_eq) mod_eq (ops);

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
                if constexpr (C == opc::bit_and_eq) bit_and_eq(ops);
                if constexpr (C == opc::bit_or_eq)  bit_or_eq (ops);
                if constexpr (C == opc::bit_xor_eq) bit_xor_eq(ops);
                
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
                if constexpr (C == opc::add) add (ops);
                if constexpr (C == opc::sub) sub (ops);
                if constexpr (C == opc::mul) mul (ops);
                if constexpr (C == opc::div) div (ops);
                if constexpr (C == opc::mod) mod (ops);

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
                if constexpr (C == opc::bit_and) bit_and_eq(ops);
                if constexpr (C == opc::bit_or)  bit_or_eq (ops);
                if constexpr (C == opc::bit_xor) bit_xor_eq(ops);
                if constexpr (C == opc::bit_shl) bit_xor_eq(ops);
                if constexpr (C == opc::bit_shr) bit_xor_eq(ops);

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
                if constexpr (C == opc::bit_not) bit_not(ops);
    }

    template <typename T, typename... Arg>
    template <ap::opc C, typename T1, typename T2>
    auto 
        ops<T, Arg...>::operator()
            (ap::op<C, T1, T2> op) requires is::opc::ord<C> {
                auto ops = T::ops();

                T::self(ops, (*this)(op.self));
                if constexpr (C == opc::ord_ge) ord_ge(ops);
                if constexpr (C == opc::ord_gt) ord_gt(ops);
                if constexpr (C == opc::ord_le) ord_le(ops);
                if constexpr (C == opc::ord_lt) ord_lt(ops);

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
                if constexpr (C == opc::cmp_eq) cmp_eq(ops);
                if constexpr (C == opc::cmp_ne) cmp_ne(ops);

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
                mov    (ops);

                T::arg (ops, (*this) (op.arg));
                return  ops;
    }
}

#endif
