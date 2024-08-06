#ifndef AP_TRAIT_BIT_HPP
#define AP_TRIAT_BIT_HPP

#include <ap/trait/opc.hpp>
#include <ap/trait/num.hpp>

#include <ap/trans/trans.hpp>

#include <type_traits>
#include <concepts>


namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

namespace ap::is::details                                   {
    template <typename T> struct bit_eq : std::false_type {};
    template <typename T> struct bit    : std::false_type {};
    
    template <ap::opc C, typename T, typename U>
        requires is::opc::bit<C>
    struct bit<op <C, T, U>> 
        : std::true_type
            {};

    template <ap::opc C, typename T>
        requires is::opc::bit<C>
    struct bit<op <C, T>> 
        : std::true_type
            {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::ari_eq<C>
    struct bit_eq<op <C, T, U>> 
        : std::true_type
            {};
}

namespace ap::is                                                    {
    template <typename T> concept bit_eq = details::bit_eq<T>::value;
    template <typename T> concept bit    = details::bit_eq<T>::value;
}


namespace ap                          {
    template <typename... T> class var;
}

namespace ap::can::details                                  {
    template <typename T> struct bit_eq : std::false_type {};
    template <typename T> struct bit    : std::false_type {};

    // For ap::can::bit

    // example : int a; a + 3;
    template <ap::opc C, is::int_t T, std::integral U> 
        requires is::opc::ari<C> 
    struct bit<ap::op <C, ap::var<T>, U>> 
        : std::true_type 
            {};

    // example : int a; 3 + a;
    template <ap::opc C, std::integral T, is::int_t U> 
        requires is::opc::ari<C> 
    struct bit<ap::op <C, T, ap::var<U>>> 
        : std::true_type 
            {};

    // example : 1 + 2
    template <ap::opc C, std::integral T, std::integral U>
        requires is::opc::ari<C> 
    struct bit<ap::op <C, T, U>> 
        : std::true_type 
            {};


    // example : int a; int b; a + b
    template <ap::opc C, is::int_t T, is::int_t U>
        requires is::opc::ari<C> 
    struct bit<ap::op <C, ap::var<T>, ap::var<U>>> 
        : std::true_type 
            {};

    // example : int a; a += 3
    template <ap::opc C, is::int_t T, typename U> 
        requires is::opc::ari_eq<C> 
    struct bit<ap::op <C, ap::var<T>, U>> 
        : std::true_type 
            {};


    // example : int a; a ^= 3;
    template <ap::opc C, typename... T> 
        requires is::opc::bit_eq<C> 
    struct bit<ap::op <C, T...>> 
        : std::true_type 
            {};

    // example : int a; a ^ 3;
    template <ap::opc C, typename... T> 
        requires is::opc::bit<C> 
    struct bit<ap::op <C, T...>> 
        : std::true_type 
            {};

    template <is::num_t T>           struct bit<var <T>> : std::true_type {};
    template <std::floating_point T> struct bit<T>       : std::true_type {};
    template <std::integral T>       struct bit<T>       : std::true_type {};

    // For ap::can::bit_eq
    template <ap::opc C, is::int_t T, typename U>
        requires is::opc::ari_eq<C>
    struct bit_eq<ap::op <C, ap::var<T>, U>>
        : std::true_type
            {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::bit_eq<C>
    struct bit_eq<ap::op <C, T, U>>
        : std::true_type
            {};

    template <is::num_t T> 
    struct bit_eq<var <T>> 
        : std::true_type 
            {};
}

namespace ap::can                                                   {
    template <typename T> concept bit_eq = details::bit_eq<T>::value;
    template <typename T> concept bit    = details::bit   <T>::value;
}

namespace ap::can::trans::details                                                  {
    template <typename T>    struct bit                        : std::false_type {};
    template <typename... T> struct bit <ap::trans::bit<T...>> : std::true_type  {};
}

namespace ap::can::trans                                      {
    template <typename T> concept bit = details::bit<T>::value;
}


#endif
