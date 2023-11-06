#ifndef AMPERSAND_META_TRAIT_OBJ_HPP
#define AMPERSAND_META_TRAIT_OBJ_HPP

#include "../declare.hpp"

namespace ap::details {
	template <typename T>	 struct obj_t			 : std::false_type {};
	template <typename... T> struct obj_t<obj<T...>> : std::true_type  {};

	template <typename T>	   struct int_obj_t				: std::false_type {};
	template <std::integral T> struct int_obj_t<ap::obj<T>> : std::true_type  {};

	template <typename T>			 struct float_obj_t				: std::false_type {};
	template <std::floating_point T> struct float_obj_t<ap::obj<T>> : std::true_type  {};
}

namespace ap {
	template <typename T> concept obj_t		  = details::obj_t		<T>::value;
	template <typename T> concept int_obj_t   = details::int_obj_t  <T>::value;
	template <typename T> concept float_obj_t = details::float_obj_t<T>::value;
}

#endif