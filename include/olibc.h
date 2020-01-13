#ifndef OLIBC_H
#define OLIBC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <Block.h>

#define CHECK_THIS(_t) do { if (!_t) return 0; } while(0);

#define LAMBDA(rt, at, b) Block_copy( ^ rt at b)
#define LAMBDA_RELEASE Block_release

typedef void (^dropf)(void*);

void panic(const char *fmt, ...);

void *smalloc(size_t size);

void *ptr(void *data, dropf drop);

void *share(void *data);

void drop(void *this);

#endif
