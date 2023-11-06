#ifndef AMPERSAND_META_ELEM_HPP
#define AMPERSAND_META_ELEM_HPP

#include "declare.hpp"
#include "../desc/declare.hpp"

extern "C"
{
#include "elem.h"
}

#define AMPERSAND_ELEM_FRIEND				   \
	template <typename... T> friend class type;\
							 friend class desc;

namespace ap {
	template <acc A, stor S, typename... T>
	class elem<A, S, type<T...>> {
		AMPERSAND_ELEM_FRIEND
		::obj* m_obj;
	public:
		elem(const char*, type<T...>);
	};

	template <acc A, stor S, typename... T>
	elem<A, S, type<T...>>::elem
		(const char* par_name, type<T...> par)
			: m_obj(obj_init(0, ap_elem_t, 4, par_name, par.m_obj, A, S)) {}
}

#endif