#include "iterator.h"

typedef struct iterator_t {
	void *_data;
	void *(*_next)(void*);
	void (*_drop)(void*);
} iterator_t;

void iterator_drop(iterator_t *this) {
	if (!this) return;

	this->_drop(this->data);
	free(this);
}

void *iterator_next(iterator_t *this) {
	CHECK_THIS(this);

	return this->_next(this->data);
}



