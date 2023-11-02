#ifndef AMPERSAND_META_TYPE_HPP
#define AMPERSAND_META_TYPE_HPP

#include <optional>
#include <concepts>

#include "declare.hpp"
#include "../desc/declare.hpp"
#include "../details/var.hpp"

extern "C"
{
#include "type.h"
}

#define AP_TYPE_FRIEND\
	template <acc A, stor S, typename... T> friend class elem	  ;\
	template <typename... T>				friend class obj	  ;\
	template <typename T>					friend class val	  ;\
											friend class c99::desc;

namespace ap		{
	template <std::integral T>
	class type<T>	{
		AP_TYPE_FRIEND
		::obj* m_obj;
	public:
		 type()					{
			 u64_t ret_type = -1;

			 if constexpr (std::is_same_v<T, std::int8_t>)   ret_type = ap_type_i8 ;
			 if constexpr (std::is_same_v<T, std::int16_t>)  ret_type = ap_type_i16;
			 if constexpr (std::is_same_v<T, std::int32_t>)  ret_type = ap_type_i32;
			 if constexpr (std::is_same_v<T, std::int64_t>)  ret_type = ap_type_i64;

			 if constexpr (std::is_same_v<T, std::uint8_t>)  ret_type = ap_type_u8;
			 if constexpr (std::is_same_v<T, std::uint16_t>) ret_type = ap_type_u16;
			 if constexpr (std::is_same_v<T, std::uint32_t>) ret_type = ap_type_u32;
			 if constexpr (std::is_same_v<T, std::uint64_t>) ret_type = ap_type_u64;

			 m_obj = obj_init(0, ap_type_t, 1, ret_type);
		 }

		 type(const type<T>& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
		 type(type<T>&& par)	  : m_obj(obj_init_as_ref(par.m_obj)) {}
		~type()									  { obj_deinit(m_obj); }

		auto operator()()					{ return details::var<type<T>>			    (*this)		 ; }
		auto operator()(ops_arg_t auto par) { return details::var<type<T>, decltype(par)>(*this, par); }
	};

	template <std::floating_point T>
	class type<T>	{
		AP_TYPE_FRIEND
		::obj* m_obj;
	public:
		 type()					{
			 u64_t ret_type = -1;

			 if constexpr (std::is_same_v<T, float>)  ret_type = ap_type_f32;
			 if constexpr (std::is_same_v<T, double>) ret_type = ap_type_f64;

			 m_obj = obj_init(0, ap_type_t, 1, ret_type);;
		 }

		 type(const type& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
		 type(type&& par)	   : m_obj(obj_init_as_ref(par.m_obj)) {}
		~type()								   { obj_deinit(m_obj); }

		auto operator()()					{ return details::var<type<T>>			     (*this)	 ; }
		auto operator()(ops_arg_t auto par) { return details::var<type<T>, decltype(par)>(*this, par); }
	};					   

	template <>
	class type<void>			{
		AP_TYPE_FRIEND
		::obj* m_obj;
	public:
		 type()					;
		 type(const type<void>&);
		 type(type<void>&&)	    ;
		~type()					;
	};

	template <>
	class type<>	{
		AP_TYPE_FRIEND
		::obj* m_obj;
	public:
		 type(const char*)  ;
		 type(const type<>&);
		 type(type<>&&)	    ;
		~type()			    ;

		auto operator()()				  ;
		auto operator()(ops_arg_t auto...);
	};

	template <elem_t... T>
	class type<T...> {
		AP_TYPE_FRIEND
		::obj* m_obj;
	public:
		 type(const char*, T...);
		 type(const type<T...>&);
		 type(type<T...>&&)		;
		~type()					;

		auto operator()()																 { return details::var<type<T...>>				    (*this)		   ; }
		auto operator()(ops_arg_t auto... par) requires (sizeof...(par) == sizeof...(T)) { return details::var<type<T...>, decltype(par)...>(*this, par...); }
	};

	template <elem_t... T> type(const char*, T...) -> type<T...>;

	template <elem_t... T>
	type<T...>::type(const char* par_name, T... par)
		: m_obj(obj_init(0, ap_type_t, sizeof...(par) + 2, ap_type_strt, par_name, (par.m_obj)...))
			{}

	template <elem_t... T> type<T...>:: type(const type<T...>& par) : m_obj(obj_init_as_ref(par.m_obj)) {}
	template <elem_t... T> type<T...>:: type(type<T...>&& par)	    : m_obj(obj_init_as_ref(par.m_obj)) {}
	template <elem_t... T> type<T...>::~type()								        { obj_deinit(m_obj); }
}

#endif