#ifndef AMPERSAND_META_VAL_HPP
#define AMPERSAND_META_VAL_HPP

extern "C"
{
#include "val.h"
#include "type.h"
}

#include "traits.hpp"

#define AMPERSAND_VAL_FRIEND\
	template <op O, typename... T> friend class ops;

namespace ap {
	template <std::integral T>
	class val<type<T>> {
		AMPERSAND_VAL_FRIEND
		::obj* m_obj;
	public:
		 val(T par)		  {
			 type<T> par_t;
			 m_obj = obj_init(0, ap_val_t, 2, par_t.m_obj, par);
		 }
		 val(const val& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
		 val(val&& par)      : m_obj(obj_init_as_ref(par.m_obj)) {}
		~val()								  { obj_deinit(m_obj) }
	};

	template <std::floating_point T>
	class val<type<T>> {
		AMPERSAND_VAL_FRIEND
		::obj* m_obj;
	public:
		 val(T par)		  {
			 type<T> par_t;
			 m_obj = obj_init(0, ap_val_t, 2, par_t.m_obj, par);
		 }
		 val(const val& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
		 val(val&& par)      : m_obj(obj_init_as_ref(par.m_obj)) {}
		~val()								  { obj_deinit(m_obj) }
	};
}

#endif