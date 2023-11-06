#ifndef AMPERSAND_META_TRAIT_FUNC_HPP
#define AMPERSAND_META_TRAIT_FUNC_HPP

#include "../declare.hpp"

namespace ap::details {
	template <typename T>	 struct func_t			   : std::false_type {};
	template <typename... T> struct func_t<func<T...>> : std::true_type  {};
}

namespace ap {
	template <typename T> concept func_t = details::func_t<T>::value;
}

#endif