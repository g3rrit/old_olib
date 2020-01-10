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
	if (!this) return;

	list_node_t *node = this->head;
	list_node_t *fnode = 0;
	for (;node;) {
		fnode = node;	
		node = node->next;	
		free(fnode);
	}
	this->size = 0;
	this->head = 0;
	this->end  = 0;
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


void list_iterator_drop(void *data) { 
	if (!data) return;
	free(data);
}

void *list_iterator_next(void *data) {
	if (!data) return 0;

	list_node_t **elem = (list_node_t**)data;
	*elem = (*elem)->next;
	return *elem;
}

void *list_iterator(list_t *this) {
	list_node_t **data = smalloc(sizeof(list_node_t**));
	return iterator_create(data, &list_iterator_drop, &list_iterator_next);
}


