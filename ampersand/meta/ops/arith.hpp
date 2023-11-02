#ifndef AMPERSAND_META_OPS_ARITH_HPP
#define AMPERSAND_META_OPS_ARITH_HPP

#include "../declare.hpp"
extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U>
	class ops<op::add, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				: m_obj(obj_init(0, ap_ops_t, 3, op::add, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::add, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::add, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																				  { obj_deinit(par.m_obj); }
	};

	template <obj_t T, ops_arg_t U>
	class ops<op::add_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::add_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::add_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									     {}
		 ops(ops<op::add_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									     {}
		~ops()																				     { obj_deinit(par.m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::sub, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				: m_obj(obj_init(0, ap_ops_t, 3, op::sub, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::sub, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::sub, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																				  { obj_deinit(par.m_obj); }
	};

	template <obj_t T, ops_arg_t U>
	class ops<op::sub_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::sub_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::sub_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									     {}
		 ops(ops<op::sub_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									     {}
		~ops()																				     { obj_deinit(par.m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::mul, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				: m_obj(obj_init(0, ap_ops_t, 3, op::mul, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::mul, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::mul, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																				  { obj_deinit(par.m_obj); }
	};

	template <obj_t T, ops_arg_t U>
	class ops<op::mul_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::mul_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::mul_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									     {}
		 ops(ops<op::mul_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									     {}
		~ops()																				     { obj_deinit(par.m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::div, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				 : m_obj(obj_init(0, ap_ops_t, 3, op::div, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::div, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::div, T, U>&& par)		 : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																				  { obj_deinit(par.m_obj); }
	};

	template <obj_t T, ops_arg_t U>
	class ops<op::div_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::div_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::div_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									     {}
		 ops(ops<op::div_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))								   	     {}
		~ops()																				     { obj_deinit(par.m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
	class ops<op::mod, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				: m_obj(obj_init(0, ap_ops_t, 3, op::mod, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::mod, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::mod, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																				  { obj_deinit(par.m_obj); }
	};

	template <obj_t T, ops_arg_t U>
	class ops<op::mod_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::mod_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::mod_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									     {}
		 ops(ops<op::mod_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									     {}
		~ops()																				     { obj_deinit(par.m_obj); }
	};
}

#endif