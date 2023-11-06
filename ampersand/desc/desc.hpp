#ifndef AMPERSAND_DESC_DESC_HPP
#define AMPERSAND_DESC_DESC_HPP

extern "C"
{
#include <ampersand/base/obj.h>

#include "func.h"
#include "strt.h"
#include "ops.h"
#include "script.h"
}

#include <ampersand/meta.hpp>
#include <optional>

#include "desc_friend.hpp"

namespace ap   {
	class desc {
		::obj* m_obj;
		desc(::obj*);
	public:
		AMPERSAND_DESC_FRIEND
		 desc(const desc&);
		 desc(desc&&)	  ;
		~desc()			  ;
	public:
		bool operator()(type_t   auto par) { return ::ap_desc_strt  (m_obj, par.m_obj); }
		bool operator()(ops_t    auto par) { return ::ap_desc_ops   (m_obj, par.m_obj); }
		bool operator()(script_t auto par) { return ::ap_desc_script(m_obj, par.m_obj); }
		bool operator()(func_t   auto par) { return ::ap_desc_func  (m_obj, par.m_obj); }
	};
}

#endif