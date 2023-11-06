#include "type.hpp"

namespace ap {
	type<void>:: type()						 : m_obj(obj_init(0, ap_type_t, 1, ap_type_none)) {}
	type<void>:: type(const type<void>& par) : m_obj(obj_init_as_ref(par.m_obj))			  {}
	type<void>:: type(type<void>&& par)		 : m_obj(obj_init_as_ref(par.m_obj))			  {}
	type<void>::~type()													  { obj_deinit(m_obj); }

	type<>:: type(const char* par)	 : m_obj(obj_init(0, ap_type_t, 2, ap_type_ext, par)) {}
	type<>:: type(const type<>& par) : m_obj(obj_init_as_ref(par.m_obj))				  {}
	type<>:: type(type<>&& par)		 : m_obj(obj_init_as_ref(par.m_obj))				  {}
	type<>::~type()												 	  { obj_deinit(m_obj); }

	
}