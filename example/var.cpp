#include <ap/core.hpp>
#include <ap/meta.hpp>
#include <ap/grammar.hpp>

#include <iostream>

int main()                     {
    ap::var a { ap::i8_t, "a" };
    auto b = a + 3 + 4;
    auto c = ~a;

    ap::meta::op op { b };

    ap::meta::var var { a };
    std::cout << ap::meta::name(var).value() << std::endl;

    std::cout << typeid(a + 3).name() << std::endl;
    std::cout << typeid(a - 3).name() << std::endl;
    std::cout << typeid(a * 3).name() << std::endl;
    std::cout << typeid(a / 3).name() << std::endl;
    std::cout << typeid(a % 3).name() << std::endl;
    std::cout << b.arg << std::endl;
    std::cout << ap::name(a)          << std::endl;
}