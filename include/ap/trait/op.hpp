#ifndef AP_TRAIT_OP_HPP
#define AP_TRAIT_OP_HPP

#include <ap/trait/opc.hpp>
#include <type_traits>

namespace ap::is::details                                                                {
    template <typename T>               struct op_t                  : std::false_type {};
    template <ap::opc C, typename... T> struct op_t<ap::op<C, T...>> : std::true_type  {};
}

namespace ap::is                                                {
    template <typename T> concept op_t = details::op_t<T>::value;
}

#endif
