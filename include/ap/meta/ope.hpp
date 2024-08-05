#ifndef AP_META_OPE_HPP
#define AP_META_OPE_HPP

#include <ap/core/core.hpp>
#include <ap/trait.hpp>

#include "ope/var.hpp"
#include "ope/num.hpp"
#include "ope/op.hpp"


#include <string_view>
#include <type_traits>

#include <variant>
#include <optional>


namespace ap::meta                              {
    class ope                                   {
        using sub_t = std::variant<var, num, op>;
        sub_t sub;

        friend std::optional<var> as_var(ope&);
        friend std::optional<num> as_num(ope&);
        friend std::optional<op>  as_op (ope&);
    public:
        ope(var&);
        ope(num&);
        ope(op&);

        template <typename T, typename U> ope(ap::var<T, U> arg) : sub (var (arg)) {}
        template <is::pack_t T>           ope(ap::var<T>    arg) : sub (var (arg)) {}
        template <is::num_t  T>           ope(ap::var<T>    arg) : sub (var (arg)) {}

        ope(std::floating_point auto arg) : sub (ap::meta::num (arg)) {}
        ope(std::integral       auto arg) : sub (ap::meta::num (arg)) {}

        template <ap::opc C, typename... T> ope(ap::op<C, T...> arg) : sub (ap::meta::op(arg)) {}
    };

    std::optional<var> as_var(ope&);
    std::optional<num> as_num(ope&);
    std::optional<op>  as_op (ope&);
}

#endif
