#ifndef AMPERSAND_META_DECLARE_HPP
#define AMPERSAND_META_DECLARE_HPP

#include <concepts>
#include <type_traits>

namespace ap {	
	enum class acc  : std::uint64_t { pub, priv, prot };
	enum class stor : std::uint64_t { dyn, stat }	   ;

	template <typename... T>				class type;
	template <acc A, stor S, typename... T> class elem;
	template <typename... T>				class obj ;
	template <typename T>					class val ;
	template <typename... T>				class func;
	

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

		log_and = 17, log_or     = 18, log_not = 19,
		bit_and = 20, bit_and_eq = 21,
		bit_or  = 22, bit_or_eq  = 23,
	    bit_xor = 24, bit_xor_eq = 25,
	    bit_not = 26,
		
		push = 27, pop = 28,
		bind = 29,
		call = 30,
		ret	 = 31,

		cond_if    = 32, cond_elif = 33, cond_else = 34,
		loop_while = 35, loop_for  = 36,
		ref		   = 36
	};

	template <op O, typename... T> class ops;
	class script;
}

namespace ap::details {
	template <typename T>					struct type_t			  : std::false_type {};
	template <typename... T>			    struct type_t<type<T...>> : std::true_type  {};

	template				<typename... T> struct elem_t						  : std::false_type {};
	template <acc A, stor S, typename... T> struct elem_t<elem<A, S, type<T...>>> : std::true_type  {};

	template <typename T>					struct obj_t			: std::false_type {};
	template <typename... T>				struct obj_t<obj<T...>> : std::true_type  {};

	template <typename T>					struct val_t		  : std::false_type {};
	template <std::integral T>				struct val_t<type<T>> : std::true_type  {};
	template <std::floating_point T>		struct val_t<type<T>> : std::true_type  {};

	template <typename... T>				struct ops_t			   : std::false_type {};
	template <op O, typename... T>			struct ops_t<ops<O, T...>> : std::true_type  {};

	template <typename T>					struct script_t		    : std::false_type {};
	template <>								struct script_t<script> : std::true_type  {};

	template <typename T>					struct func_t			  : std::false_type {};
	template <typename... T>				struct func_t<func<T...>> : std::true_type  {};
}

namespace ap		  {
	template <typename T> concept    type_t = details::type_t  <T>::value;
	template <typename T> concept    elem_t = details::elem_t  <T>::value;
	template <typename T> concept     obj_t = details::obj_t   <T>::value;
	template <typename T> concept	  val_t = details::val_t   <T>::value;
	template <typename T> concept  script_t = details::script_t<T>::value;
	template <typename T> concept     ops_t = details::ops_t   <T>::value;
	template <typename T> concept ops_arg_t = ops_t<T> || obj_t<T> || val_t<T>;
	template <typename T> concept    func_t = details::func_t<T>::value		  ;
}

#endif