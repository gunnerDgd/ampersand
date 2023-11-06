#include "list_it.h"

__it_trait __list_it_trait  = {
	.on_next = &__list_it_next,
	.on_get  = &__list_it_get ,
	.on_set  = &__list_it_set ,
	.on_lt   = &__list_it_lt  ,
	.on_gt   = &__list_it_gt  ,
	.on_eq   = &__list_it_eq
};

void
	__list_it_begin
		(__list* par_list, __it* par_it) {
			par_it->it_parent = par_list			;
			par_it->it		  = par_list->begin.next;
			par_it->trait	  = &__list_it_trait    ;
}

void
	__list_it_end
		(__list* par_list, __it* par_it) {
			par_it->it_parent =  par_list		;
			par_it->it		  = &par_list->end  ;
			par_it->trait	  = &__list_it_trait;
}

bool_t
	__list_it_next
		(__it* par_next) {
			__list	    *list      = par_next->it_parent;
			__list_elem *list_elem = par_next->it		;

			if (list_elem == &list->end)
				return false_t;

			par_next->it = list_elem->next;
			return true_t;
}

void*
	__list_it_get
		(__it* par_iter) {
			return ((__list_elem*)par_iter->it)->elem;
}

void*
	__list_it_set
		(__it* par_iter, void* par_set) {
			__list_elem *elem	  = par_iter->it;
			void		*elem_ptr = elem->elem  ;

			if (elem == &((__list*)par_iter)->end)
				return 0;

			elem->elem = par_set;
			return elem_ptr;
}

bool_t
	__list_it_eq
		(__it* par_iter, __it* par_iter_cmp) {
			return par_iter->it == par_iter_cmp->it;
}

bool_t
	__list_it_lt
		(__it* par_iter, __it* par_iter_cmp) {
			return false_t;
}

bool_t
	__list_it_gt
		(__it* par_iter, __it* par_iter_cmp) {
			return false_t;
}