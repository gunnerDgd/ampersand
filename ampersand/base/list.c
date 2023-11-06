#include "list.h"

#include "details/list.h"
#include "details/list_it.h"

obj_trait* list_t = &__list_trait;

bool_t
    list_init
        (list* par, alloc* par_alloc) {
            if(!par_alloc) par_alloc = get_alloc();
            if(!par_alloc) return false_t;

            return __list_init(par, par_alloc);
}

bool_t
    list_init_as_clone
        (list* par, list* par_clone) {
            if(!((__list*)par_clone)->alloc)
                return false_t;

            return __list_init_as_clone(par, par_clone);
}

void
    list_deinit
        (list* par) {
            if(!((__list*)par)->alloc)
                return;

            __list_deinit(par);
}

it
    list_push_back
        (list* par, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_back(par, par_object);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_front
        (list* par, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_front(par, par_object);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_at
        (list* par, obj* par_push, it* par_at) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_at(par, par_push, ((__it*)par_at)->it);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

void
    list_pop_front
        (list* par) {
            __list_pop_front(par);
}

void
    list_pop_back
        (list* par) {
            __list_pop_back(par);
}

void
    list_pop_at
        (list* par, it* par_at) {
            __list_pop_at(par, ((__it*)par_at)->it);
}

it
	list_begin
        (list* par) {
            it ret;
            __list_it_begin(par, &ret);
        
            return ret;
}

it
	list_end
        (list* par) {
            it ret;
            __list_it_end(par, &ret);

            return ret;
}