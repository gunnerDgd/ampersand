#include <iostream>

#include "ap/core.hpp"
#include "ap/meta.hpp"

struct MyPack                             {
    static auto name() { return "MyPack"; }
};

int main() {
    auto pack = ap::pack {
        MyPack  {},
        ap::var { ap::i8, "Var1" }
    };

    ap::var pack_var  { pack, "Var"  };
    ap::var pack_var2 { pack, "Var2" };
    
    auto ret = (pack_var = pack_var2);

    std::cout << typeid (ret).name() << std::endl;

    std::cout << ap::name (pack) << std::endl;
    std::cout << ap::name (ap::sub<0>(pack)) << std::endl;
}