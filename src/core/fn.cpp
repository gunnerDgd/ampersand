#include <ap/core/fn.hpp>
#include <ap/meta.hpp>

namespace ap                      {
    fn<void()>::fn(str_t name)
        : call<fn<void()>> (*this),
          name             (name)
            {}
}