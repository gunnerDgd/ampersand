#include "ops.hpp"

namespace ap::meta {
	ops:: ops(::obj* par)     : m_obj(ref(par))		  {}
	ops:: ops(const ops& par) : m_obj(ref(par.m_obj)) {}
	ops:: ops(ops&& par)	  : m_obj(ref(par.m_obj)) {}
	ops::~ops()										  { del(m_obj); }
}