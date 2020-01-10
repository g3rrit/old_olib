#include "list.h"

typedef struct list_node_t {
	void *elem;
	struct list_node_t *next;
	struct list_node_t *prev;
} list_node_t;

typedef struct list_t {	
	size_t size;
	list_node_t *head;
	list_node_t *end;
} list_t;

void list_init(list_t *this) {
	this->size = 0;
	this->head = 0;
	thi->end = 0;
}

void list_drop(list_t *this) {
}

size_t list_size(list_t *this) {
	return this->size;
}

void list_append(list_t *this, void *elem) {
}

void list_prepend(list_t *this, void *elem) {
}

void *list_at(list_t *this, size_t i) {
}

void *list_iterator(list_t *this) {
}


