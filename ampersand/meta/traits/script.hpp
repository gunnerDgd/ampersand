#ifndef AMPERSAND_META_TRAIT_SCRIPT_HPP
#define AMPERSAND_META_TRAIT_SCRIPT_HPP

#include "../declare.hpp"
#include "ops.hpp"

namespace ap::details {
	template <typename T> struct script_t		  : std::false_type {};
	template <>			  struct script_t<script> : std::true_type  {};
}

namespace ap {
	template <typename T> concept script_t     = details::script_t<T>::value;
	template <typename T> concept script_arg_t = script_t<T> || ops_t<T>    ;
}

#endif