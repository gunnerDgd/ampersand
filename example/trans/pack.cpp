#include <iostream>

#include <ap/core.hpp>
#include <ap/meta.hpp>

#include <ap/trans/pack.hpp>

#include <string_view>

struct MyPack                             {
    static auto name() { return "MyPack"; }
};

struct c_trait                    {
    using str_t = std::string_view;
    using ret_t = void;

    static ret_t push(str_t name) { std::cout << "struct " << name << " {\n"; }
    static ret_t pop ()           { std::cout << "};\n"; }
    static ret_t err ()           {}

    static ret_t var(str_t type, str_t name) { std::cout << "struct " << type << " " << name << ";\n"; }

    static ret_t f64 (str_t name) { std::cout << "\tdouble " << name << ";\n"; }
    static ret_t f32 (str_t name) { std::cout << "\tfloat "  << name << ";\n"; }

    static ret_t u64 (str_t name) { std::cout << "\tunsigned long long " << name << ";\n"; }
    static ret_t i64 (str_t name) { std::cout << "\tlong long "          << name << ";\n"; }

    static ret_t u32(str_t name) { std::cout << "\tunsigned int " << name << ";\n"; }
    static ret_t i32(str_t name) { std::cout << "\tint "          << name << ";\n"; }

    static ret_t u16(str_t name) { std::cout << "\tunsigned short " << name << ";\n"; }
    static ret_t i16(str_t name) { std::cout << "\tshort "          << name << ";\n"; }

    static ret_t u8 (str_t name) { std::cout << "\tunsigned char " << name << ";\n"; }
    static ret_t i8 (str_t name) { std::cout << "\tchar "          << name << ";\n"; }
};

int main ()                       {
    ap::trans::pack<c_trait> trans;

    auto pack = ap::pack     {
        MyPack             {},
        ap::let(ap::i8) ("a"),
        ap::let(ap::i16)("b"),
        ap::let(ap::i32)("c"),
        ap::let(ap::i64)("d"),

        ap::let(ap::u8) ("e"),
        ap::let(ap::u16)("f"),
        ap::let(ap::u32)("g"),
        ap::let(ap::u64)("h"),
    };

    trans(pack);
}