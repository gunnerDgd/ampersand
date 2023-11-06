#ifndef AMPERSAND_META_HPP
#define AMPERSAND_META_HPP

#include "meta/declare.hpp"

#include "meta/type.hpp"
#include "meta/elem.hpp"

#include "meta/func.hpp"
#include "meta/obj.hpp"

#include "meta/script.hpp"

namespace ap				      {
	type<bool>			boolean ();

	type<std::int8_t>   i8      ();
	type<std::int16_t>  i16		();
	type<std::int32_t>  i32		();
	type<std::int64_t>  i64		();

	type<std::uint8_t>  u8		();
	type<std::uint16_t> u16		();
	type<std::uint32_t> u32		();
	type<std::uint64_t> u64		();

	type<float>			f32		();
	type<double>		f64		();

	type<void>			none	();
}

#endif