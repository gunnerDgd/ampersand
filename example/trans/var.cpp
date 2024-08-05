#include <iostream>

#include <ap/trans/var.hpp>
#include <ap/core.hpp>
#include <ap/meta.hpp>

#include <string_view>

struct MyPack                             {
    static auto name() { return "MyPack"; }
};

struct c_trait                    {
    using str_t = std::string_view;
    using ret_t = void;

    static ret_t pack(str_t type, str_t name) { std::cout << "struct " << type << " " << name << ";\n"; }

    static ret_t f64 (str_t name) { std::cout << "double " << name << ";\n"; }
    static ret_t f32 (str_t name) { std::cout << "float "  << name << ";\n"; }

    static ret_t u64 (str_t name) { std::cout << "unsigned long long " << name << ";\n"; }
    static ret_t i64 (str_t name) { std::cout << "long long "          << name << ";\n"; }

    static ret_t u32(str_t name) { std::cout << "unsigned int " << name << ";\n"; }
    static ret_t i32(str_t name) { std::cout << "int "          << name << ";\n"; }

    static ret_t u16(str_t name) { std::cout << "unsigned short " << name << ";\n"; }
    static ret_t i16(str_t name) { std::cout << "short "          << name << ";\n"; }

    static ret_t u8 (str_t name) { std::cout << "unsigned char " << name << ";\n"; }
    static ret_t i8 (str_t name) { std::cout << "char "          << name << ";\n"; }
};

int main()                       {
    ap::trans::var<c_trait> trans;

    auto pack = ap::pack    {
        MyPack            {},
        ap::let(ap::i8) ("a")
    };

    auto i8  = ap::let(ap::i8)  ("a");
    auto u8  = ap::let(ap::u8)  ("a");

    auto i16 = ap::let(ap::i16) ("a");
    auto u16 = ap::let(ap::u16) ("a");

    auto i32 = ap::let(ap::i32) ("a");
    auto u32 = ap::let(ap::u32) ("a");

    auto i64 = ap::let(ap::i64) ("a");
    auto u64 = ap::let(ap::u64) ("a");

    auto var = ap::let(pack) ("a");


    trans(i8);
    trans(u8);

    trans(i16);
    trans(u16);

    trans(i32);
    trans(u32);

    trans(i64);
    trans(u64);

    trans(var);
}