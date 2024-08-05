#ifndef AP_OPERATOR_ARI_HPP
#define AP_OPERATOR_ARI_HPP

#include <ap/trait.hpp>
#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap            {
    template <typename T>
    class ari           {
        using sub_t = T&;
        sub_t sub;
    public:
        ari(sub_t self) : sub (self) {}
    public:
        template <typename U> auto operator+ (U arg) { return op<opc::add, T, U> { sub, arg }; }
        template <typename U> auto operator- (U arg) { return op<opc::sub, T, U> { sub, arg }; }
        template <typename U> auto operator* (U arg) { return op<opc::mul, T, U> { sub, arg }; }
        template <typename U> auto operator/ (U arg) { return op<opc::div, T, U> { sub, arg }; }
        template <typename U> auto operator% (U arg) { return op<opc::mod, T, U> { sub, arg }; }
    };

    template <typename T>
    class ari_eq        {
        using sub_t = T&;
        sub_t sub;
    public:
        ari_eq(sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator+=(U arg);
        template <typename U> auto operator-=(U arg);
        template <typename U> auto operator*=(U arg);
        template <typename U> auto operator/=(U arg);
        template <typename U> auto operator%=(U arg);
    };

    template <typename T>
    template <typename U> 
    auto 
        ari_eq<T>::operator+=
            (U arg)                              { 
                auto ret = meta::add_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::add_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        ari_eq<T>::operator-=
            (U arg)                              { 
                auto ret = meta::sub_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::sub_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        ari_eq<T>::operator*=
            (U arg)                              { 
                auto ret = meta::mul_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::mul_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        ari_eq<T>::operator/=
            (U arg)                              { 
                auto ret = meta::div_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::div_eq, T, U> { sub, arg }; 
    }

    template <typename T>
    template <typename U> 
    auto 
        ari_eq<T>::operator%=
            (U arg)                              { 
                auto ret = meta::mod_eq(sub, arg);
                meta::src::push(ret);

                return op<opc::mod_eq, T, U> { sub, arg }; 
    }
}

#endif
