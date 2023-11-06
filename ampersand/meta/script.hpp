#ifndef AMPERSAND_META_SCRIPT_HPP
#define AMPERSAND_META_SCRIPT_HPP

#include "traits.hpp"

extern "C"
{
#include "script.h"
}

namespace ap	 {
	class script {
		::obj* m_obj;
	public:
		 script(script_arg_t auto... par) : m_obj(obj_init(0, ap_script_t, sizeof...(par), (par.m_obj)...)) {}
		 script(const script&);
		 script(script&&)	  ;
		~script()			  ;
	};
}

#endif