#ifndef AMPERSAND_META_OPS_CMP_HPP
#define AMPERSAND_META_OPS_CMP_HPP

#include "../declare.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U>
	class ops<op::gt, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)			   : m_obj(obj_init(0, ap_ops_t, 3, op::gt, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::gt, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::gt, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::gt_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				  : m_obj(obj_init(0, ap_ops_t, 3, op::gt_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::gt_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::gt_eq, T, U>&& par)	  : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::lt, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)			   : m_obj(obj_init(0, ap_ops_t, 3, op::lt, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::lt, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::lt, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::lt_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				  : m_obj(obj_init(0, ap_ops_t, 3, op::lt_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::lt_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::lt_eq, T, U>&& par)	  : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)			   : m_obj(obj_init(0, ap_ops_t, 3, op::eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::neq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				: m_obj(obj_init(0, ap_ops_t, 3, op::neq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::neq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::neq, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	
}

#endif