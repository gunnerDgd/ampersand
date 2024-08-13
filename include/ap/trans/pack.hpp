#ifndef AP_TRANS_PACK_HPP
#define AP_TRANS_PACK_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/ope.hpp>

#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::trans                     {
    
    template <typename T>
    class pack <T>                      {
    public:
        using str_t = std::string_view;
    public:
        auto operator()(ap::meta::pack);

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
                if (!name.has_value()) return;

                if (type.index() == 0) goto pack;
                if (type.index() == 1) goto num;

        pack:   self.var(std::get<0>(type), name.value());
                return;
        num:    auto idx  = std::get<1>(type);

                switch (idx)                                               {
                    case meta::type_id::f64: self.f64 (name.value()); break;
                    case meta::type_id::f32: self.f32 (name.value()); break;

                    case meta::type_id::u64: self.u64 (name.value()); break;
                    case meta::type_id::i64: self.i64 (name.value()); break;

                    case meta::type_id::u32: self.u32 (name.value()); break;
                    case meta::type_id::i32: self.i32 (name.value()); break;

                    case meta::type_id::u16: self.u16 (name.value()); break;
                    case meta::type_id::i16: self.i16 (name.value()); break;

                    case meta::type_id::u8 : self.u8  (name.value()); break;
                    case meta::type_id::i8 : self.i8  (name.value()); break;
                }
    }
}

namespace ap::trans                                                                                      {
    template <typename T> void pack<T>::var(auto&& self, str_t type, str_t name) { self.var(type, name); }

    template <typename T> void pack<T>::f64(auto&& self, str_t name)  { self.f64(name); }
    template <typename T> void pack<T>::f32(auto&& self, str_t name)  { self.f32(name); }

    template <typename T> void pack<T>::u64(auto&& self, str_t name)  { self.u64(name); }
    template <typename T> void pack<T>::i64(auto&& self, str_t name)  { self.i64(name); }

    template <typename T> void pack<T>::u32(auto&& self, str_t name)  { self.u32(name); }
    template <typename T> void pack<T>::i32(auto&& self, str_t name)  { self.i32(name); }

    template <typename T> void pack<T>::u16(auto&& self, str_t name)  { self.u16(name); }
    template <typename T> void pack<T>::i16(auto&& self, str_t name)  { self.i16(name); }

    template <typename T> void pack<T>::u8 (auto&& self, str_t name)  { self.u8 (name); }
    template <typename T> void pack<T>::i8 (auto&& self, str_t name)  { self.i8 (name); }
}

namespace ap::trans                                {
    template <typename T>
    auto
        pack<T>::operator()
            (ap::meta::pack arg)                   {
                auto ret = T (ap::meta::name (arg));
                for (auto&& pos : arg.sub)         {
                    this->var(ret, pos);
                }

                return ret;
    }
}

#endif
