#ifndef AMPERSAND_META_OPS_OBJ_HPP
#define AMPERSAND_META_OPS_OBJ_HPP

#include "../declare.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <obj_t T, ops_arg_t... Args>
	class ops<op::push, T, Args...> {
		::obj* m_obj;
	public:
		 ops(T par, Args... par_arg)		       : m_obj(obj_init(0, ap_ops_t, sizeof(par_arg)... + 2, op::push, par.m_obj, (par_arg.m_obj)...)) {}
		 ops(const ops<op::push, T, Args...>& par) : m_obj(obj_init_as_ref(par.m_obj))															   {}
		 ops(ops<op::push, T, Args...>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))															   {}
		~ops()																												   { obj_deinit(m_obj); }
	};

	template <obj_t T>
	class ops<op::pop, T> {
		::obj* m_obj;
	public:
		 ops(T par)						 : m_obj(obj_init(0, ap_ops_t, 2, op::pop, par.m_obj)) {}
		 ops(const ops<op::pop, T>& par) : m_obj(obj_init_as_ref(par.m_obj))				   {}
		 ops(ops<op::pop, T>&& par)		 : m_obj(obj_init_as_ref(par.m_obj))				   {}
		~ops()															   { obj_deinit(m_obj); }
	};
}

#endif