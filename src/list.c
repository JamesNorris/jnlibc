#include "list.h"

struct list* list_init() {
	struct list* list = (struct list*) malloc(sizeof(struct list));
	
	list->size = 0;
	list->head = 0;//null
	list->tail = 0;//null
	
	return list;
}

void list_destroy(struct list* list, int free_data) {
	ASSERT(list);
	
	struct list_elem* cur = list->head;
	struct list_elem* next;
	
	void* data;
	
	while(next != cur) {//all but the last element
		next = cur->next;
		
		data = cur->data;
		
		if (data && free_data) {
			free(data);
		}
		
		free(cur);
		
		cur = next;
	}
	
	free(list);
}

int list_size(struct list* list) {
	ASSERT(list);
	
	return list->size;
}

int list_index_of(struct list* list, struct list_elem* elem) {
	ASSERT(list);
	ASSERT(elem);
	
	int index = 0;
	struct list_elem* cur = list->head;
	
	while(cur != elem) {
		index++;
		cur = cur->next;
		
		if (index == list->size) {
			return -1;
		}
	}
	
	return index;
}

int list_index_of_data(struct list* list, void* data, compare_func func) {
	ASSERT(list);
	ASSERT(data);
	ASSERT(func);
	
	struct list_elem* cur = list->head;
	
	if (cur == 0) {//empty list
		return -1;
	}
	
	int len = list->size;
	
	for (int i = 0; i < len; i++) {
		if (func(data, cur->data) == 0) return i;//found
		
		cur = cur->next;
	}
	
	return -1;
}

int list_contains(struct list* list, struct list_elem* elem) {
	return list_index_of(list, elem) != -1;
}

int list_contains_data(struct list* list, void* data, compare_func func) {	
	return list_index_of_data(list, data, func) != -1;
}

void* list_at(struct list* list, int index) {
	ASSERT(list);
	ASSERT(index >= 0);
	//ASSERT(list->head);
	
	if (list->size == 0) {//empty list
		return 0;//null
	}
	
	ASSERT(index < list->size);
	
	struct list_elem* cur = list->head;
	
	for (int i = 1; i <= index; i++) {
		cur = cur->next;
	}
	
	return cur->data;
}

void* list_entry(struct list_elem* elem) {
	ASSERT(elem);
	
	return elem->data;
}

struct list_elem* list_next(struct list_elem* elem) {
	ASSERT(elem);
	
	return elem->next;
}

struct list_elem* list_prev(struct list_elem* elem) {
	ASSERT(elem);
	
	return elem->prev;
}

struct list_elem* list_begin(struct list* list) {
	ASSERT(list);
	
	return list->head;
}

struct list_elem* list_end(struct list* list) {
	ASSERT(list);
	
	return list->tail;
}

struct list_elem* list_insert(struct list* list, int index, void* data) {
	ASSERT(list);
	ASSERT(index >= 0);
	ASSERT(index <= list->size);
	ASSERT(data);
	
	if (!list->size) {
		struct list_elem* elem = (struct list_elem*) malloc(sizeof(struct list_elem));
		
		elem->data = data;
		
		elem->next = elem;
		elem->prev = elem;
		
		list->head = elem;
		list->tail = elem;
		
		list->size += 1;
		
		return elem;
	}
	
	//TODO this can be more efficient:
	
	struct list_elem* cur = list->head;
	
	if (index == 0) {
		return list_insert_before(list, cur, data);
	}
	
	for (int i = 1; i < index; i++) {
		cur = cur->next;
	}
	
	return list_insert_after(list, cur, data);
}

struct list_elem* list_insert_before(struct list* list, struct list_elem* next, void* data) {
	ASSERT(list);
	ASSERT(next);
	ASSERT(data);
	
	ASSERT(list_contains(list, next));
	
	struct list_elem* elem = (struct list_elem*) malloc(sizeof(struct list_elem));
	
	elem->data = data;
	
	elem->next = next;
	elem->prev = next->prev;
	
	elem->next->prev = elem;
	elem->prev->next = elem;
	
	if (next == list->head) {
		//list->head->prev = elem;
		//list->tail->next = elem;
		list->head = elem;
	}
	
	list->size += 1;
	
	return elem;
}

struct list_elem* list_insert_after(struct list* list, struct list_elem* prev, void* data) {
	ASSERT(list);
	ASSERT(prev);
	ASSERT(data);
	
	ASSERT(list_contains(list, prev));
	
	struct list_elem* elem = (struct list_elem*) malloc(sizeof(struct list_elem));
	
	elem->data = data;
	
	elem->next = prev->next;
	elem->prev = prev;
	
	elem->next->prev = elem;
	elem->prev->next = elem;
	
	if (prev == list->tail) {
		//list->head->prev = elem;
		//list->tail->next = elem;
		list->tail = elem;
	}
	
	list->size += 1;
	
	return elem;
}

struct list_elem* list_push_front(struct list* list, void* data) {
	return list_insert(list, 0, data);
}

struct list_elem* list_push_back(struct list* list, void* data) {
	return list_insert(list, list->size, data);
}

void* list_pop_front(struct list* list) {
	ASSERT(list);
	
	struct list_elem* head = list->head;
	
	ASSERT(head);
	
	void* data = head->data;
	
	list_remove(list, head);
	
	return data;
}

void* list_pop_back(struct list* list) {
	ASSERT(list);
	
	struct list_elem* tail = list->tail;
	
	ASSERT(tail);
	
	void* data = tail->data;
	
	list_remove(list, tail);
	
	return data;
}

int list_remove_at(struct list* list, int index) {
	ASSERT(list);
	ASSERT(index >= 0);
	ASSERT(index < list->size);
	
	struct list_elem* cur = list->head;
	
	for (int i = 1; i < index; i++) {
		cur = cur->next;
	}
	
	return list_remove(list, cur) != -1;
}

int list_remove(struct list* list, struct list_elem* elem) {
	ASSERT(list);
	ASSERT(elem);
	
	if (!list_contains(list, elem)) {
		return -1;
	}
	
	if (list->size == 1) {
		list->head = 0;//null
		list->tail = 0;//null
		free(elem);
	} else if (elem == list->head) {
		list->head = elem->next;
		list->head->prev = list->tail;
		list->tail->next = list->head;
		free(elem);
	} else if (elem == list->tail) {
		list->tail = elem->prev;
		list->tail->next = list->head;
		list->head->prev = list->tail;
		free(elem);
	} else {
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		free(elem);
	}
	
	list->size -= 1;
	
	return 0;
}

int list_remove_data(struct list* list, void* data, compare_func func) {
	ASSERT(list);
	ASSERT(data);
	ASSERT(func);
	
	int index = list_index_of_data(list, data, func);
	
	if (index == -1) {
		return -1;
	}
	
	return list_remove_at(list, index);
}
