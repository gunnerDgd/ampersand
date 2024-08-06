#include <iostream>

#include "ap/core.hpp"
#include "ap/meta.hpp"

struct MyPack                             {
    static auto name() { return "MyPack"; }
};

int main()                     {
    auto pack = ap::pack       {
        MyPack()               ,
        ap::let(ap::i8_t)("v1"),
        ap::let(ap::i8_t)("v2"),
        ap::let(ap::i8_t)("v3"),
        ap::let(ap::i8_t)("v4"),
        ap::let(ap::i8_t)("v5"),
    };

    ap::var pack_var  { pack, "Var"  };
    ap::var pack_var2 { pack, "Var2" };
    
    auto ret = (pack_var = pack_var2);

    std::cout << typeid (ret).name() << std::endl;

    std::cout << ap::name (pack) << std::endl;
    std::cout << ap::name (ap::sub<0>(pack)) << std::endl;
}