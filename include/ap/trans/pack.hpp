#ifndef AP_TRANS_PACK_HPP
#define AP_TRANS_PACK_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/ope.hpp>

#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::trans                        {
    
    template <typename Trait>
    class pack <Trait>                     {
    public:
        using str_t = std::string_view;
        using trait = typename Trait;
    public:
        auto make(str_t);

        auto operator()(ap::meta::pack&);

        void var(auto&&, ap::meta::var);
        void var(auto&&, str_t, str_t);

        void f64(auto&&, str_t);
        void f32(auto&&, str_t);

        void u64(auto&&, str_t);
        void i64(auto&&, str_t);

        void u32(auto&&, str_t);
        void i32(auto&&, str_t);

        void u16(auto&&, str_t);
        void i16(auto&&, str_t);

        void u8 (auto&&, str_t);
        void i8 (auto&&, str_t);
    };
}


// For pack<T>

namespace ap::trans                                                                  {
    template <typename T>
    void
        pack<T>::var
            (auto&& self, ap::meta::var var)      {
                auto type = ap::meta::type (var);
                auto name = ap::meta::name (var);

                if (type.index() == 0) goto pack;
                if (type.index() == 1) goto num;

        pack:   trait::var(self, std::get<0>(type), name);
                return;
        num:    auto idx  = std::get<1>(type);

                switch (idx)                                                        {
                    case meta::type_id::f64: f64 (self, ap::meta::name (var)); break;
                    case meta::type_id::f32: f32 (self, ap::meta::name (var)); break;

                    case meta::type_id::u64: u64 (self, ap::meta::name (var)); break;
                    case meta::type_id::i64: i64 (self, ap::meta::name (var)); break;

                    case meta::type_id::u32: u32 (self, ap::meta::name (var)); break;
                    case meta::type_id::i32: i32 (self, ap::meta::name (var)); break;

                    case meta::type_id::u16: u16 (self, ap::meta::name (var)); break;
                    case meta::type_id::i16: i16 (self, ap::meta::name (var)); break;

                    case meta::type_id::u8 : u8  (self, ap::meta::name (var)); break;
                    case meta::type_id::i8 : i8  (self, ap::meta::name (var)); break;
                }
    }
}

namespace ap::trans                                                                                              {
    template <typename T> void pack<T>::var(auto&& self, str_t type, str_t name) { trait::var(self, type, name); }

    template <typename T> void pack<T>::f64(auto&& self, str_t name)  { trait::f64(self, name); }
    template <typename T> void pack<T>::f32(auto&& self, str_t name)  { trait::f32(self, name); }

    template <typename T> void pack<T>::u64(auto&& self, str_t name)  { trait::u64(self, name); }
    template <typename T> void pack<T>::i64(auto&& self, str_t name)  { trait::i64(self, name); }

    template <typename T> void pack<T>::u32(auto&& self, str_t name)  { trait::u32(self, name); }
    template <typename T> void pack<T>::i32(auto&& self, str_t name)  { trait::i32(self, name); }

    template <typename T> void pack<T>::u16(auto&& self, str_t name)  { trait::u16(self, name); }
    template <typename T> void pack<T>::i16(auto&& self, str_t name)  { trait::i16(self, name); }

    template <typename T> void pack<T>::u8 (auto&& self, str_t name)  { trait::u8 (self, name); }
    template <typename T> void pack<T>::i8 (auto&& self, str_t name)  { trait::i8 (self, name); }

    template <typename T> auto pack<T>::make(str_t name) { return trait::make(name); }
}

namespace ap::trans                                   {
    template <typename Trait>
    auto
        pack<Trait>::operator()
            (ap::meta::pack& arg)                     {
                auto ret = make (ap::meta::name (arg));
                for (auto&& pos : arg.sub)            {
                    (*this)(ret, pos);
                }

                return ret;
    }
}

#endif
