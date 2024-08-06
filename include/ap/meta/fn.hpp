#ifndef AP_META_FUNC_HPP
#define AP_META_FUNC_HPP

#include <string_view>
#include <list>

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/ope.hpp>
#include <ap/trait.hpp>

namespace ap::meta                                                  {
    class fn                                                        {
        using ret_t = std::variant <std::string_view, meta::type_id>;
        using src_t = std::optional<meta::src>;
        using str_t = std::string_view;
        using arg_t = std::list<var>;

        friend str_t name(ap::meta::fn&);
        str_t name;
        ret_t ret;
        src_t src;
        arg_t arg;
    public:
        template <typename  N, typename... P, typename... A> fn(ap::fn<ap::pack<N, P...>(A...)>);
        template <typename  N, typename... P>                fn(ap::fn<ap::pack<N, P...>(void)>);

        template <is::num_t T, typename... A>                fn(ap::fn<T(A...)>);
        template <is::num_t T>                               fn(ap::fn<T(void)>);

        template <typename... A>                             fn(ap::fn<void(A...)>);
                                                             fn(ap::fn<void(void)>);
    };
}

namespace ap::meta                      {
    std::string_view name(ap::meta::fn&);
}

namespace ap::meta                                       {
    template <typename  N, typename... P, typename... A> 
    fn::fn(ap::fn<ap::pack<N, P...>(A...)> func)
        : name (ap::name(fn)),
          ret  (N ::name())  ,
          src  (func.src)
                                                                        {
            [this, &func] <std::size_t... I>(std::index_sequence<I...>) {
                (arg.emplace_back(ap::arg<I>(func)), ...);
            }   (std::make_index_sequence<sizeof...(A)> {});
    }


    template <typename  N, typename... P>                
    fn::fn(ap::fn<ap::pack<N, P...>(void)> func)
        : name (ap::name (func)),
          ret  (N ::name ())    ,
          src  (func.src)
            {}

    template <is::num_t T, typename... A>                
    fn::fn(ap::fn<T(A...)> func) 
        : name (ap::name (func)),
          src  (func.src)
                                                                                     {
            if constexpr (std::same_as<T, ap::types::i64_t>) ret = meta::type_id::i64;
            if constexpr (std::same_as<T, ap::types::u64_t>) ret = meta::type_id::u64;

            if constexpr (std::same_as<T, ap::types::i32_t>) ret = meta::type_id::i32;
            if constexpr (std::same_as<T, ap::types::u32_t>) ret = meta::type_id::u32;

            if constexpr (std::same_as<T, ap::types::i16_t>) ret = meta::type_id::i16;
            if constexpr (std::same_as<T, ap::types::u16_t>) ret = meta::type_id::u16;

            if constexpr (std::same_as<T, ap::types::i8_t>)  ret = meta::type_id::i8;
            if constexpr (std::same_as<T, ap::types::u8_t>)  ret = meta::type_id::u8;

            if constexpr (std::same_as<T, ap::types::f64_t>) ret = meta::type_id::f64;
            if constexpr (std::same_as<T, ap::types::f32_t>) ret = meta::type_id::f32;

            [this, &func] <std::size_t... I>(std::index_sequence<I...>) {
                (arg.emplace_back(ap::arg<I>(func)), ...);
            }   (std::make_index_sequence<sizeof...(A)> {});
    }


    template <is::num_t T>
    fn::fn(ap::fn<T(void)> func)
        : name (ap::name (func)),
          src  (func.src)
                                                                                     {
            if constexpr (std::same_as<T, ap::types::i64_t>) ret = meta::type_id::i64;
            if constexpr (std::same_as<T, ap::types::u64_t>) ret = meta::type_id::u64;

            if constexpr (std::same_as<T, ap::types::i32_t>) ret = meta::type_id::i32;
            if constexpr (std::same_as<T, ap::types::u32_t>) ret = meta::type_id::u32;

            if constexpr (std::same_as<T, ap::types::i16_t>) ret = meta::type_id::i16;
            if constexpr (std::same_as<T, ap::types::u16_t>) ret = meta::type_id::u16;

            if constexpr (std::same_as<T, ap::types::i8_t>)  ret = meta::type_id::i8;
            if constexpr (std::same_as<T, ap::types::u8_t>)  ret = meta::type_id::u8;

            if constexpr (std::same_as<T, ap::types::f64_t>) ret = meta::type_id::f64;
            if constexpr (std::same_as<T, ap::types::f32_t>) ret = meta::type_id::f32;
    }

    template <typename... A>
    fn::fn(ap::fn<void(A...)> func)
        : name (ap::name (func)),
          src  (func.src)
                                                                        {
            [this, &func] <std::size_t... I>(std::index_sequence<I...>) {
                (arg.emplace_back(ap::arg<I>(func)), ...);
            }   (std::make_index_sequence<sizeof...(A)> {});
    }
}

#endif
