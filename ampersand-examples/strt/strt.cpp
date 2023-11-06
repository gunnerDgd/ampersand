#include <ampersand/elem.hpp>
#include <ampersand/strt.hpp>
#include <ampersand/var.hpp>

#include <ampersand/meta.hpp>
#include <ampersand/desc.hpp>

#include <iostream>

auto test_type = ap::strt("test_type")(
				 ap::pub (ap::i8 ())  ("m_test0"),
				 ap::prot(ap::i16())  ("m_test1"),
				 ap::priv(ap::i32())  ("m_test2"),
				 ap::priv(ap::i64())  ("m_test3")
);

int main() {
	auto desc = ap::from_c99();
		 desc(test_type);

	auto c99 = ap::c99::from(desc).value();

	std::cout << c99 << std::endl;
}