#ifndef AMPERSAND_META_TRAIT_COMMON_HPP
#define AMPERSAND_META_TRAIT_COMMON_HPP

#include "../declare.hpp"
#include "type.hpp"

namespace ap::details {
	template <typename... T>								struct common_t;
	template <std::integral T	   , std::integral		 U> struct common_t<ap::type<T>, ap::type<U>> { using type = ap::type<std::common_type_t<T, U>>; };
	template <std::floating_point T, std::integral		 U> struct common_t<ap::type<T>, ap::type<U>> { using type = ap::type<T>; };
	template <std::integral		  T, std::floating_point U> struct common_t<ap::type<T>, ap::type<U>> { using type = ap::type<U>; };
	template <std::floating_point T, std::floating_point U> struct common_t<ap::type<T>, ap::type<U>> { using type = ap::type<std::common_type_t<T, U>>; };

	template <ap::int_t   T, ap::int_t U>   struct common_t<ap::obj<T>, ap::obj<U>>	{ using type = common_t<T, U>::type; };
	template <ap::float_t T, ap::int_t U>   struct common_t<ap::obj<T>, ap::obj<U>>	{ using type = common_t<T, U>::type; };
	template <ap::int_t   T, ap::float_t U> struct common_t<ap::obj<T>, ap::obj<U>>	{ using type = common_t<T, U>::type; };
	template <ap::float_t T, ap::float_t U> struct common_t<ap::obj<T>, ap::obj<U>>	{ using type = common_t<T, U>::type; };
}

namespace ap {
	template <typename T , typename U> using common_t = details::common_t<T, U>::type;
}

#endif