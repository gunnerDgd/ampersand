#ifndef AP_TRANS_PACK_HPP
#define AP_TRANS_PACK_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::trans                     {
    template <typename M, typename Trait>
    class pack <M, Trait>                   {
        M mod;
    public:
        using str_t = std::string_view;
        using ret_t = typename Trait::ret_t;
        using trait = typename Trait;
        using mod_t = M;

        template <typename... Arg> pack (Arg&&... arg) : mod (std::forward<Arg>(arg)...) {}
    public:
        auto  push(str_t);
        auto  pop ();

        template <typename N, typename... T>
        auto  operator()(ap::pack<N, T...>&);
        auto  operator()(meta::pack&);

        template <is::pack_t V> auto operator()(ap::var<V>);
        template <is::num_t  V> auto operator()(ap::var<V>);
        auto operator()(meta::var);
        ret_t var  (str_t, str_t);

        ret_t f64  (str_t);
        ret_t f32  (str_t);

        ret_t u64  (str_t);
        ret_t i64  (str_t);

        ret_t u32  (str_t);
        ret_t i32  (str_t);

        ret_t u16  (str_t);
        ret_t i16  (str_t);

        ret_t u8   (str_t);
        ret_t i8   (str_t);
    };

    template <typename Trait>
    class pack <Trait>                     {
    public:
        using str_t = std::string_view;
        using ret_t = typename Trait::ret_t;
        using trait = typename Trait;
    public:
        auto  push(str_t);
        auto  pop ();

        template <typename N, typename... T>
        auto  operator()(ap::pack<N, T...>&);
        auto  operator()(meta::pack&);

        template <is::pack_t V> auto operator()(ap::var<V>);
        template <is::num_t  V> auto operator()(ap::var<V>);
        auto operator()(meta::var);
        ret_t var(str_t, str_t);

        ret_t f64(str_t);
        ret_t f32(str_t);

        ret_t u64(str_t);
        ret_t i64(str_t);

        ret_t u32(str_t);
        ret_t i32(str_t);

        ret_t u16(str_t);
        ret_t i16(str_t);

        ret_t u8(str_t);
        ret_t i8(str_t);
    };
}

namespace ap::trans                                                                {
    template <typename T, typename U>
    template <is::pack_t V>
    auto
        pack<T, U>::operator()
            (ap::var<V> var)                     {
                auto type = ap::type (var);
                auto name = ap::name (var);

                return pack(ap::name(type), name);
    }

    template <typename T, typename U>
    template <is::num_t V>
    auto
        pack<T, U>::operator()
            (ap::var<V> var)                                                     {
                if constexpr (std::same_as<V, f64_t>) return f64 (ap::name (var));
                if constexpr (std::same_as<V, f32_t>) return f32 (ap::name (var));

                if constexpr (std::same_as<V, u64_t>) return u64 (ap::name (var));
                if constexpr (std::same_as<V, i64_t>) return i64 (ap::name (var));

                if constexpr (std::same_as<V, u32_t>) return u32 (ap::name (var));
                if constexpr (std::same_as<V, i32_t>) return i32 (ap::name (var));

                if constexpr (std::same_as<V, u16_t>) return u16 (ap::name (var));
                if constexpr (std::same_as<V, i16_t>) return i16 (ap::name (var));

                if constexpr (std::same_as<V, u8_t>)  return u8  (ap::name (var));
                if constexpr (std::same_as<V, i8_t>)  return i8  (ap::name (var));
    }

    template <typename T, typename U>
    auto
        pack<T, U>::operator()
            (ap::meta::var var)                                                {
                auto type = ap::meta::type (var);
                auto name = ap::meta::name (var);

                if (type.index() == 0) goto pack;
                if (type.index() == 1) goto num;
                return trait::err(mod);

        pack:   return pack(std::get<0>(type), name);
        num:    auto idx  = std::get<1>(type);

                switch (idx)                                                  {
                    case meta::type_id::f64: return f64 (ap::meta::name (var));
                    case meta::type_id::f32: return f32 (ap::meta::name (var));

                    case meta::type_id::u64: return u64 (ap::meta::name (var));
                    case meta::type_id::i64: return i64 (ap::meta::name (var));

                    case meta::type_id::u32: return u32 (ap::meta::name (var));
                    case meta::type_id::i32: return i32 (ap::meta::name (var));

                    case meta::type_id::u16: return u16 (ap::meta::name (var));
                    case meta::type_id::i16: return i16 (ap::meta::name (var));

                    case meta::type_id::u8 : return u8  (ap::meta::name (var));
                    case meta::type_id::i8 : return i8  (ap::meta::name (var));
                    default                : return trait::err(mod);
                }
    }
}

namespace ap::trans                                                                                                                            {
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::var(str_t type, str_t name) { return trait::var(mod, type, name); }

    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::f64(str_t name) { return trait::f64(mod, name); }
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::f32(str_t name) { return trait::f32(mod, name); }

    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::u64(str_t name) { return trait::u64(mod, name); }
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::i64(str_t name) { return trait::i64(mod, name); }

    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::u32(str_t name) { return trait::u32(mod, name); }
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::i32(str_t name) { return trait::i32(mod, name); }

    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::u16(str_t name) { return trait::u16(mod, name); }
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::i16(str_t name) { return trait::i16(mod, name); }

    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::u8 (str_t name) { return trait::u8 (mod, name); }
    template <typename T, typename U> typename pack<T, U>::ret_t pack<T, U>::i8 (str_t name) { return trait::i8 (mod, name); }

    template <typename T, typename U> typename auto pack<T, U>::push(str_t name) { return trait::push (mod, name); }
    template <typename T, typename U> typename auto pack<T, U>::pop ()           { return trait::pop  (mod); }
}

namespace ap::trans                                                    {
    template <typename M, typename Trait>
    template <typename N, typename... T>
    auto
        pack<M, Trait>::operator()
            (ap::pack<N, T...> & arg)                                        {
                push (ap::name (arg));
                [this, &arg] <std::size_t... I> (std::index_sequence<I...>) {
                    ((*this)(ap::sub<I>(arg)), ...);
                }   (std::make_index_sequence<sizeof...(T)>{});

                return pop();
    }

    template <typename M, typename Trait>
    auto
        pack<M, Trait>::operator()
            (ap::meta::pack& arg)          {
                push (ap::meta::name (arg));
                for (auto&& pos : arg.sub) {
                    (*this)(pos);
                }

                return pop();
    }
}



// For pack<T>

namespace ap::trans                                                                {
    template <typename T>
    template <is::pack_t V>
    auto
        pack<T>::operator()
            (ap::var<V> var)                     {
                auto type = ap::type (var);
                auto name = ap::name (var);

                return pack(ap::name(type), name);
    }

    template <typename T>
    template <is::num_t V>
    auto
        pack<T>::operator()
            (ap::var<V> var)                                                    {
                if constexpr (std::same_as<V, f64_t>) return f64 (ap::name (var));
                if constexpr (std::same_as<V, f32_t>) return f32 (ap::name (var));

                if constexpr (std::same_as<V, u64_t>) return u64 (ap::name (var));
                if constexpr (std::same_as<V, i64_t>) return i64 (ap::name (var));

                if constexpr (std::same_as<V, u32_t>) return u32 (ap::name (var));
                if constexpr (std::same_as<V, i32_t>) return i32 (ap::name (var));

                if constexpr (std::same_as<V, u16_t>) return u16 (ap::name (var));
                if constexpr (std::same_as<V, i16_t>) return i16 (ap::name (var));

                if constexpr (std::same_as<V, u8_t>)  return u8  (ap::name (var));
                if constexpr (std::same_as<V, i8_t>)  return i8  (ap::name (var));
    }

    template <typename T>
    auto
        pack<T>::operator()
            (ap::meta::var var)                                                {
                auto type = ap::meta::type (var);
                auto name = ap::meta::name (var);

                if (type.index() == 0) goto pack;
                if (type.index() == 1) goto num;
                return trait::err();

        pack:   return pack(std::get<0>(type), name);
        num:    auto idx  = std::get<1>(type);

                switch (idx)                                                  {
                    case meta::type_id::f64: return f64 (ap::meta::name (var));
                    case meta::type_id::f32: return f32 (ap::meta::name (var));

                    case meta::type_id::u64: return u64 (ap::meta::name (var));
                    case meta::type_id::i64: return i64 (ap::meta::name (var));

                    case meta::type_id::u32: return u32 (ap::meta::name (var));
                    case meta::type_id::i32: return i32 (ap::meta::name (var));

                    case meta::type_id::u16: return u16 (ap::meta::name (var));
                    case meta::type_id::i16: return i16 (ap::meta::name (var));

                    case meta::type_id::u8 : return u8  (ap::meta::name (var));
                    case meta::type_id::i8 : return i8  (ap::meta::name (var));
                    default                : return trait::err();
                }
    }
}

namespace ap::trans                                                                                                     {
    template <typename T> typename pack<T>::ret_t pack<T>::var(str_t type, str_t name) { return trait::var(type, name); }

    template <typename T> typename pack<T>::ret_t pack<T>::f64(str_t name) { return trait::f64(name); }
    template <typename T> typename pack<T>::ret_t pack<T>::f32(str_t name) { return trait::f32(name); }

    template <typename T> typename pack<T>::ret_t pack<T>::u64(str_t name) { return trait::u64(name); }
    template <typename T> typename pack<T>::ret_t pack<T>::i64(str_t name) { return trait::i64(name); }

    template <typename T> typename pack<T>::ret_t pack<T>::u32(str_t name) { return trait::u32(name); }
    template <typename T> typename pack<T>::ret_t pack<T>::i32(str_t name) { return trait::i32(name); }

    template <typename T> typename pack<T>::ret_t pack<T>::u16(str_t name) { return trait::u16(name); }
    template <typename T> typename pack<T>::ret_t pack<T>::i16(str_t name) { return trait::i16(name); }

    template <typename T> typename pack<T>::ret_t pack<T>::u8 (str_t name) { return trait::u8 (name); }
    template <typename T> typename pack<T>::ret_t pack<T>::i8 (str_t name) { return trait::i8 (name); }

    template <typename T> typename auto pack<T>::push(str_t name) { return trait::push (name); }
    template <typename T> typename auto pack<T>::pop ()           { return trait::pop  (); }
}

namespace ap::trans                                                          {
    template <typename Trait>
    template <typename N, typename... T>
    auto
        pack<Trait>::operator()
            (ap::pack<N, T...> & arg)                                       {
                push (ap::name (arg));
                [this, &arg] <std::size_t... I> (std::index_sequence<I...>) {
                    (((*this)(ap::sub<I>(arg))), ...);
                }   (std::make_index_sequence<sizeof...(T)>{});

                return pop();
    }

    template <typename Trait>
    auto
        pack<Trait>::operator()
            (ap::meta::pack& arg)          {
                push (ap::meta::name (arg));
                for (auto&& pos : arg.sub) {
                    (*this)(pos);
                }

                return pop();
    }
}

#endif
