#include "iterator.h"

typedef struct iterator_t {
	void *_data;
	void *(*_next)(void*);
	void (*_drop)(struct iterator_t*);
} iterator_t;


