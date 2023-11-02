#ifndef AMPERSAND_META_FUNC_HPP
#define AMPERSAND_META_FUNC_HPP

#include "declare.hpp"
#include "script.hpp"

extern "C"
{
#include "func.h"
}

namespace ap {
	template <type_t R, obj_t... Args>
	class func<R(Args...)> {
		::obj* m_obj;
	public:
		 func(script, R, Args...)	  ;
		 func(const func<R(Args...)>&);
		 func(func<R(Args...)>&&)	  ;
		~func()						  ;
	};

	template <type_t R, obj_t... Args>
	func<R(Args...)>::func(script par, R par_ret, Args... par_arg)
		: m_obj(obj_init(0, ap_func_t, par.m_obj, par_ret.m_obj, (par_arg.m_obj)...))		{}

	template <type_t R, obj_t... Args>
	func<R(Args...)>::func(const func<R(Args...)>& par) : m_obj(obj_init_as_ref(par.m_obj)) {}

	template <type_t R, obj_t... Args>
	func<R(Args...)>::func(func<R(Args...)>&& par)      : m_obj(obj_init_as_ref(par.m_obj)) {}

	template <type_t R, obj_t... Args>
	func<R(Args...)>::~func()											{ obj_deinit(m_obj); }
}

#endif