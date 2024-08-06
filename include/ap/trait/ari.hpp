#ifndef AP_TRAIT_ARI_HPP
#define AP_TRAIT_ARI_HPP

#include <ap/trait/opc.hpp>
#include <ap/trait/num.hpp>

#include <ap/trans/trans.hpp>

#include <type_traits>
#include <concepts> 

namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

namespace ap::is::details                                   {
    template <typename T> struct ari_eq : std::false_type {};
    template <typename T> struct ari    : std::false_type {};
    
    template <ap::opc C, typename T, typename U>
        requires is::opc::ari<C>
    struct ari<op <C, T, U>> 
        : std::true_type
            {};

    template <ap::opc C, typename T, typename U>
        requires is::opc::ari_eq<C>
    struct ari_eq<op <C, T, U>> 
        : std::true_type
            {};
}

namespace ap::is                                                    {
    template <typename T> concept ari_eq = details::ari_eq<T>::value;
    template <typename T> concept ari    = details::ari_eq<T>::value;
}


namespace ap                          {
    template <typename... T> class var;
}

namespace ap::can::details                                  {
    template <typename T> struct ari_eq : std::false_type {};
    template <typename T> struct ari    : std::false_type {};

    // For ap::can::ari
    template <ap::opc C, typename... T> 
        requires is::opc::ari_eq<C> 
    struct ari<ap::op <C, T...>> 
        : std::true_type 
            {};

    template <ap::opc C, typename... T> 
        requires is::opc::bit_eq<C> 
    struct ari<ap::op <C, T...>> 
        : std::true_type 
            {};


    template <ap::opc C, typename... T> 
        requires is::opc::ari<C> 
    struct ari<ap::op <C, T...>> 
        : std::true_type 
            {};

    template <ap::opc C, typename... T> 
        requires is::opc::bit<C> 
    struct ari<ap::op <C, T...>> 
        : std::true_type 
            {};


    template <is::num_t T>           struct ari<var <T>> : std::true_type {};
    template <std::floating_point T> struct ari<T>       : std::true_type {};
    template <std::integral T>       struct ari<T>       : std::true_type {};

    // For ap::can::ari_eq
    template <ap::opc C, typename... T> requires is::opc::ari_eq<C> struct ari_eq<ap::op <C, T...>> : std::true_type {};
    template <ap::opc C, typename... T> requires is::opc::bit_eq<C> struct ari_eq<ap::op <C, T...>> : std::true_type {};

    template <is::num_t T> struct ari_eq<var <T>> : std::true_type {};
}

namespace ap::can                                                   {
    template <typename T> concept ari_eq = details::ari_eq<T>::value;
    template <typename T> concept ari    = details::ari   <T>::value;
}

namespace ap::can::trans::details                                                  {
    template <typename T>    struct ari                        : std::false_type {};
    template <typename... T> struct ari <ap::trans::ari<T...>> : std::true_type  {};
}

namespace ap::can::trans                                      {
    template <typename T> concept ari = details::ari<T>::value;
}

#endif
