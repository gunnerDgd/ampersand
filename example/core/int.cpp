#include <core/int.hpp>
#include <core/trait/int.hpp>

#include <iostream>

int main ()                            {
    static_assert(ap::int_t<ap::i64_t>);
    static_assert(ap::int_t<ap::u64_t>);

    static_assert(ap::int_t<ap::i32_t>);
    static_assert(ap::int_t<ap::u32_t>);

    static_assert(ap::int_t<ap::i16_t>);
    static_assert(ap::int_t<ap::u16_t>);

    static_assert(ap::int_t<ap::i8_t>);
    static_assert(ap::int_t<ap::u8_t>);

    static_assert(!ap::int_t<double>);
    static_assert(!ap::int_t<float>);
    static_assert(!ap::int_t<short>);
    static_assert(!ap::int_t<char>);
    static_assert(!ap::int_t<int>);

    std::cout << "Success!!\n";
}