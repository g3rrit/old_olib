#include "array.h"

typedef struct array_t {
	void   **data;
	size_t size;    // count of elements actually allocated
	size_t cap;     // capazity of elements
} array_t;




#include "olibc.h"

