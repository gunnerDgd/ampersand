#ifndef AP_OPERATOR_CALL_HPP
#define AP_OPERATOR_CALL_HPP

#include <ap/trait.hpp>
#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap                                              {
    template <typename T>
    class call          {
        using sub_t = T&;
        sub_t sub;
    public:
        call(sub_t self) : sub (self) {}
    public:
        template <typename... Arg> auto operator()(Arg...);
                                   auto operator()();
    };

    template <typename T>
    template <typename... Arg> 
    auto 
        call<T>::operator()
            (Arg... arg)                                    {
                auto ret = meta::call (sub, arg...);
                meta::src::push(ret);

                return op<opc::call, T, Arg...>(sub, arg...); 
    }

    template <typename T>
    auto 
        call<T>::operator()()         {
            auto ret = meta::call(sub);
            meta::src::push(ret);

            return op<opc::call, T>(sub);
    }
}

#endif
