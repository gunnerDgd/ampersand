#ifndef AP_FN_HPP
#define AP_FN_HPP

#include "ap/trait.hpp"
#include "ap/meta/src.hpp"

#include "ap/trait/opc.hpp"

#include <string_view>
#include <optional>
#include <tuple>

namespace ap                                {
    template <opc C, typename... T> class op;
}

namespace ap                         {
    template <typename... T> class fn;
    template <ap::var_t R, ap::var_t... A>
    class fn<R(A...)>                                {
        using arg_t = std::optional<std::tuple<A...>>;
        using str_t = std::string_view;
        using fun_t = R(*)(A...);

        str_t name;
        fun_t fun;
        arg_t arg;
        src   src;
    public:
        fn(str_t, R(&)(A...), A...);
        fn(str_t);
    public:
        auto operator()(A...);
    };
}

#endif
