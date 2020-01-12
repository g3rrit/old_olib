#ifndef OLIBC_ITERATOR_H
#define OLIBC_ITERATOR_H

typedef struct iterator_t iterator_t;

/**
 * Creates a new iterator.
 * Creates a new iterator needs to be dropped after usage (@see drop).
 * This function is mainly to be used by the library itself.
 * @param data an obj storing some data by the iterator.
 * @param next a functions that gets called on requesting the next element of an iterator.
 *              @see iterator_next
 */
iterator_t *iterator_new(void *data, void *(*next)(void*));

/**
 * Retrieves the next element of the iterator.
 * Retrieves the next element of the iterator, if present.
 * If the iterator is at its end 0 is returned.
 * @param this the iterator referenced.
 * @return the next element.
 *         0 if the iterator is at its end.
 */
void *iterator_next(iterator_t *this);

#endif
