#ifndef SLIBC_H
#define SLIBC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define CHECK_THIS(_t) do { if (!_t) return 0; } while(0);

void panic(const char *fmt, ...);

void *smalloc(size_t size);

#endif
