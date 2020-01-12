#include "obj.h"

#include "olibc.h"

typedef struct obj_t {
	void *_data;
	void (*_drop)(void*);
} obj_t;

void *obj(void *data, void (*_drop)(void*)) {
	obj_t *res = smalloc(sizeof(obj_t));
	res->_data = data;
	return res->_data;
}

void drop(void *this) {
	if (!this) return;
	obj_t *obj = this;
	obj->_drop(this);
	free(obj);
}


