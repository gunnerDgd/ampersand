#ifndef AMPERSAND_FUNC_HPP
#define AMPERSAND_FUNC_HPP

#include <ampersand/meta.hpp>

namespace ap												   {
	auto fn(const char* name)								   {
		return [name]		       (type_t		 auto ret)	   {
		return [name, ret]		   (obj_t		 auto... args) {
		return [name, ret, args...](script_arg_t auto... ops)  {
			return func<decltype(ret)(decltype(args)...)>(script(ops...), ret, args...);
		};
		};
		};
	}

	auto ret(obj_t auto ret_val) {
		return ops<op::ret, decltype(ret_val)>(ret_val);
	}
}

#endif