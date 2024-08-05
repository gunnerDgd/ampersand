#ifndef AP_TRAIT_NUM_HPP
#define AP_TRAIT_NUM_HPP

#include "float.hpp"
#include "int.hpp"

namespace ap::is::details                                                            {
    template <typename T>    struct num_t    { static constexpr bool value = false; };

    template <is::float_t T> struct num_t<T> { static constexpr bool value = true; };
    template <is::int_t T>   struct num_t<T> { static constexpr bool value = true; };
}

namespace ap::is                                                  {
    template <typename T> concept num_t = details::num_t<T>::value;
}

#endif
