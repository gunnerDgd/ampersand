#ifndef AP_TRAIT_BOOL_HPP
#define AP_TRAIT_BOOL_HPP

#include <type_traits>

namespace ap     {
    struct bool_t;
}

namespace ap::is::details                                               {
    template <typename T> struct bool_t             : std::false_type {};
    template <>           struct bool_t<ap::bool_t> : std::false_type {};
}

namespace ap::is {
    template <typename T> concept bool_t = details::bool_t<T>::value;
}

#endif
