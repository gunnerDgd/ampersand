#ifndef AMPERSAND_VAR_HPP
#define AMPERSAND_VAR_HPP

#include "details/var.hpp"

namespace ap					 {
	auto var(ap::obj_t auto par) { 
		return details::var<decltype(par)>(par);
	}
}

#endif