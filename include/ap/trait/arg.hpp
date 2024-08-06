#ifndef AP_TRAIT_ARG_HPP
#define AP_TRAIT_ARG_HPP

#include "move.hpp"
#include "var.hpp"

namespace ap                         {
    template <typename... T> class fn;
}

namespace ap::can::details                                  {
    template <typename... T> struct arg : std::false_type {};

    template <typename R, is::var_t A1, typename A2>
        requires can::move<A1, A2>
    struct arg<fn<R(A1)>, A2>
        : std::true_type
            {};

    template <typename R, is::var_t A1, is::var_t... A1n, typename A2, typename... A2n>
        requires ((sizeof...(A1n)) == (sizeof...(A2n)))
    struct arg <fn<R(A1, A1n...)>, A2, A2n...>
        : public arg <fn<R(A1n...)>, A2n...>
            {};
}

namespace ap::can                                                                        {
    template <typename Fn, typename... Arg> concept arg = details::arg<Fn, Arg...>::value;
}

#endif
