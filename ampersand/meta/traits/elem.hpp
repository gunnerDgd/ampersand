#ifndef AMPERSAND_META_TRAIT_ELEM_HPP
#define AMPERSAND_META_TRAIT_ELEM_HPP

#include "../declare.hpp"

namespace ap::details {
	template				<typename... T> struct elem_t						  : std::false_type {};
	template <acc A, stor S, typename... T> struct elem_t<elem<A, S, type<T...>>> : std::true_type  {};
}

namespace ap {
	template <typename T> concept elem_t = details::elem_t  <T>::value;
}

#endif