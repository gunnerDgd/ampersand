#ifndef AP_OPERATOR_BIT_HPP
#define AP_OPERATOR_BIT_HPP

#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>
#include <ap/trait.hpp>

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap             {
    template <typename T>
    class bit           {
        using sub_t = T&;
        sub_t sub;
    public:
        bit(sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator& (U arg) { return op<opc::bit_and, T, U> { sub, arg }; }
        template <typename U> auto operator| (U arg) { return op<opc::bit_or , T, U> { sub, arg }; }
        template <typename U> auto operator^ (U arg) { return op<opc::bit_xor, T, U> { sub, arg }; }
                              auto operator~ ()      { return op<opc::bit_not, T>    { sub }; }
    };

    template <typename T>
    class bit_eq        {
        using sub_t = T&;
        sub_t sub;
    public:
        bit_eq(sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator&=(U);
        template <typename U> auto operator|=(U);
        template <typename U> auto operator^=(U);
    };

    template <typename T>
    template <typename U> 
    auto 
        bit_eq<T>::operator&=
            (U arg)                                  {
                auto ret = meta::bit_and_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::bit_and_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        bit_eq<T>::operator|=
            (U arg)                                 {
                auto ret = meta::bit_or_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::bit_or_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        bit_eq<T>::operator^=
            (U arg)                                  {
                auto ret = meta::bit_xor_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::bit_xor_eq, T, U> { sub, arg };
    }
}

#endif
