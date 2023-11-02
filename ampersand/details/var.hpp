#ifndef AMPERSAND_DETAILS_VAR_HPP
#define AMPERSAND_DETAILS_VAR_HPP

#include <tuple>
#include "../meta/declare.hpp"

namespace ap::details {
	template <typename... T> 
	class var;
	
	template <ap::type_t T, ap::ops_arg_t... Args>
	class var<T, Args...> {
		template <typename... T> friend class var;
		std::tuple<Args...> m_type_args;
		T					m_type	   ;
	public:
		var(T par, Args... par_args) : m_type(par), m_type_args(par_args...) {}
	};

	template <ap::type_t T>
	class var<T>		  {
		template <typename... T> friend class var;
		T			m_type;
	public:
		var(T par) : m_type(par) {}
	};

	template <ap::obj_t T>
	class var<T> {
		T m_obj;
	public:
		var(T par) : m_obj(par) {}
		template <ap::type_t T, ap::ops_arg_t... Args>
		auto operator=(var<T, Args...> par) {
			auto ret = [this, par]<std::size_t... Idx>(std::index_sequence<Idx...>) {
				return ops<op::push, T, Args...>(m_obj,(std::get<Idx>(par.m_type_args), ...));
			};

			return ret(std::make_index_sequence<sizeof...(Args)>{});
		}

		template <ap::type_t T>
		auto operator=(var<T> par) {
			return ops<op::push, T>(m_obj);
		}
	};
}

#endif