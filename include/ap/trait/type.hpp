#ifndef AP_TYPE_HPP
#define AP_TYPE_HPP

#include "pack.hpp"
#include "num.hpp"

namespace ap::is::details                                        {
    template <typename T>   struct type_t    : std::false_type {};
    template <is::pack_t T> struct type_t<T> : std::true_type  {};
    template <is::num_t T>  struct type_t<T> : std::true_type  {};
}

namespace ap::is                                                    {
    template <typename T> concept type_t = details::type_t<T>::value;
}

#endif
