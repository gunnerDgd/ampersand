#include "c99.hpp"

extern "C"
{
#include "c99/c99.h"
}

namespace ap	   {
	desc
		from_c99() {
			return desc(obj_init(0, ap_desc_t, 2, c99_run_t, c99_t));
	}

	std::optional<c99> 
		c99::from(desc& par) {
			::obj* ret = ap_desc_context(par.m_obj);
			if (obj_get_trait(ret) != c99_t)
				return std::nullopt;

			return c99(ret);
	}

	c99:: c99(::obj* par)	  : m_obj(obj_init_as_ref(par))       {}
	c99:: c99(const c99& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	c99:: c99(c99&& par)	  : m_obj(obj_init_as_ref(par.m_obj)) {}
	c99::~c99()								  { obj_deinit(m_obj); }

	std::ostream& 
		operator << (std::ostream& par_os, c99& par) {
			ptr ret = str_ptr(c99_get_str(par.m_obj));
			par_os.write((const char*)ptr_raw(ret), str_len(c99_get_str(par.m_obj)));
			return par_os;
	}
}