#include "script.hpp"

namespace ap {
	script:: script(const script& par) : m_obj(obj_init_as_ref(par.m_obj))				    {}
	script:: script(script&& par)	   : m_obj(obj_init_as_ref(par.m_obj))				    {}
	script::~script()													{ obj_deinit(m_obj); }

}