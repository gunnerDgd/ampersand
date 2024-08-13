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
        using len_t = std::uint64_t;
        using idx_t = type_id;

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

        friend std::variant <str_t, type_id> type(var&);
        friend std::optional<str_t>          self(var&);
        friend std::optional<str_t>          name(var&);
        friend len_t                         len (var&);
        
        str_t self;
        str_t name;
        str_t type;
        idx_t idx;
        len_t len;

    public:
        template <typename T, is::pack_t U> var(ap::var<T, ap::var<U>>);
        template <typename T, is::num_t  U> var(ap::var<T, ap::var<U>>);
        
        template <is::pack_t  T>            var(ap::var<T[]>);
        template <is::num_t   T>            var(ap::var<T[]>);

        template <is::pack_t  T>            var(ap::var<T>);
        template <is::num_t   T>            var(ap::var<T>);
    };

    template <typename T, is::pack_t U>
    var::var(ap::var<T, ap::var<U>> var)
        : name(ap::name(var)),
          idx (type_id::pack),
          len (1)
           
                                        {
            auto self = ap::self(var);
            auto type = ap::type(var);

            this->type = ap::name (type);
            this->self = ap::name (self);
    }

    template <typename T, is::num_t U>
    var::var(ap::var<T, ap::var<U>> var)
        : name(ap::name(var)),
          len (1)
                                                                               {
            auto  self = ap::self (var) ;
            this->self = ap::name (self);

            if constexpr (std::same_as<U, ap::types::i64_t>) idx = type_id::i64;
            if constexpr (std::same_as<U, ap::types::i32_t>) idx = type_id::i32;
            if constexpr (std::same_as<U, ap::types::i16_t>) idx = type_id::i16;
            if constexpr (std::same_as<U, ap::types::i8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<U, ap::types::u64_t>) idx = type_id::u64;
            if constexpr (std::same_as<U, ap::types::u32_t>) idx = type_id::u32;
            if constexpr (std::same_as<U, ap::types::u16_t>) idx = type_id::u16;
            if constexpr (std::same_as<U, ap::types::u8_t>)  idx = type_id::u8;

            if constexpr (std::same_as<U, ap::types::f64_t>) idx = type_id::f64;
            if constexpr (std::same_as<U, ap::types::f32_t>) idx = type_id::f32;
    }

    template <is::pack_t T>
    var::var(ap::var<T> var)
        : name(ap::name(var)),
          idx (type_id::pack),
          len (1)
                                       {
            auto  type = ap::type(var) ;
            this->type = ap::name(type);
    }

    template <is::num_t T>
    var::var(ap::var<T> var)
        : name(ap::name(var)),
          len (1)
                                                                               {
            if constexpr (std::same_as<T, ap::types::i64_t>) idx = type_id::i64;
            if constexpr (std::same_as<T, ap::types::i32_t>) idx = type_id::i32;
            if constexpr (std::same_as<T, ap::types::i16_t>) idx = type_id::i16;
            if constexpr (std::same_as<T, ap::types::i8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<T, ap::types::u64_t>) idx = type_id::u64;
            if constexpr (std::same_as<T, ap::types::u32_t>) idx = type_id::u32;
            if constexpr (std::same_as<T, ap::types::u16_t>) idx = type_id::u16;
            if constexpr (std::same_as<T, ap::types::u8_t>)  idx = type_id::u8;

            if constexpr (std::same_as<T, ap::types::f64_t>) idx = type_id::f64;
            if constexpr (std::same_as<T, ap::types::f32_t>) idx = type_id::f32;
    }

    template <is::pack_t T>
    var::var(ap::var<T[]> var)
        : name(ap::name(var)),
          len (ap::len (var)),
          idx (type_id::pack)
                                       {
            auto  type = ap::type(var) ;
            this->type = ap::name(type);
    }

    template <is::num_t T>
    var::var(ap::var<T[]> var)
        : name(ap::name(var)),
          len (ap::len (var))
                                                                               {
            if constexpr (std::same_as<T, ap::types::i64_t>) idx = type_id::i64;
            if constexpr (std::same_as<T, ap::types::i32_t>) idx = type_id::i32;
            if constexpr (std::same_as<T, ap::types::i16_t>) idx = type_id::i16;
            if constexpr (std::same_as<T, ap::types::i8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<T, ap::types::u64_t>) idx = type_id::u64;
            if constexpr (std::same_as<T, ap::types::u32_t>) idx = type_id::u32;
            if constexpr (std::same_as<T, ap::types::u16_t>) idx = type_id::u16;
            if constexpr (std::same_as<T, ap::types::u8_t>)  idx = type_id::i8;

            if constexpr (std::same_as<T, ap::types::f64_t>) idx = type_id::f64;
            if constexpr (std::same_as<T, ap::types::f32_t>) idx = type_id::f32;
    }
}

namespace ap::meta                                     {
    std::variant <std::string_view, type_id> type(var&);
    std::optional<std::string_view>          self(var&);
    std::optional<std::string_view>          name(var&);
    std::uint64_t                            len (var&);
}

#endif
