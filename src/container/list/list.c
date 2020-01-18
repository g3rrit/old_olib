#include "list.h"

#include "olibc.h"

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

list_node_t *list_node_new(void *elem, list_node_t *next, list_node_t *prev) {
	void _drop(void *t) {
		list_node_t *l = t;
		drop(l->elem);
	}

	list_node_t *res = ptr(sizeof(list_node_t), &_drop);
	res->elem = elem;
	res->next = next;
	res->prev = prev;
	return res;
}

void _list_drop(list_t *this) {
	if (!this) return;

	list_node_t *node = this->head;
	list_node_t *fnode = 0;
	for (;node;) {
		fnode = node;	
		node = node->next;	
		drop(fnode);
	}
	this->size = 0;
	this->head = 0;
	this->end  = 0;
}

list_t *list_new() {
	void _drop(void *t) {
		_list_drop((list_t*)t);
	}

	list_t *res = ptr(sizeof(list_t), _drop);
	res->size = 0;
	res->head = 0;
	res->end = 0;

	return res;
}

size_t list_size(list_t *this) {
	return this->size;
}

void list_append(list_t *this, void *elem) {
	if (!this) return;

	list_node_t *node = list_node_new(elem, 0, this->end);

	if (!this->size) {
		this->end = node;
		this->head = node;
	}
	this->size++;
}

void list_prepend(list_t *this, void *elem) {
	if (!this) return;

	list_node_t *node = list_node_new(elem, this->head, this->end);

	if (!this->size) {
		this->end = node;
		this->head = node;
	}
	this->size++;
}

void *list_at(list_t *this, size_t i) {
	if (!this) return 0;
	if (this->size <= i) return 0;

	list_node_t *node = 0;
	if (i <= this->size / 2) {
		node = this->head;
		for (;i;i--) {
			node = node->next;
		}
	} else {
		node = this->end;
		for (i++; i < this->size; i++) {
			node = node->prev;
		}
	}
 
	return node->elem;
}

void *list_iterator_next(void *data) {
	if (!data) return 0;

	list_node_t **elem = (list_node_t**)data;
	*elem = (*elem)->next;
	return *elem;
}

void *list_iterator(list_t *this) {

	list_node_t **data = ptr(sizeof(list_node_t**), 0);
	return iterator_new(data, &list_iterator_next);
}


