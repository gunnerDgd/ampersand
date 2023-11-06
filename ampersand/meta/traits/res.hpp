#ifndef AMPERSAND_META_TRAIT_RES_HPP
#define AMPERSAND_META_TRAIT_RES_HPP

#include "../declare.hpp"
#include "common.hpp"

namespace ap::details {
	template <typename T>										struct res_t;
	template <typename... T>									struct res_t <ap::type<T...>>										  { using type = ap::type<T...>; };
	template <typename... T>									struct res_t <ap::obj <ap::type<T...>>>								  { using type = ap::type<T...>; };
	template <typename... T>									struct res_t <ap::val <ap::type<T...>>>								  { using type = ap::type<T...>; };
	template <acc A, stor S, typename... T>						struct res_t <ap::elem<A, S, ap::type<T...>>>						  { using type = ap::type<T...>; };
	template <typename R, typename... Args, typename... OpArgs> struct res_t <ap::ops<ap::op::call, ap::func<R(Args...), OpArgs...>>> { using type =			  R; };
	template <ap::obj_t T, typename... Args>					struct res_t <ap::ops<ap::op::push, T, Args...>>					  { using type = res_t<T>::type; };

	template <op O, typename T, typename U> requires (O >= op::add	   && O <= op::mod_eq)  struct res_t<ap::ops<O, T, U>> { using type = ap::common_t<T, U>; };
	template <op O, typename T, typename U> requires (O >= op::gt	   && O <= op::neq)     struct res_t<ap::ops<O, T, U>> { using type = ap::type<bool>    ; };
	template <op O, typename T, typename U> requires (O >= op::log_and && O <= op::log_not) struct res_t<ap::ops<O, T, U>> { using type = ap::type<bool>    ; };
	template <op O, typename T, typename U> requires (O >= op::bit_and && O <= op::bit_not) struct res_t<ap::ops<O, T, U>> { using type = ap::common_t<T, U>; };

	template <ap::ops_arg_t T> struct res_t<ap::ops<op::bit_not, T>> { using type = res_t<T>::type; };
	template <ap::ops_arg_t T> struct res_t<ap::ops<op::log_not, T>> { using type = res_t<T>::type; };
}

namespace ap {
	template <typename T> using res_t = details::res_t <T>::type;
}

#endif