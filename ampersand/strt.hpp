#ifndef AMPERSAND_STRT_HPP
#define AMPERSAND_STRT_HPP

#include "meta.hpp"

namespace ap					{
	auto strt(const char* name) {
		return [name](elem_t auto... par) {
			return type { name, par... };
		};
	}
}

#endif