#ifndef AMPERSAND_DESC_C99_DESC_HPP
#define AMPERSAND_DESC_C99_DESC_HPP

#include <string>
#include <optional>

#include <ampersand/meta.hpp>

extern "C"
{
#include "desc.h"
#include "strt.h"
}

namespace ap::c99    {
	class desc       {
		 ::obj* m_obj;
	public:
		 desc()			  ;
		 desc(const desc&);
		 desc(desc&&)     ;
		~desc()			  ;
	public:
		static std::string to_string(desc)			   ;
		static bool		   to_file  (desc, const char*);
	public:
		template <elem_t... T> bool operator()(type<T...> par) { return c99_desc_strt(m_obj, par.m_obj); }
	};
}

#endif