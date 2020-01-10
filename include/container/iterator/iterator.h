#ifndef SLIBC_ITERATOR_H
#define SLIBC_ITERATOR_H

typedef struct iterator_t iterator_t;

/**
 * Creates a new iterator.
 * Creates a new iterator.
 * This function is mainly to be used by the library itself.
 * @param data a pointer to some data stored by the iterator.
 * @param _drop a function that gets called on deletion of the iterator.
 *              @see iterator_drop
 * @param _next a functions that gets called on requesting the next element of an iterator.
 *              @see iterator_next
 */
iterator_t *iterator_create(void *data, void (*_drop)(void*), void *(*_next)(void*));

/**
 * Drops the iterator after usage.
 * Drops the iterator if no longer needed.
 * This needs to be done in order to avoid memory leaks.
 * @param this the iterator referenced.
 */
void iterator_drop(iterator_t *this);

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
