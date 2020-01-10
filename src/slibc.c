#include "slibc.h"

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


