#ifndef CSTL_ITERATOR_H
#define CSTL_ITERATOR_H

typedef struct iterator_t iterator_t;

void iterator_drop(iterator_t *this);

void *iterator_next(iterator_t *this);

#endif
