#include "olibc.h"

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
	void    *_data;
	dropf    _drop;
	uint32_t _rc;
} ptr_t;

void *ptr(void *data, dropf drop) {
	ptr_t *res = smalloc(sizeof(ptr_t));
	res->_data = data;
	res->_drop = drop;
	res->_rc   = 1;
	return res->_data;
}

void *share(void *data) {
	if (!data) return 0;
	ptr_t *ptr = data;
	ptr->_rc++;
	return data;
}

void drop(void *this) {
	if (!this) return;
	ptr_t *ptr = this;
	if (--ptr->_rc) return;
	ptr->_drop(this);
	LAMBDA_RELEASE(ptr->_drop);
	free(this);
}


