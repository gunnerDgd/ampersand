#ifndef AP_META_OPE_HPP
#define AP_META_OPE_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

#include <ap/meta/ope/func.hpp>
#include <ap/meta/ope/var.hpp>
#include <ap/meta/ope/num.hpp>
#include <ap/meta/ope/op.hpp>

#include <string_view>
#include <type_traits>

#include <variant>
#include <optional>


namespace ap::meta                                          {
    class ope                                               {
        template <typename... T> friend class trans::boolean;
        template <typename... T> friend class trans::func;
        template <typename... T> friend class trans::mem;
        template <typename... T> friend class trans::ari;
        template <typename... T> friend class trans::bit;
        template <typename... T> friend class trans::cmp;
        template <typename... T> friend class trans::ord;

        template <typename... T> friend class trans::pack;
        template <typename... T> friend class trans::var;
        template <typename... T> friend class trans::ops;
        template <typename... T> friend class trans::op;
        template <typename... T> friend class trans::fn;

        using sub_t = std::variant<var, num, op, func>;
        sub_t sub;

        friend std::optional<func> as_func(ope&);
        friend std::optional<var>  as_var (ope&);
        friend std::optional<num>  as_num (ope&);
        friend std::optional<op>   as_op  (ope&);
    public:
        enum class type {
            none,
            func,
            var ,
            num ,
            op
        };

        friend type type(ope&);
    public:
        ope(func&);
        ope(var&);
        ope(num&);
        ope(op&);

        template <typename T, typename U> ope(ap::var<T, U> arg) : sub (var (arg)) {}
        template <is::pack_t T>           ope(ap::var<T>    arg) : sub (var (arg)) {}
        template <is::num_t  T>           ope(ap::var<T>    arg) : sub (var (arg)) {}

        ope(std::floating_point auto arg) : sub (ap::meta::num (arg)) {}
        ope(std::integral       auto arg) : sub (ap::meta::num (arg)) {}

        template <ap::opc C, typename... T> ope(ap::op<C, T...> arg) : sub (ap::meta::op(arg)) {}
        template <typename... T>            ope(ap::fn<T...> fn)     : sub (func(fn))          {}
    };

    
}

namespace ap::meta      {
    ope::type type(ope&);
}

namespace ap::meta                   {
    std::optional<func> as_func(ope&);
    std::optional<var>  as_var (ope&);
    std::optional<num>  as_num (ope&);
    std::optional<op>   as_op  (ope&);
}

#endif
