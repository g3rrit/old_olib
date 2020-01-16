#include "iterator.h"

#include "olibc.h"

typedef struct iterator_t {
	void *_data;
	void *(*_next)(void*);
} iterator_t;

iterator_t *iterator_new(void *data, void *(*next)(void*)) {
	void _drop(void *t) {
		if (!t) return;
		drop(((iterator_t*)t)->_data);
	}

	iterator_t *res = ptr(sizeof(iterator_t), &_drop);
	res->_data = data;
	res->_next = next;

	return res;
}

void *iterator_next(iterator_t *this) {
	CHECK_THIS(this);

	return this->_next(this->_data);
}

