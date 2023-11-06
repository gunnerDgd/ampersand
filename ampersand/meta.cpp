#include "meta.hpp"

namespace ap				      {
	type<bool>			boolean() { return type<bool>		   {}; }

	type<std::int8_t>   i8	   () { return type<std::int8_t>   {}; }
	type<std::int16_t>  i16	   () { return type<std::int16_t>  {}; }
	type<std::int32_t>  i32    () { return type<std::int32_t>  {}; }
	type<std::int64_t>  i64    () { return type<std::int64_t>  {}; }

	type<std::uint8_t>  u8     () { return type<std::uint8_t>  {}; }
	type<std::uint16_t> u16    () { return type<std::uint16_t> {}; }
	type<std::uint32_t> u32    () { return type<std::uint32_t> {}; }
	type<std::uint64_t> u64    () { return type<std::uint64_t> {}; }

	type<float>			f32    () { return type<float>  {}; }
	type<double>		f64    () { return type<double> {}; }

	type<void>			none   () { return type<void>   {}; }

	
}