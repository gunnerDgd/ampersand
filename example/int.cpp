#include "ap/core.hpp"
#include "ap/trait.hpp"

#include <iostream>

int main ()                                       {
    static_assert(ap::is::int_t<ap::types::i64_t>);
    static_assert(ap::is::int_t<ap::types::u64_t>);

    static_assert(ap::is::int_t<ap::types::i32_t>);
    static_assert(ap::is::int_t<ap::types::u32_t>);

    static_assert(ap::is::int_t<ap::types::i16_t>);
    static_assert(ap::is::int_t<ap::types::u16_t>);

    static_assert(ap::is::int_t<ap::types::i8_t>);
    static_assert(ap::is::int_t<ap::types::u8_t>);

    static_assert(!ap::is::int_t<double>);
    static_assert(!ap::is::int_t<float>);
    static_assert(!ap::is::int_t<short>);
    static_assert(!ap::is::int_t<char>);
    static_assert(!ap::is::int_t<int>);

    std::cout << "Success!!\n";
}