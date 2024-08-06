#include <ap/core.hpp>
#include <ap/meta.hpp>
#include <iostream>

void test1()                         {
    auto a = ap::let (ap::i64_t)("a");
}

auto test2(ap::var<ap::types::i64_t>) {
    return 1;
}

int main()                                          {
    auto fn1 = ap::func()         ()("test1", test1);
    auto fn2 = ap::func(ap::i32_t)(ap::let(ap::i64_t)("arg1"))("test2", test2);
    auto op1 = fn1();
    auto op2 = fn2(3);

    std::cout << typeid(op1).name() << std::endl;
    std::cout << typeid(op2).name() << std::endl;
}