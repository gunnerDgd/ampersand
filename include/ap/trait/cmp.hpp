#ifndef AP_TRAIT_CMP_HPP
#define AP_TRAIT_CMP_HPP

#include <ap/trait/opc.hpp>

#include <ap/trait/bool.hpp>
#include <ap/trait/num.hpp>

#include <type_traits>
#include <concepts>

namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

namespace ap::is::details                                {
    template <typename T> struct cmp : std::false_type {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::cmp<C>
    struct cmp <op <C, T, U>>
        : std::true_type
            {};
}

namespace ap::is                                              {
    template <typename T> concept cmp = details::cmp<T>::value;
}

namespace ap                          {
    template <typename... T> class var;
}

namespace ap::can::details                               {
    template <typename T> struct cmp : std::false_type {};

    template <std::floating_point T> struct cmp <T> : std::true_type {};
    template <std::integral T>       struct cmp <T> : std::true_type {};

    template <is::bool_t T>          struct cmp <ap::var <T>> : std::true_type {};
    template <is::num_t T>           struct cmp <ap::var <T>> : std::true_type {};
}

namespace ap::can                                             {
    template <typename T> concept cmp = details::cmp<T>::value;
}

namespace ap::can::trans::details                                                  {
    template <typename T>    struct cmp                        : std::false_type {};
    template <typename... T> struct cmp <ap::trans::cmp<T...>> : std::true_type  {};
}

namespace ap::can::trans                                      {
    template <typename T> concept cmp = details::cmp<T>::value;
}

#endif
