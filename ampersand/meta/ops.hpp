#ifndef AMPERSAND_META_OPS_HPP
#define AMPERSAND_META_OPS_HPP

#include "type.hpp"

extern "C"
{
#include "ops.h"
}

namespace ap::meta				{
	enum class op_idx : ::u64_t {
		none =  0,
		err	 = -1,

		add = 1 , add_eq = 2 ,
		sub = 3 , sub_eq = 4 ,
		mul = 5 , mul_eq = 6 ,
		div = 7 , div_eq = 8 ,
		mod = 9 , mod_eq = 10,

		gt  = 11, gt_eq  = 12,
		lt  = 13, lt_eq  = 14,
		eq  = 15, neq    = 16,

		logical_and = 17, logical_or    = 18, logical_not = 20,
		bit_and		= 21, bit_and_eq	= 22,
		bit_or      = 23, bit_or_eq		= 24,
		bit_xor     = 25, bit_xor_eq	= 26,
		bit_not		= 27,
		init		= 28, init_as_clone = 29, deinit	  = 30,

		call		= 31, ret			= 32,
		cond_if     = 33, cond_elif     = 34, cond_else   = 35,
		loop_while  = 36, loop_for      = 37
	};

	class ops	    {
		::obj* m_obj;
		ops(::obj*) ;
	public:
		static std::optional<ops> make_from(op_idx, auto...);

		 ops(const ops&)	;
		 ops(ops&&) noexcept;
		~ops()				;
	};

	std::optional<ops> 
		ops::make_from(op_idx par_idx, auto... par) {
			::obj* ret = make (ap_ops_t) from (sizeof...(par) + 1, par_idx, (par.m_obj)...);
			if   (!ret) return std::nullopt;

			return ops(ret);
	}
}

#endif