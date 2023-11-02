#include <ampersand/elem.hpp>
#include <ampersand/strt.hpp>
#include <ampersand/var.hpp>

#include <ampersand/meta.hpp>
#include <ampersand/desc.hpp>

#include <iostream>

auto test_type = ap::strt("test_type")(
				 ap::pub (ap::i8 ()) ("m_test0"),
				 ap::prot(ap::i16()) ("m_test1"),
				 ap::priv(ap::i32()) ("m_test2"),
				 ap::priv(ap::i64()) ("m_test3")
);



int main() {
	auto c99 = ap::c99::desc();
	c99(test_type);

	std::cout << c99.get_context() << std::endl;
}