#ifndef AMPERSAND_META_OPS_LOGICAL_HPP
#define AMPERSAND_META_OPS_LOGICAL_HPP

#include "../declare.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U>
	class ops<op::log_and, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)					: m_obj(obj_init(0, ap_ops_t, 3, op::log_and, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::log_and, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::log_and, T, U>&& par)	    : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::log_or, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::log_or, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::log_or, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::log_or, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T>
	class ops<op::log_not, T> {
		::obj* m_obj;
	public:
		 ops(T par)							 : m_obj(obj_init(0, ap_ops_t, 3, op::log_not, par.m_obj())) {}
		 ops(const ops<op::log_not, T>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::log_not, T>&& par)	     : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};
}

#endif