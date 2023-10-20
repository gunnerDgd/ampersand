#include "list.h"

#include "details/list.h"
#include "details/list_it.h"

#include "default.h"

bool_t
    list_init
        (list* par_list, alloc* par_alloc) {
            if(!par_alloc)
                par_alloc = get_alloc();
            if(!par_alloc)
                return false_t;

            return __list_init(par_list, par_alloc);
}

bool_t
    list_init_as_clone
        (list* par_list, list* par_list_clone) {
            if(!((__list*)par_list_clone)->alloc)
                return false_t;

            return __list_init_as_clone(par_list, par_list_clone);
}

void
    list_deinit(list* par_list) {
        if(!((__list*)par_list)->alloc)
            return;

        __list_deinit(par_list);
}

it
    list_push_back
        (list* par_list, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_back(par_list, par_object);
            ret_it->it_parent = par_list;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_front
        (list* par_list, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_front(par_list, par_object);
            ret_it->it_parent = par_list;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_at
        (list* par_list, obj* par_object, it* par_at) {
            it    ret;
            __it *ret_it = &ret;

            ret_it->it        = __list_push_at(par_list, par_object, ((__it*)par_at)->it);
            ret_it->it_parent = par_list;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

void
    list_pop_front(list* par_list) {
        __list_pop_front(par_list);
}

void
    list_pop_back(list* par_list) {
        __list_pop_back(par_list);
}

void
    list_pop_at(list* par_list, it* par_at) {
        __list_pop_at(par_list, ((__it*)par_at)->it);
}

it
	list_begin(list* par_list) {
        it ret;
        __list_it_begin(par_list, &ret);
        
        return ret;
}

it
	list_end(list* par_list) {
        it ret;
        __list_it_end(par_list, &ret);

        return ret;
}