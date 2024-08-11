#ifndef AP_TRANS_FN_HPP
#define AP_TRANS_FN_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trans/trans.hpp>
#include <ap/trait.hpp>

#include <ap/meta/src.hpp>
#include <ap/meta/fn.hpp>

#include <ap/meta/src.hpp>
#include <ap/meta/fn.hpp>
#include <ap/core/fn.hpp>
#include <string_view>

namespace ap::trans                     {
    template <typename T, typename... U>
    class fn<T, trans::ops<U...>>     {
        using ops_t = trans::ops<U...>;
        ops_t ops;
    public:
        using str_t = std::string_view;
        using trait = T;
    public:
        auto operator()(meta::fn func)       {
            auto fn = T (func.name);

            auto ret = func.ret;
            if (ret.index() == 1) this->ret(fn, std::get<1>(ret));
            if (ret.index() == 2) this->ret(fn, std::get<2>(ret));
            for(auto&& arg : func.arg) this->arg(fn, arg);

            if (!func.src.has_value()) return fn;
            auto& src = func.src.value();

            for (auto& op : src.ops) this->src (fn, op);
            return fn;
        }

        void src(auto&&, ap::meta::op);
        void src(auto&&);

        void arg(auto&&, ap::meta::var);
        void arg(auto&&, str_t, str_t);

        void ret(auto&&, meta::type_id);
        void ret(auto&&, str_t);

        fn(T, trans::ops<U...>);
    };

    template <typename T, typename U> fn(T, U) -> fn<T, U>;
}

namespace ap::trans {
    template <typename T, typename... U>
    fn<T, trans::ops<U...>>::fn
        (T, trans::ops<U...> ops)
            : ops (ops)
                {}
}

namespace ap::trans                           {
    template <typename T, typename... U>
    void
        fn<T, trans::ops<U...>>::src
            (auto&& fn, ap::meta::op op)      {
                fn.src(this->ops(op));
    }

    template <typename T, typename... U>
    void
        fn<T, trans::ops<U...>>::src
            (auto&& fn)        {
                fn.src(fn);
    }
}

namespace ap::trans                     {
    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, ap::meta::var arg) {
                auto type = meta::type(arg);
                auto name = meta::name(arg);

                if (!name.has_value()) return;

                if (type.index() == 0) fn.arg (std::get<0>(type), name.value());
                if (type.index() == 1) fn.arg (std::get<1>(type), name.value());
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, str_t type, str_t name) { 
                fn.arg(type, name); 
    }
}

namespace ap::trans                     {
    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret
            (auto && fn, str_t name) { 
                fn.ret(name); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret
            (auto && fn, meta::type_id type) { 
                fn.ret(type);
    }
}

#endif
