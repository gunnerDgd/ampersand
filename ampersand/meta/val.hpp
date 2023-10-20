#ifndef AMPERSAND_META_VAL_HPP
#define AMPERSAND_META_VAL_HPP

extern "C"
{
#include "val.h"
}

#include "type.hpp"

namespace ap::meta {
	class val	   {
		::obj* m_obj;
	public:
		static std::optional<val> make_from(type&, auto);

		 val(const val&);
		 val(val&&)     ;
		~val()			;
	};

	std::optional<val> 
		val::make_from(type& par_type, auto par) {
			::obj* ret = make (ap_val_t) from (2, par_type.m_obj, par);
			if   (!ret) return std::nullopt;

			return val { ret };
	}
}

#endif