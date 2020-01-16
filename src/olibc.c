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

void *ptr(size_t size, dropf drop) {
	ptr_t *res = smalloc(offsetof(ptr_t, _rc) + size);
	res->_drop = drop;
	res->_rc   = 1;
	return (void*) res->_data;
}

void *share(void *data) {
	if (!data) return 0;
	ptr_t *ptr = data - offsetof(ptr_t, _rc);
	ptr->_rc++;
	return data;
}

void drop(void *data) {
	if (!data) return;
	ptr_t *ptr = data - offsetof(ptr_t, _rc);
	if (--ptr->_rc) return;
	if (ptr->_drop) ptr->_drop(data);
	free(ptr);
}


