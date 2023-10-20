#include "desc.hpp"

extern "C"
{
#include "details/desc.h"
}

#ifdef PRESET_WIN32
#include <Windows.h>
#endif

namespace ap::c99 {
	desc:: desc()				 : m_obj(obj_init(0, c99_desc_t, 0)) {}
	desc:: desc(const desc& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc:: desc(desc&& par)		 : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc::~desc()								 { obj_deinit(m_obj); }

	std::string
		desc::to_string(desc par) {
			__c99_desc* ret = (__c99_desc*)par.m_obj;
			return std::string(str_raw_ptr(&ret->ctx), str_len(&ret->ctx));
	}

	bool		   
		desc::to_file(desc par, const char* par_path)	{
#ifdef PRESET_WIN32
			__c99_desc* ret_desc = (__c99_desc*)par.m_obj;
			HANDLE	    ret		 = CreateFile (
					(LPCSTR)par_path,
					GENERIC_ALL	 	,
					0				,
					0				,
					CREATE_NEW		,
					0				,
					0
			);

			if (ret == INVALID_HANDLE_VALUE)
				return false;

			DWORD res   = 0;
			if(!WriteFile(ret, str_raw_ptr(&ret_desc->ctx), str_len(&ret_desc->ctx), &res, 0))	
				return false;

			return res == str_len(&ret_desc->ctx);
#endif
	}
}