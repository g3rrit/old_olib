#ifndef OLIBC_H
#define OLIBC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define CHECK_THIS(_t) do { if (!_t) return 0; } while(0);

typedef void (*dropf)(void*);

void panic(const char *fmt, ...);

void *smalloc(size_t size);

void *ptr(size_t size, dropf drop);

void *resize(void *data, size_t size);

void *share(void *data);

void drop(void *data);

#endif
