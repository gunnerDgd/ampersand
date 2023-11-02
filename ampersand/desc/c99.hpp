#ifndef AMPERSAND_DESC_C99_HPP
#define AMPERSAND_DESC_C99_HPP

#include <iostream>
#include <fstream>

#include <ampersand/meta.hpp>

extern "C"
{
#include "c99.h"
}

namespace ap::c99   {
	class desc	    {
		::obj* m_obj;
	public:
		class context        {
			friend class desc;
			::obj* m_obj     ;
			 context(desc&)  ;
		public:
			 context(const context&);
			 context(context&&)		;
			~context()				;
		public:
			friend std::ostream&  operator<< (std::ostream& , desc::context&);
			friend std::ostream&  operator<< (std::ostream& , desc::context) ;
			friend std::ofstream& operator<< (std::ofstream&, desc::context&);
			friend std::ofstream& operator<< (std::ofstream&, desc::context) ;
		};
	public:
		 desc()			  ;
		 desc(const desc&);
		 desc(desc&&)	  ;
		~desc()			  ;
	public:
		context get_context();
		bool    operator() (type_t   auto par) { return ap_desc_strt  (m_obj, par.m_obj); }
		bool    operator() (script_t auto par) { return ap_desc_script(m_obj, par.m_obj); }
		bool    operator() (ops_t    auto par) { return ap_desc_ops   (m_obj, par.m_obj); }
		bool    operator() (func_t   auto par) { return ap_desc_func  (m_obj, par.m_obj); }
	};
}

#endif