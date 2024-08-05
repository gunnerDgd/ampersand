#include "ap/core/float.hpp"
#include <ap/core/trait/float.hpp>

#include <iostream>

int main()                               {
    static_assert(ap::float_t<ap::f32_t>);
    static_assert(ap::float_t<ap::f64_t>);
    std::cout << "Success !!\n";
}