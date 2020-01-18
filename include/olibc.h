#ifndef OLIBC_H
#define OLIBC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define CHECK_THIS(_t) do { if (!_t) return 0; } while(0);

typedef void (*dropf)(void*);

/**
 * Prints an error message and stops execution.
 * Prints an error message, stops execution and returns with code -1.
 * @param fmt the format string for the message to print.
 * @param ... additional arguments used in the format string.
 */
void panic(const char *fmt, ...);

/**
 * Safe allocation function.
 * Safe allocation function, that panics on error.
 * @param size the size in bytes to allocate.
 * @return address of the allocated memory.
 */ 
void *smalloc(size_t size);

/**
 * Allocates an object with a drop function.
 * Allocates an object on the heap, in addtition to.
 * using the provided drop function on dropping the value (@see drop).
 * @param size the size in bytes to allocate.
 * @param dropfn the function function to call on drop.
 * @return pointer to the allocated memory
 */
void *ptr(size_t size, dropf dropfn);

/**
 * Duplicates a pointer.
 * Duplicates a pointer in order the share the contract of dropping the object.
 * The object only gets dropped if #drop = #share - 1
 * @param data address of the object.
 * @return shared pointer to the object.
 */
void *share(void *data);

/**
 * Drops an object.
 * Drops an object previously allocated with ptr (@see ptr).
 * @param data address of the object.
 */
void drop(void *data);

#endif
