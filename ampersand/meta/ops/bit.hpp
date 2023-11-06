#ifndef AMPERSAND_META_OPS_BIT_HPP
#define AMPERSAND_META_OPS_BIT_HPP

#include "../traits.hpp"

extern "C"
{
#include "../ops.h"
}

namespace ap {
	template <ops_arg_t T, ops_arg_t U> 
		requires int_t<res_t<T>> && int_t<res_t<U>>
	class ops<op::bit_and, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				    : m_obj(obj_init(0, ap_ops_t, 3, op::bit_and, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_and, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))											 {}
		 ops(ops<op::bit_and, T, U>&& par)		: m_obj(obj_init_as_ref(par.m_obj))											 {}
		~ops()																							 { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U>
		requires int_t<res_t<T>>&& int_t<res_t<U>>
	class ops<op::bit_or, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				   : m_obj(obj_init(0, ap_ops_t, 3, op::bit_or, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_or, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))										   {}
		 ops(ops<op::bit_or, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))										   {}
		~ops()																						   { obj_deinit(m_obj); }
	};

	template <ops_arg_t T, ops_arg_t U> 
		requires int_t<res_t<T>>&& int_t<res_t<U>>
	class ops<op::bit_xor, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)				    : m_obj(obj_init(0, ap_ops_t, 3, op::bit_xor, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_xor, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))											 {}
		 ops(ops<op::bit_xor, T, U>&& par)	    : m_obj(obj_init_as_ref(par.m_obj))											 {}
		~ops()																							 { obj_deinit(m_obj); }
	};

	template <ops_arg_t T> 
		requires int_t<res_t<T>> 
	class ops<op::bit_not, T> {
		::obj* m_obj;
	public:
		 ops(T par)						     : m_obj(obj_init(0, ap_ops_t, 3, op::bit_not, par.m_obj())) {}
		 ops(const ops<op::bit_not, T>& par) : m_obj(obj_init_as_ref(par.m_obj))						 {}
		 ops(ops<op::bit_not, T>&& par)		 : m_obj(obj_init_as_ref(par.m_obj))						 {}
		~ops()																	     { obj_deinit(m_obj); }
	};

	template <int_obj_t T, ops_arg_t U> 
		requires int_t<res_t<T>> && int_t<res_t<U>>
	class ops<op::bit_and_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)					   : m_obj(obj_init(0, ap_ops_t, 3, op::bit_and_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_and_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::bit_and_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <int_obj_t T, ops_arg_t U> 
		requires int_t<res_t<T>> && int_t<res_t<U>>
	class ops<op::bit_or_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)					   : m_obj(obj_init(0, ap_ops_t, 3, op::bit_or_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_or_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::bit_or_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};

	template <int_obj_t T, ops_arg_t U> 
		requires int_t<res_t<T>> && int_t<res_t<U>>
	class ops<op::bit_xor_eq, T, U> {
		::obj* m_obj;
	public:
		 ops(T par, U par_add)					   : m_obj(obj_init(0, ap_ops_t, 3, op::bit_xor_eq, par.m_obj(), par_add.m_obj())) {}
		 ops(const ops<op::bit_xor_eq, T, U>& par) : m_obj(obj_init_as_ref(par.m_obj))									  {}
		 ops(ops<op::bit_xor_eq, T, U>&& par)	   : m_obj(obj_init_as_ref(par.m_obj))									  {}
		~ops()																					  { obj_deinit(m_obj); }
	};
}

#endif