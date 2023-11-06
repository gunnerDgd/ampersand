#ifndef AMPERSAND_META_TRAIT_TYPE_HPP
#define AMPERSAND_META_TRAIT_TYPE_HPP

#include "../declare.hpp"
#include "elem.hpp"

namespace ap::details {
	template <typename T>			 struct type_t			       : std::false_type {};
	template <typename... T>		 struct type_t<type<T...>>     : std::true_type  {};

	template <typename T>			 struct int_t				   : std::false_type {};
	template <std::integral T>		 struct int_t<ap::type<T>>     : std::true_type  {};

	template <typename T>			 struct float_t				   : std::false_type {};
	template <std::floating_point T> struct float_t<ap::type<T>>   : std::true_type  {};

	template <typename T>			 struct boolean_t			      : std::false_type {};
	template <>						 struct boolean_t<ap::type<bool>> : std::true_type  {};

	template <typename T>			 struct strt_t				   : std::false_type {};
	template <ap::elem_t... T>		 struct strt_t<ap::type<T...>> : std::true_type  {};
}

namespace ap {
	template <typename T> concept type_t    = details::type_t   <T>::value;
	template <typename T> concept int_t     = details::int_t	<T>::value;
	template <typename T> concept float_t   = details::float_t  <T>::value;
	template <typename T> concept boolean_t = details::boolean_t<T>::value;
	template <typename T> concept strt_t    = details::strt_t   <T>::value;
}

#endif