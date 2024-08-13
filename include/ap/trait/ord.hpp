#ifndef AP_TRAIT_ORD_HPP
#define AP_TRAIT_ORD_HPP

#include <ap/trait/opc.hpp>
#include <ap/trait/num.hpp>

#include <ap/trans/trans.hpp>

#include <type_traits>
#include <concepts>

namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

namespace ap::is::details                                {
    template <typename T> struct ord : std::false_type {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::ord<C>
    struct ord <op <C, T, U>>
        : std::true_type
            {};
}

namespace ap::is                                              {
    template <typename T> concept ord = details::ord<T>::value;
}




namespace ap                          {
    template <typename... T> class var;
}

namespace ap::can::details                               {
    template <typename T> struct ord : std::false_type {};
    
    template <is::num_t T>           struct ord <ap::var <T>> : std::true_type {};
    template <std::floating_point T> struct ord <T>           : std::true_type {};
    template <std::integral T>       struct ord <T>           : std::true_type {};
}

namespace ap::can                                             {
    template <typename T> concept ord = details::ord<T>::value;
}

namespace ap::can::trans::details                                                  {
    template <typename T>    struct ord                        : std::false_type {};
    template <typename... T> struct ord <ap::trans::ord<T...>> : std::true_type  {};
}

namespace ap::can::trans                                      {
    template <typename T> concept ord = details::ord<T>::value;
}

#endif
