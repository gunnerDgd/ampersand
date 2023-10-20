#include "list.h"

bool_t
    __list_init(__list* par_list, __alloc* par_alloc) {
        par_list->begin.next = &par_list->end;
        par_list->begin.prev =              0;

        par_list->end.prev   = &par_list->begin;
        par_list->end.next   =                0;

        par_list->alloc      = par_alloc;

        return true_t;
}

bool_t
    __list_init_as_clone(__list* par_list, __list* par_list_clone) {
        if(!par_list_clone->alloc) return false_t;

        __list_init (par_list,  par_list_clone->alloc);
        __list_elem *push_cur = par_list_clone->begin.next;

        while(push_cur->next)
            __list_push_back(par_list, __obj_init_as_clone(push_cur->elem));

        return true_t;
}

void
    __list_deinit(__list* par_deinit) {
        while(par_deinit->begin.next != &par_deinit->end)
            __list_pop_front(par_deinit);
}

__list_elem*
    __list_push_back(__list* par_list, __obj* par_object) {
        if(!par_list->alloc) return 0;

        __mem       *ret_mem   = __mem_init(par_list->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
        __list_elem *ret       = ret_mem->ptr      ;
                     ret->mem  = ret_mem		   ;
                     ret->next = &par_list->end	   ;
                     ret->prev =  par_list->end.prev;

                     ret->elem = __obj_init_as_ref(par_object);
                     ret->list = par_list;
                                 par_list->end.prev->next = ret;
								 par_list->end.prev       = ret;

        return       ret;
}

__list_elem*
    __list_push_front(__list* par_list, __obj* par_object) {
        __mem       *ret_mem   = __mem_init(par_list->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
        __list_elem *ret       = ret_mem->ptr;

                     ret->next =  par_list->begin.next;
                     ret->prev = &par_list->begin;

                     ret->elem = __obj_init_as_ref(par_object);
                     ret->list = par_list;
                                 par_list->begin.next->prev = ret;
								 par_list->begin.next       = ret;

        return       ret;
}

__list_elem*
    __list_push_at(__list* par_list, __obj* par_object, __list_elem* par_at) {
        if(!par_at)                   return 0;
        if (par_at->list != par_list) return 0;

        __mem       *ret_mem   = __mem_init(par_list->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
        __list_elem *ret       = ret_mem->ptr;

                     ret->mem  = ret_mem     ;
                     ret->prev = par_at      ;
                     ret->next = par_at->next;

                     ret->elem = __obj_init_as_ref(par_object);
                     ret->list = par_list;
                                 par_at->next = ret;

        return       ret;
}

void
    __list_pop_front(__list* par_list) {
        __list_elem *ret_elem = par_list->begin.next; if (ret_elem == &par_list->end) return;
        __obj       *ret      = ret_elem->elem;

                     ret_elem->prev->next = ret_elem->next;
                     ret_elem->next->prev = ret_elem->prev;

        __mem_deinit(ret_elem->mem);
        __obj_deinit(ret);
}

void
    __list_pop_back(__list* par_list) {
        __list_elem *ret_elem = par_list->end.prev; if (ret_elem == &par_list->begin) return;
        __obj       *ret      = ret_elem->elem;

                     ret_elem->prev->next = ret_elem->next;
                     ret_elem->next->prev = ret_elem->prev;

        __mem_deinit(ret_elem->mem);
        __obj_deinit(ret);
}

void
    __list_pop_at(__list* par_list, __list_elem* par_pop) {
        __obj *ret = par_pop->elem; if (par_pop->list != par_list) return;
                     par_pop->prev->next = par_pop->next;
                     par_pop->next->prev = par_pop->prev;

        __mem_deinit(par_pop->mem);
        __obj_deinit(ret);
}