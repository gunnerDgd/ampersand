#include "ap/core/core.hpp"
#include "ap/trait.hpp"
#include <iostream>

int main()                                          {
    static_assert(ap::is::float_t<ap::types::f32_t>);
    static_assert(ap::is::float_t<ap::types::f64_t>);
    std::cout << "Success !!\n";
}