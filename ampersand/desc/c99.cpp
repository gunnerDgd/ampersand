#include "c99.hpp"

extern "C"
{
#include "details/desc.h"
#include "c99/details/ctx.h"
}

namespace ap::c99 {
	desc:: desc()			     : m_obj(obj_init(0, ap_desc_t, 2, c99_ctx_t, c99_desc)) {}
	desc:: desc(const desc& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc:: desc(desc&& par)		 : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc::~desc()								 { obj_deinit(m_obj); }

	desc::context
		desc::get_context() {
			return context(*this);
	}

	desc::context:: context(desc& par)			: m_obj(obj_init_as_ref(((::__ap_desc*)par.m_obj)->ctx)) {}
	desc::context:: context(const context& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	desc::context:: context(context&& par)		: m_obj(obj_init_as_ref(par.m_obj)) {}
	desc::context::~context()								    { obj_deinit(m_obj); }

	std::ostream&
		operator<< (std::ostream& par_os, desc::context& par) {
			::__c99_ctx* ctx = (::__c99_ctx*)par.m_obj;
			par_os.write(str_raw_ptr(&ctx->ctx), str_len(&ctx->ctx));

			return par_os;
	}
	
	std::ofstream&
		operator<< (std::ofstream& par_os, desc::context& par) {
			::__c99_ctx* ctx = (::__c99_ctx*)par.m_obj;
			par_os.write(str_raw_ptr(&ctx->ctx), str_len(&ctx->ctx));

			return par_os;
	}

	std::ostream&
		operator<< (std::ostream& par_os, desc::context par) {
			::__c99_ctx* ctx = (::__c99_ctx*)par.m_obj;
			par_os.write(str_raw_ptr(&ctx->ctx), str_len(&ctx->ctx));

			return par_os;
	}
	
	std::ofstream&
		operator<< (std::ofstream& par_os, desc::context par) {
			::__c99_ctx* ctx = (::__c99_ctx*)par.m_obj;
			par_os.write(str_raw_ptr(&ctx->ctx), str_len(&ctx->ctx));

			return par_os;
	}
}