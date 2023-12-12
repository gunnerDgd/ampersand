#include "ap.h"
#include <stdlib.h>

bool_t ap_mem_res_new() { return true_t; }
void   ap_mem_res_del() { return true_t; }

void*  ap_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   ap_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res		  ap_mem_res		 ;
mem_res_trait ap_mem_res_trait = {
	.on_new		= &ap_mem_res_new,
	.on_del		= &ap_mem_res_del,

	.on_mem_new = &ap_mem_new	 ,
	.on_mem_del = &ap_mem_del
};

ap_type ap_i8  , ap_i16, ap_i32, ap_i64,
        ap_u8  , ap_u16, ap_u32, ap_u64,
        ap_f32 ,
        ap_f64 ,
		ap_none,
		ap_bool,
		ap_any ;

void 
	ap_init()										  {
		mem_res_new(&ap_mem_res, &ap_mem_res_trait, 0);
		set_mem_res(&ap_mem_res);

		ap_i8   = make (ap_type_t) from (1, ap_type_id_i8) ;
		ap_i16  = make (ap_type_t) from (1, ap_type_id_i16);
		ap_i32  = make (ap_type_t) from (1, ap_type_id_i32);
		ap_i64  = make (ap_type_t) from (1, ap_type_id_i64);

		ap_u8   = make (ap_type_t) from (1, ap_type_id_u8) ;
		ap_u16  = make (ap_type_t) from (1, ap_type_id_u16);
		ap_u32  = make (ap_type_t) from (1, ap_type_id_u32);
		ap_u64  = make (ap_type_t) from (1, ap_type_id_u64);

		ap_f32  = make (ap_type_t) from (1, ap_type_id_f32);
		ap_f64  = make (ap_type_t) from (1, ap_type_id_f64);

		ap_bool = make (ap_type_t) from (1, ap_type_id_bool);
		ap_none = make (ap_type_t) from (1, ap_type_id_none);
		ap_any  = make (ap_type_t) from (1, ap_type_id_any) ;
}

void 
	ap_deinit()     {
		del (ap_i8) ;
		del (ap_i16);
		del (ap_i32);
		del (ap_i64);

		del (ap_u8) ;
		del (ap_u16);
		del (ap_u32);
		del (ap_u64);

		del (ap_f32);
		del (ap_f64);

		del (ap_bool);
		del (ap_none);
		del (ap_any) ;

		set_mem_res(0);
		mem_res_del(&ap_mem_res);
}