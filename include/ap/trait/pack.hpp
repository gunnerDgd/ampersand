#ifndef AP_TRAIT_PACK_HPP
#define AP_TRAIT_PACK_HPP

#include <type_traits>

namespace ap                           {
    template <typename... T> class pack;
}

namespace ap::is::details                                                       {
    template <typename T>    struct pack_t                  : std::false_type {};
    template <typename... T> struct pack_t <ap::pack<T...>> : std::true_type  {};
}

namespace ap::is                                                    {
    template <typename T> concept pack_t = details::pack_t<T>::value;
}

#endif
