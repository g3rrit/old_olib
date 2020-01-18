#include "olibc.h"

#include <stddef.h>
#include <stdarg.h>

void panic(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  printf("ERROR: ");
  vprintf(fmt, args);
  va_end(args);
  exit(-1);
}

void *smalloc(size_t size) {
	void *res = malloc(size);
	if (!res) panic("unable to allocated memory of size: %d\n", size);
	return res;
}

typedef struct ptr_t {
	dropf    _drop;
	uint32_t _rc;
	uint8_t  _data[];
} ptr_t;

#define DIFF_PTR(data_) (data_ - offsetof(ptr_t, _rc))

void *ptr(size_t size, dropf dropfn) {
	ptr_t *res = smalloc(offsetof(ptr_t, _rc) + size);
	res->_drop = dropfn;
	res->_rc   = 1;
	return (void*) res->_data;
}

void *share(void *data) {
	if (!data) return 0;
	ptr_t *ptr = DIFF_PTR(data);
	ptr->_rc++;
	return data;
}

void drop(void *data) {
	if (!data) return;
	ptr_t *ptr = DIFF_PTR(data);
	if (--ptr->_rc) return;
	if (ptr->_drop) ptr->_drop(data);
	free(ptr);
}


