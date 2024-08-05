#ifndef AP_OPS_VAR_HPP
#define AP_OPS_VAR_HPP

#include <string_view>
#include <variant>
#include <optional>

#include <type_traits>
#include <concepts>

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

namespace ap::meta                     {
    class var                          {
        using str_t = std::string_view;
        using idx_t = type_id;

        friend std::variant <str_t, type_id> type(var&);
        friend std::optional<str_t>          self(var&);
        friend std::optional<str_t>          name(var&);
        
        str_t self;
        str_t name;
        str_t type;
        idx_t idx;

    public:
        template <typename T, is::pack_t U> var(ap::var<T, ap::var<U>>);
        template <typename T, is::num_t  U> var(ap::var<T, ap::var<U>>);
        template <is::pack_t T>             var(ap::var<T>);
        template <is::num_t  T>             var(ap::var<T>);
    };

    template <typename T, is::pack_t U>
    var::var(ap::var<T, ap::var<U>> var)
        : name(ap::name(var)),
          idx (type_id::pack)        {
            auto self = ap::self(var);
            auto type = ap::type(var);

            this->type = ap::name (type);
            this->self = ap::name (self);
    }

    template <typename T, is::num_t U>
    var::var(ap::var<T, ap::var<U>> var)
        : name(ap::name(var))           {
            auto  self = ap::self (var) ;
            this->self = ap::name (self);

            if constexpr (std::same_as<U, ap::i64_t>) idx = type_id::i64;
            if constexpr (std::same_as<U, ap::i32_t>) idx = type_id::i32;
            if constexpr (std::same_as<U, ap::i16_t>) idx = type_id::i16;
            if constexpr (std::same_as<U, ap::i8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<U, ap::u64_t>) idx = type_id::u64;
            if constexpr (std::same_as<U, ap::u32_t>) idx = type_id::u32;
            if constexpr (std::same_as<U, ap::u16_t>) idx = type_id::u16;
            if constexpr (std::same_as<U, ap::u8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<U, ap::f64_t>) idx = type_id::f64;
            if constexpr (std::same_as<U, ap::f32_t>) idx = type_id::f32;
    }

    template <is::pack_t T>
    var::var(ap::var<T> var)
        : name(ap::name(var)),
          idx (type_id::pack)          {
            auto  type = ap::type(var) ;
            this->type = ap::name(type);
    }

    template <is::num_t T>
    var::var(ap::var<T> var)
        : name(ap::name(var))                                           {
            if constexpr (std::same_as<T, ap::i64_t>) idx = type_id::i64;
            if constexpr (std::same_as<T, ap::i32_t>) idx = type_id::i32;
            if constexpr (std::same_as<T, ap::i16_t>) idx = type_id::i16;
            if constexpr (std::same_as<T, ap::i8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<T, ap::u64_t>) idx = type_id::u64;
            if constexpr (std::same_as<T, ap::u32_t>) idx = type_id::u32;
            if constexpr (std::same_as<T, ap::u16_t>) idx = type_id::u16;
            if constexpr (std::same_as<T, ap::u8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<T, ap::f64_t>) idx = type_id::f64;
            if constexpr (std::same_as<T, ap::f32_t>) idx = type_id::f32;
    }
}

namespace ap::meta                                     {
    std::variant <std::string_view, type_id> type(var&);
    std::optional<std::string_view>          self(var&);
    std::optional<std::string_view>          name(var&);
}

#endif
