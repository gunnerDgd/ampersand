#ifndef AMPERSAND_META_DECLARE_HPP
#define AMPERSAND_META_DECLARE_HPP

#include <concepts>
#include <type_traits>

namespace ap {
	template <typename... T> class    type;
	template <typename T>    struct __type_t			 : std::false_type {};
	template <typename... T> struct __type_t<type<T...>> : std::true_type  {};
	template <typename T> concept	  type_t			 = __type_t<T>::value;

	enum class acc  { pub, priv, prot };
	enum class stor { dyn, stat }	   ;

	template <acc A, stor S, typename... T> class    elem;
	template				<typename... T> struct __elem_t							: std::false_type {};
	template <acc A, stor S, typename... T> struct __elem_t<elem<A, S, type<T...>>> : std::true_type  {};
	template <typename T>					concept  elem_t = __elem_t<T>::value;

	template <typename... T> class    obj;
	template <typename T>    struct __obj_t			  : std::false_type {};
	template <typename... T> struct __obj_t<obj<T...>> : std::true_type  {};
	template <typename T>    concept  obj_t = __obj_t<T>::value;

	enum class op			  {
		none =  0			  ,
		err	 = -1			  ,
		add  =  1, add_eq = 2 ,
		sub	 =  3, sub_eq = 4 ,
		mul  =  5, mul_eq = 6 ,
		div	 =  7, div_eq = 8 ,
		mod	 =  9, mod_eq = 10,

		gt   = 11, gt_eq  = 12,
	    lt	 = 13, lt_eq  = 14,
		eq   = 15, neq	  = 16,

		logical_and = 17, logical_or = 18, logical_not = 19,
		bit_and     = 20, bit_and_eq = 21,
		bit_or      = 22, bit_or_eq  = 23,
	    bit_xor     = 24, bit_xor_eq = 25,
	    bit_not     = 26,

		obj_new		= 27,
	    obj_clone	= 28,
		obj_del		= 29,
		call		= 30,
		ret		    = 31,

		cond_if		= 32,
		cond_elif	= 33,
		cond_else	= 34,

		loop_while	= 35,
		loop_for    = 36
	};

	template <op O, typename... T> class    ops;
	template <typename... T>	   struct __ops_t				: std::false_type {};
	template <op O, typename... T> struct __ops_t<ops<O, T...>> : std::true_type  {};
	template <typename T>		   concept  ops_t = __ops_t<T>::value;

	template <typename T>			 struct __arith_arg_t			    : std::false_type {};
	template <std::integral T>		 struct __arith_arg_t<obj<type<T>>> : std::true_type  {};
	template <std::floating_point T> struct __arith_arg_t<obj<type<T>>> : std::true_type  {};
	template <typename T>			 concept  arith_arg_t = __arith_arg_t<T>::value;
}

#endif