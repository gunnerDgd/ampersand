#ifndef AP_TRAIT_VAR_HPP
#define AP_TRAIT_VAR_HPP

#include "type.hpp"

namespace ap::is::details                                                {
    template <typename T>   struct var_t             : std::false_type {};
    template <is::type_t T> struct var_t<ap::var<T>> : std::true_type  {};
}

namespace ap::is                                                  {
    template <typename T> concept var_t = details::var_t<T>::value;
}

#endif
