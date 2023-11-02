#ifndef AMPERSAND_META_OBJ_HPP
#define AMPERSAND_META_OBJ_HPP

extern "C"
{
#include "obj.h"
}

#include "declare.hpp"

namespace ap			     {
	template <typename... T>
	class obj<type<T...>>	 {
		template <typename... T>	   friend class type;
		template <op O, typename... T> friend class ops ;
		::obj* m_obj;
	public:
		 obj(const char*, type<T...>)   ;
		 obj(const obj<type<T...>>&)    ;
		 obj(obj<type<T...>>&&) noexcept;
		~obj()						    ;
	};

	template <typename... T> obj<type<T...>>:: obj(const char* par_name, type<T...> par) : m_obj(obj_init(0, ap_obj_t, 2, par.m_obj, par_name)) {}
	template <typename... T> obj<type<T...>>:: obj(const obj<type<T...>>& par)			 : m_obj(obj_init_as_ref(par.m_obj)) {}
	template <typename... T> obj<type<T...>>:: obj(obj<type<T...>>&& par) noexcept	     : m_obj(obj_init_as_ref(par.m_obj)) {}
	template <typename... T> obj<type<T...>>::~obj()												     { obj_deinit(m_obj); }
}

#endif