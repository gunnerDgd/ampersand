#ifndef AP_TRANS_FN_HPP
#define AP_TRANS_FN_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trans/trans.hpp>
#include <ap/trait.hpp>

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
        auto make(str_t);
        auto make(auto&);

        void src(auto&&, ap::meta::op);
        void arg(auto&&, ap::meta::var);
        void arg(auto&&, str_t, str_t);
        void ret(auto&&, str_t);
        
        void ret_f64(auto&&);
        void ret_f32(auto&&);

        void ret_u64(auto&&);
        void ret_i64(auto&&);

        void ret_u32(auto&&);
        void ret_i32(auto&&);

        void ret_u16(auto&&);
        void ret_i16(auto&&);

        void ret_u8 (auto&&);
        void ret_i8 (auto&&);

        
    };
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
    auto 
        fn<T, trans::ops<U...>>::make
            (auto& fn)                {
                return trait::make(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, ap::meta::var arg) {
                auto type = meta::type(arg);
                auto name = meta::name(arg);

                if (type.index() == 0) trait::arg (fn, std::get<0>(type), name);
                if (type.index() == 1) trait::arg (fn, std::get<1>(type), name);
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, str_t type, str_t name) { 
                trait::arg(fn, type, name); 
    }
}

namespace ap::trans {
    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret
            (auto && fn, str_t name) { 
                trait::ret(fn, name); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_f64
            (auto&& fn)           {
                trait::ret_f64(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_f32
            (auto&& fn)           {
                trait::ret_f32(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_u64
            (auto&& fn) { 
                trait::ret_u64(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_i64
            (auto&& fn)           {
                trait::ret_i64(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_u32
            (auto&& fn)           {
                trait::ret_u32(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_i32
            (auto&& fn)           {
                trait::ret_i32(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_u16
            (auto&& fn)           {
                trait::ret_u16(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_i16
            (auto&& fn)           {
                trait::ret_i16(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_u8
            (auto&& fn)          {
                trait::ret_u8(fn); 
    }

    template <typename T, typename... U>
    void 
        fn<T, trans::ops<U...>>::ret_i8
            (auto&& fn)          {
                trait::ret_i8(fn);
    }
}

#endif
