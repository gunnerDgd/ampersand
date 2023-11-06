#ifndef AMPERSAND_META_OPS_LOGICAL_OPS_HPP
#define AMPERSAND_META_OPS_LOGICAL_OPS_HPP

#include "../traits.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U> 
		requires boolean_t<res_t<T>> && boolean_t<res_t<U>>
	auto operator&&(T par, U par_ops) { return ops<op::log_and, T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> 
		requires boolean_t<res_t<T>> && boolean_t<res_t<U>>
	auto operator||(T par, U par_ops) { return ops<op::log_or , T, U>(par, par_ops); }
	template <ops_arg_t T>				
		requires boolean_t<res_t<T>>
	auto operator! (T par)			  { return ops<op::log_not, T>	 (par)		   ; }
}

#endif