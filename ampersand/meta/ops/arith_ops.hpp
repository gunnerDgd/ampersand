#ifndef AMPERSAND_META_OPS_ARITH_OPS_HPP
#define AMPERSAND_META_OPS_ARITH_OPS_HPP

#include "../traits.hpp"

extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>) 
	auto operator+(T par, U par_add)  { return ops<op::add, T, U>(par, par_add); }
	
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator-(T par, U par_add)  { return ops<op::sub, T, U>(par, par_add); }

	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator*(T par, U par_add)  { return ops<op::mul, T, U>(par, par_add); }

	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator/(T par, U par_add)  { return ops<op::div, T, U>(par, par_add); }
	
	template <ops_arg_t T, ops_arg_t U> 
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator%(T par, U par_add)  { return ops<op::mod, T, U>(par, par_add); }

	
	template <obj_t T, ops_arg_t U>		
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator+=(T par, U par_add) { return ops<op::add_eq, T, U>(par, par_add); }

	template <obj_t T, ops_arg_t U>		
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator-=(T par, U par_add) { return ops<op::sub_eq, T, U>(par, par_add); }
	
	template <obj_t T, ops_arg_t U>		
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator*=(T par, U par_add) { return ops<op::mul_eq, T, U>(par, par_add); }
	
	template <obj_t T, ops_arg_t U>		
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator/=(T par, U par_add) { return ops<op::div_eq, T, U>(par, par_add); }

	template <obj_t T, ops_arg_t U>		
		requires (int_t<res_t<T>> || float_t<res_t<T>>) && (int_t<res_t<U>> || float_t<res_t<U>>)
	auto operator%=(T par, U par_add) { return ops<op::mod_eq, T, U>(par, par_add); }
}

#endif