#include "iterator.h"

#include "olibc.h"

typedef struct iterator_t {
	void *_data;
	void *(*_next)(void*);
} iterator_t;

iterator_t *iterator_new(void *data, void *(*next)(void*)) {
	iterator_t *res = smalloc(sizeof(iterator_t));
	res->_data = data;
	res->_next = next;
	return ptr(res, LAMBDA(void, (void *this), {
		if (!this) return;
		drop(((iterator_t*)this)->_data);
		free(this);
	}));
}

void *iterator_next(iterator_t *this) {
	CHECK_THIS(this);

	return this->_next(this->_data);
}

