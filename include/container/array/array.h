#ifndef OLIBC_ARRAY_H
#define OLIBC_ARRAY_H

#include <stddef.h>

typedef struct array_t array_t;

array_t array_new(size_t cap);

void array_recap(array_t *this, size_t cap);

void array_add(array_t *this, void *elem);

void *array_at(array_t *this, int pos);

void *array_remove(array_t *this, int pos);

#endif
