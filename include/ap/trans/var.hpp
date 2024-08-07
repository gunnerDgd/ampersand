#ifndef AP_TRANS_VAR_HPP
#define AP_TRANS_VAR_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::trans                                         {
    template <typename Trait>
    class var<Trait>                  {
    public:
        using str_t = std::string_view;
        using trait = Trait;
    public:
        auto operator()(meta::var&);
        auto pack(str_t, str_t);

        auto f64 (str_t);
        auto f32 (str_t);

        auto u64 (str_t);
        auto i64 (str_t);

        auto u32 (str_t);
        auto i32 (str_t);

        auto u16 (str_t);
        auto i16 (str_t);

        auto u8  (str_t);
        auto i8  (str_t);
    };
}


namespace ap::trans                                                                                     {
    template <typename T> auto var<T>::pack (str_t type, str_t name) { return trait::pack (type, name); }

    template <typename T> auto var<T>::f64(str_t name) { return trait::f64 (name); }
    template <typename T> auto var<T>::f32(str_t name) { return trait::f32 (name); }

    template <typename T> auto var<T>::u64(str_t name) { return trait::u64 (name); }
    template <typename T> auto var<T>::i64(str_t name) { return trait::i64 (name); }

    template <typename T> auto var<T>::u32(str_t name) { return trait::u32 (name); }
    template <typename T> auto var<T>::i32(str_t name) { return trait::i32 (name); }

    template <typename T> auto var<T>::u16(str_t name) { return trait::u16 (name); }
    template <typename T> auto var<T>::i16(str_t name) { return trait::i16 (name); }

    template <typename T> auto var<T>::u8 (str_t name) { return trait::u8  (name); }
    template <typename T> auto var<T>::i8 (str_t name) { return trait::i8  (name); }
}

namespace ap::trans                                                           {
    template <typename T>
    auto
        var<T>::operator()
            (ap::meta::var& var)                                              {
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

#endif
