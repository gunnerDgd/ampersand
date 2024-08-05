#ifndef AP_TRAIT_BOOLEAN_HPP
#define AP_TRAIT_BOOLEAN_HPP

#include <ap/trait/opc.hpp>
#include <ap/trait/bool.hpp>

namespace ap                                    {
    template <ap::opc C, typename... T> class op;
}

namespace ap::is::details                                    {
    template <typename T> struct boolean : std::false_type {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::boolean<C>
    struct boolean <op<C, T, U>>
        : std::true_type
            {};

    template <ap::opc C, typename T>
        requires is::opc::boolean<C>
    struct boolean <op<C, T>>
        : std::true_type
            {};
}

namespace ap::is                                                      {
    template <typename T> concept boolean = details::boolean<T>::value;
}

namespace ap::can::details                                   {
    template <typename T> struct boolean : std::false_type {};

    template <ap::opc C, typename... T>
        requires is::opc::ord<C>
    struct boolean<ap::op <C, T...>>
        : std::true_type 
            {};

    template <ap::opc C, typename... T>
        requires is::opc::boolean<C>
    struct boolean<ap::op <C, T...>>
        : std::true_type 
            {};

    template <is::bool_t T>
    struct boolean<ap::var<T>>
        : std::true_type
            {};
}

namespace ap::can                                                     {
    template <typename T> concept boolean = details::boolean<T>::value;
}

#endif
