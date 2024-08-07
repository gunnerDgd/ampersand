#ifndef AP_TRANS_FN_HPP
#define AP_TRANS_FN_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trans/trans.hpp>
#include <ap/trait.hpp>

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
        template <typename N, typename... P, typename... A>  auto operator()(ap::fn<ap::pack<N, P...>(A...)>);
        template <typename N, typename... P>                 auto operator()(ap::fn<ap::pack<N, P...>(void)>);

        template <is::num_t R, typename... A> auto operator()(ap::fn<R(A...)>);
        template <is::num_t R>                auto operator()(ap::fn<R(void)>);

        template <typename... A> auto operator()(ap::fn<void(A...)>);

        auto operator()(ap::fn<void()> func)       {
            auto fn = trait::make (ap::name (func));

            if (!func.src.has_value()) return trait::make(fn);
            auto src = func.src.value();

            for (auto&& pos : src) this->src(pos);
            return trait::make (fn);
        }
        
        auto make(str_t name) { return trait::make(name); }
        auto make(auto& fn)   { return trait::make(fn); }

        template <is::pack_t V> void arg (auto&&, ap::var<V>);
        template <is::num_t V>  void arg (auto&&, ap::var<V>);
        void arg (auto&&, ap::meta::var);

        void arg (auto&& fn, str_t type, str_t name) { trait::arg(fn, type, name); }
        void ret (auto&& fn, str_t name)             { trait::ret(fn, name); }

        void ret_f64(auto&& fn) { trait::ret_f64(fn); }
        void ret_f32(auto&& fn) { trait::ret_f32(fn); }

        void ret_u64(auto&& fn) { trait::ret_u64(fn); }
        void ret_i64(auto&& fn) { trait::ret_i64(fn); }

        void ret_u32(auto&& fn) { trait::ret_u32(fn); }
        void ret_i32(auto&& fn) { trait::ret_i32(fn); }

        void ret_u16(auto&& fn) { trait::ret_u16(fn); }
        void ret_i16(auto&& fn) { trait::ret_i16(fn); }

        void ret_u8 (auto&& fn) { trait::ret_u8 (fn); }
        void ret_i8 (auto&& fn) { trait::ret_i8 (fn); }

        template <opc C, typename... V>
        void src (auto&& fn, ap::op<C, V...> op) { trait::src(this->ops(op)); }
        void src (auto&& fn, ap::meta::op op)    { trait::src(this->ops(op)); }
    };
}

namespace ap::trans                                 {
    template <typename T, typename... U>
    template <is::pack_t V>
    void
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, ap::var<V> var)   {
                auto pack = ap::type (var);
                auto name = ap::name (var);

                trait::arg (ap::name (pack), name);
    }

    template <typename T, typename... U>
    template <is::num_t V>
    void
        fn<T, trans::ops<U...>>::arg
            (auto&& fn, ap::var<V> var)                                                           {
                if constexpr (std::same_as<V, ap::types::f64_t>) trait::arg_f64(fn, ap::name(var));
                if constexpr (std::same_as<V, ap::types::f32_t>) trait::arg_f32(fn, ap::name(var));

                if constexpr (std::same_as<V, ap::types::u64_t>) trait::arg_u64(fn, ap::name(var));
                if constexpr (std::same_as<V, ap::types::i64_t>) trait::arg_i64(fn, ap::name(var));

                if constexpr (std::same_as<V, ap::types::u32_t>) trait::arg_u32(fn, ap::name(var));
                if constexpr (std::same_as<V, ap::types::i32_t>) trait::arg_i32(fn, ap::name(var));

                if constexpr (std::same_as<V, ap::types::u16_t>) trait::arg_u16(fn, ap::name(var));
                if constexpr (std::same_as<V, ap::types::i16_t>) trait::arg_i16(fn, ap::name(var));

                if constexpr (std::same_as<V, ap::types::u8_t>)  trait::arg_u8 (fn, ap::name(var));
                if constexpr (std::same_as<V, ap::types::i8_t>)  trait::arg_i8 (fn, ap::name(var));
    }
}

namespace ap::trans                                                                                      {
    template <typename T, typename... U>
    template <typename N, typename... P, typename... A>  
    auto 
        fn<T, trans::ops<U...>>::operator()
            (ap::fn<ap::pack<N, P...>(A...)> func)  {
                auto fn = trait::make(ap::name(func));

                trait::ret (fn, N::name());
                [this, &func, &fn]<std::size_t... I>(std::index_sequence<I...>) {
                    this->arg (fn, ap::arg<I>(func));
                }   (std::make_index_sequence<sizeof...(A)> {});

                if (!func.src.has_value()) return trait::make (fn);
                auto src = func.src.value();

                for (auto&& pos : src) this->src (pos);
                return trait::make (fn);
    }

    template <typename T, typename... U>
    template <typename N, typename... P, typename... A>  
    auto 
        fn<T, trans::ops<U...>>::operator()
            (ap::fn<ap::pack<N, P...>(A...)> func)  {
                auto fn = trait::make(ap::name(func));
                trait::ret (fn, N::name());

                if (!func.src.has_value()) return trait::make(fn);
                auto src = func.src.value();

                for (auto&& pos : src) this->src(pos);
                return trait::make (fn);
    }

    template <typename T, typename... U>
    template <is::num_t R, typename... A> 
    auto 
        fn<T, trans::ops<U...>>::operator()
            (ap::fn<R(A...)> func)                     {
                auto fn = trait::make (ap::name (func));

                if constexpr (std::same_as<R, ap::types::f64_t>) this->ret_f64(fn);
                if constexpr (std::same_as<R, ap::types::f32_t>) this->ret_f32(fn);

                if constexpr (std::same_as<R, ap::types::u64_t>) this->ret_u64(fn);
                if constexpr (std::same_as<R, ap::types::i64_t>) this->ret_i64(fn);

                if constexpr (std::same_as<R, ap::types::u32_t>) this->ret_u32(fn);
                if constexpr (std::same_as<R, ap::types::i32_t>) this->ret_i32(fn);

                if constexpr (std::same_as<R, ap::types::u16_t>) this->ret_u16(fn);
                if constexpr (std::same_as<R, ap::types::i16_t>) this->ret_i16(fn);

                if constexpr (std::same_as<R, ap::types::u8_t>)  this->ret_u8 (fn);
                if constexpr (std::same_as<R, ap::types::i8_t>)  this->ret_i8 (fn);

                [this, &func, &fn]<std::size_t... I>(std::index_sequence<I...>) {
                    this->arg (fn, ap::arg<I>(func));
                }   (std::make_index_sequence<sizeof...(A)> {});


                if (!func.src.has_value()) return trait::make(fn);
                auto src = func.src.value();

                for (auto&& pos : src) this->src(pos);
                return trait::make (fn);
    }

    template <typename T, typename... U>
    template <is::num_t R>
    auto 
        fn<T, trans::ops<U...>>::operator()
            (ap::fn<R(void)> func)                     {
                auto fn = trait::make (ap::name (func));

                if constexpr (std::same_as<R, ap::types::f64_t>) this->ret_f64(fn);
                if constexpr (std::same_as<R, ap::types::f32_t>) this->ret_f32(fn);

                if constexpr (std::same_as<R, ap::types::u64_t>) this->ret_u64(fn);
                if constexpr (std::same_as<R, ap::types::i64_t>) this->ret_i64(fn);

                if constexpr (std::same_as<R, ap::types::u32_t>) this->ret_u32(fn);
                if constexpr (std::same_as<R, ap::types::i32_t>) this->ret_i32(fn);

                if constexpr (std::same_as<R, ap::types::u16_t>) this->ret_u16(fn);
                if constexpr (std::same_as<R, ap::types::i16_t>) this->ret_i16(fn);

                if constexpr (std::same_as<R, ap::types::u8_t>)  this->ret_u8 (fn);
                if constexpr (std::same_as<R, ap::types::i8_t>)  this->ret_i8 (fn);

                if (!func.src.has_value()) return trait::make(fn);
                auto src = func.src.value();

                for (auto&& pos : src) this->src(pos);
                return trait::make (fn);
    }

    template <typename T, typename... U>
    template <typename... A> 
    auto 
        fn<T, trans::ops<U...>>::operator()
            (ap::fn<void(A...)> func)                  {
                auto fn = trait::make (ap::name (func));

                [this, &func, &fn]<std::size_t... I>(std::index_sequence<I...>) {
                    this->arg (fn, ap::arg<I>(func));
                }   (std::make_index_sequence<sizeof...(A)> {});

                if (!func.src.has_value()) return trait::make(fn);
                auto src = func.src.value();

                for (auto&& pos : src) this->src(pos);
                return trait::make (fn);
    }
}

#endif
