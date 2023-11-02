#ifndef AMPERSAND_META_OPS_BIT_OPS_HPP
#define AMPERSAND_META_OPS_BIT_OPS_HPP

#include "../declare.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U> auto operator& (T par, U par_ops) { return ops<op::bit_and	 , T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> auto operator&=(T par, U par_ops) { return ops<op::bit_and_eq, T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> auto operator| (T par, U par_ops) { return ops<op::bit_or	 , T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> auto operator|=(T par, U par_ops) { return ops<op::bit_or_eq , T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> auto operator^ (T par, U par_ops) { return ops<op::bit_xor   , T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> auto operator^=(T par, U par_ops) { return ops<op::bit_xor_eq, T, U>(par, par_ops); }
	template <ops_arg_t T>				auto operator~ (T par)			  { return ops<op::bit_not   , T>   (par)		  ; }
}

#endif