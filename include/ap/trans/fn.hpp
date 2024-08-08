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
            auto fn = this->make (func.name);

            auto ret = func.ret;
            if (ret.index() == 1) this->ret(fn, std::get<1>(ret));
            if (ret.index() == 2) this->ret(fn, std::get<2>(ret));
            for (auto&& arg : func.arg) this->arg(fn, arg);

            if (!func.src.has_value()) return fn;
            auto& src = func.src.value();

            for (auto& op : src.ops) this->src (fn, op);
            return fn;
        }


        auto make(str_t);

        void src(auto&&, ap::meta::op);
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

namespace ap::trans {
    template <typename T, typename... U>
    void
        fn<T, trans::ops<U...>>::src
            (auto&& fn, ap::meta::op op)      {
                trait::src (fn, this->ops(op));
    }
}

namespace ap::trans                     {
    template <typename T, typename... U>
    auto 
        fn<T, trans::ops<U...>>::make
            (str_t name)                {
                return trait::make(name); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, ap::meta::var arg) {
                auto type = meta::type(arg);
                auto name = meta::name(arg);

                if (!name.has_value()) return;

                if (type.index() == 1) trait::arg (fn, std::get<1>(type), name.value());
                if (type.index() == 2) trait::arg (fn, std::get<2>(type), name.value());
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, str_t type, str_t name) { 
                trait::arg(fn, type, name); 
    }
}

namespace ap::trans                     {
    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret
            (auto && fn, str_t name) { 
                trait::ret(fn, name); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret
            (auto && fn, meta::type_id type) { 
                trait::ret(fn, type);
    }
}

#endif
