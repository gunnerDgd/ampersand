#ifndef AP_TRAIT_MOVE_HPP
#define AP_TRAIT_MOVE_HPP

#include <type_traits>
#include <concepts>

#include "opc.hpp"

#include "pack.hpp"
#include "float.hpp"
#include "bool.hpp"
#include "int.hpp"
#include "num.hpp"

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap                           {
    template <typename... T> class pack;
    template <typename... T> class var;
}

namespace ap::can::details                                            {
    template <typename T, typename U> struct move : std::false_type {};
}



//Restrictions For ap::var<T> (Self) And Integer / Floating Point Constant
namespace ap::can::details                       {
    template <is::num_t T, std::floating_point U>
    struct move <ap::var<T>, U> 
        : std::true_type
            {};

    template <is::num_t T, std::integral U>
        requires (!std::same_as<U, bool>)
    struct move <ap::var<T>, U> 
        : std::true_type
            {};

    template <is::bool_t T>
    struct move <ap::var<T>, bool> 
        : std::true_type
            {};
}

//Restrictions For ap::var<T> (Self) another ap::var<T>
namespace ap::can::details                      {
    template <typename... T>
    struct move <ap::pack<T...>, ap::pack<T...>>
        : std::true_type
            {};

    template <is::num_t T, is::num_t U>
    struct move <ap::var<T>, ap::var<U>> 
        : std::true_type
            {};

    template <is::bool_t T, is::bool_t U>
    struct move <ap::var<T>, ap::var<U>> 
        : std::true_type
            {};
}


// Restrictions For ap::var<T> (Self) and opcode Execution
namespace ap::can::details                           {
    template <is::num_t T, ap::opc C, typename... U>
        requires is::opc::ari<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    template <is::num_t T, ap::opc C, typename... U>
        requires is::opc::ari_eq<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    

    template <is::num_t T, ap::opc C, typename... U>
        requires is::opc::bit<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    template <is::num_t T, ap::opc C, typename... U>
        requires is::opc::bit_eq<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    // Warning
    // is::opc::cmp<C> / is::opc::ord<C> / is::opc::boolean<C> requires is::bool_t Self.
    template <is::bool_t T, ap::opc C, typename... U>
        requires is::opc::cmp<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    template <is::bool_t T, ap::opc C, typename... U>
        requires is::opc::ord<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};

    template <is::bool_t T, ap::opc C, typename... U>
        requires is::opc::boolean<C>
    struct move <ap::var<T>, ap::op<C, U...>>
        : std::true_type
            {};
}


// Restriction For Array Index Operation
namespace ap::can::details                                      {
    template <is::num_t T, is::num_t U, typename I>
    struct move <ap::var<T>, ap::op<opc::idx, ap::var<U[]>, I>>
        : std::true_type
            {};

    template <is::bool_t T, is::bool_t U, typename I>
    struct move <ap::var<T>, ap::op<opc::idx, ap::var<U[]>, I>>
        : std::true_type
            {};

    template <is::pack_t T, typename I>
    struct move <ap::var<T>, ap::op<opc::idx, ap::var<T[]>, I>>
        : std::true_type
            {};




    template <is::num_t T, is::num_t U, typename I>
    struct move <ap::op<opc::idx, ap::var<T []>, I>, ap::var<U>>
        : std::true_type
            {};

    template <is::bool_t T, is::bool_t U, typename I>
    struct move <ap::op<opc::idx, ap::var<T []>, I>, ap::var<U>>
        : std::true_type
            {};

    template <is::pack_t T, typename I>
    struct move <ap::op<opc::idx, ap::var<T []>, I>, ap::var<T>>
        : std::true_type
            {};
}

namespace ap::can                                                              {
    template <typename T, typename U> concept move = details::move<T, U>::value;
}

#endif
