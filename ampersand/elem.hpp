#ifndef AMPERSAND_ELEM_HPP
#define AMPERSAND_ELEM_HPP

#include "meta.hpp"

namespace ap	  {
namespace details {
	struct pub    { auto operator()(ap::type_t auto); };
	struct priv   { auto operator()(ap::type_t auto); };
	struct prot   { auto operator()(ap::type_t auto); };
	struct stat   {
		auto operator|(pub) ;
		auto operator|(priv);
		auto operator|(prot);
	};
}

	extern details::pub  pub ;
	extern details::priv priv;
	extern details::prot prot;
	extern details::stat stat;

	auto
		details::stat::operator|(details::pub par) {
			return [par](ap::type_t auto type)    {
				return [par, type](const char* name) {
					return elem<acc::pub, stor::stat, decltype(type)> { name, type };
				};
			};
	}

	auto 
		details::stat::operator|(details::priv par) {
			return [par](ap::type_t auto type)       {
				return [par, type](const char* name)    {
					return elem<acc::priv, stor::stat, decltype(type)> { name, type };
				};
			};
	}

	auto 
		details::stat::operator|(details::prot par) {
			return [par](ap::type_t auto type)    {
				return [par, type](const char* name) {
					return elem<acc::prot, stor::stat, decltype(type)> { name, type };
				};
			};
	}


	auto
		details::pub::operator()(ap::type_t auto par) {
			return [par](const char* name) {
				return elem<acc::pub, stor::dyn, decltype(par)> { name, par };
			};
	}

	auto
		details::priv::operator()(ap::type_t auto par) {
			return [par](const char* name) {
				return elem<acc::priv, stor::dyn, decltype(par)> { name, par };
			};
	}

	auto
		details::prot::operator()(ap::type_t auto par) {
			return [par](const char* name) {
				return elem<acc::prot, stor::dyn, decltype(par)> { name, par };
			};
	}
}

#endif