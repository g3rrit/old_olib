#include "iterator.h"

#include "obj.h"
#include "olibc.h"

typedef struct iterator_t {
	void *_data;
	void *(*_next)(void*);
} iterator_t;

void _iterator_drop(iterator_t *this) {
	if (!this) return;
	drop(this->_data);
	free(this);
}

iterator_t *iterator_new(void *data, void *(*next)(void*)) {
	iterator_t *res = smalloc(sizeof(iterator_t));
	res->_data = data;
	res->_next = next;
	return obj(res, &_iterator_drop);
}

void *iterator_next(iterator_t *this) {
	CHECK_THIS(this);

	return this->_next(this->_data);
}



