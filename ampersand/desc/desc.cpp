#include "desc.hpp"

namespace ap {
	desc:: desc(::obj* par)		 : m_obj(obj_init_as_ref(par))		 {}
	desc:: desc(const desc& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc:: desc(desc&& par)		 : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc::~desc()								 { obj_deinit(m_obj); }
}