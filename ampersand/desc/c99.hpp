#ifndef AMPERSAND_DESC_C99_HPP
#define AMPERSAND_DESC_C99_HPP

extern "C"
{
#include <ampersand/base/obj.h>

#include "desc.h"
#include "func.h"
#include "strt.h"
#include "ops.h"
#include "script.h"
}

#include <iostream>
#include <fstream>

#include "desc.hpp"

namespace ap  {
	desc from_c99();

	class c99		{
		::obj* m_obj;
		c99(::obj*) ;
	public:
		 static std::optional<c99> from(desc&);
		 friend std::ostream& operator << (std::ostream&, c99&);
		 c99(const c99&);
		 c99(c99&&)		;
		~c99()			;
	};

	std::ostream& operator << (std::ostream&, c99&);
}

#endif