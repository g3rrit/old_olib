#ifndef OLIBC_OBJ_H
#define OLIBC_OBJ_H

typedef void (*dropf)(void*);

void *obj(void *data, void (*_drop)(void*));

void drop(void *this);

#endif
