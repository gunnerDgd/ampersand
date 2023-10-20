#include "obj.hpp"
#include "type.hpp"

namespace ap::meta {
	obj:: obj(::obj* par)			   : m_obj(ref(par))	   {}
	obj:: obj(const obj& par)		   : m_obj(ref(par.m_obj)) {}
	obj:: obj(obj&& par)	  noexcept : m_obj(ref(par.m_obj)) {}
	obj::~obj()												   { del(m_obj); }

	std::optional<obj>
		obj::make_from(type& par, name_type par_name) {
			par.m_obj
	}
}