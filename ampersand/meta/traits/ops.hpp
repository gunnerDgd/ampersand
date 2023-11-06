#ifndef AMPERSAND_META_TRAIT_OPS_HPP
#define AMPERSAND_META_TRAIT_OPS_HPP

#include "../declare.hpp"
#include "obj.hpp"
#include "val.hpp"

namespace ap::details {
	template <typename... T>	   struct ops_t						  : std::false_type {};
	template <op O, typename... T> struct ops_t<ops<O, T...>>		  : std::true_type  {};

	template <typename... T>	   struct arith_ops_t				  : std::false_type									    {};
	template <op O, typename... T> struct arith_ops_t<ops<O, T...>>   : std::bool_constant<O >= op::add && O <= op::mod_eq> {};

	template <typename... T>	   struct cmp_ops_t					  : std::false_type									{};
	template <op O, typename... T> struct cmp_ops_t<ops<O, T...>>	  : std::bool_constant<O >= op::gt && O <= op::neq> {};

	template <typename... T>	   struct logical_ops_t				  : std::false_type									         {};
	template <op O, typename... T> struct logical_ops_t<ops<O, T...>> : std::bool_constant<O >= op::log_and && O <= op::log_not> {};

	template <typename... T>	   struct bit_ops_t					  : std::false_type									         {};
	template <op O, typename... T> struct bit_ops_t<ops<O, T...>>	  : std::bool_constant<O >= op::bit_and && O <= op::bit_not> {};
}

namespace ap {
	template <typename T> concept ops_t     =		  details::ops_t<T>::value;
	template <typename T> concept ops_arg_t = ops_t<T> || obj_t<T> || val_t<T>;
}

#endif