#ifndef AMPERSAND_META_OPS_CMP_OPS_HPP
#define AMPERSAND_META_OPS_CMP_OPS_HPP

#include "../traits.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator==(T par, U par_ops) { return ops<op::eq   , T, U>(par, par_ops); }

	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator!=(T par, U par_ops) { return ops<op::neq  , T, U>(par, par_ops); }

	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator< (T par, U par_ops) { return ops<op::lt   , T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator<=(T par, U par_ops) { return ops<op::lt_eq, T, U>(par, par_ops); }

	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator> (T par, U par_ops) { return ops<op::gt	, T, U>(par, par_ops); }
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator>=(T par, U par_ops) { return ops<op::gt_eq, T, U>(par, par_ops); }
}

#endif