#ifndef AP_GRAMMAR_LET_HPP
#define AP_GRAMMAR_LET_HPP

#include <ap/meta.hpp>
#include <ap/core.hpp>

namespace ap                                 {
    template <is::type_t T>
    auto let(T& type)                        {
        return [type](std::string_view name) {
            return var<T> { type, name };
        };
    }

    template <is::type_t T>
    auto let(T& type, std::uint64_t len)          {
        return [type, len](std::string_view name) {
            return var<T[]> { type, name, len };
        };
    }
}

#endif
