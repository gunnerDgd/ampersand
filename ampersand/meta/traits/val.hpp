#ifndef AMPERSAND_META_TRAIT_VAL_HPP
#define AMPERSAND_META_TRAIT_VAL_HPP

#include "../declare.hpp"

namespace ap::details {
	template <typename T>			 struct val_t		   : std::false_type {};
	template <std::integral T>		 struct val_t<type<T>> : std::true_type  {};
	template <std::floating_point T> struct val_t<type<T>> : std::true_type  {};
}

namespace ap {
	template <typename T> concept val_t = details::val_t<T>::value;
}

#endif