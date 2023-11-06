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

	template <op O, typename... T> class ops   ;
	class script;
}


#endif