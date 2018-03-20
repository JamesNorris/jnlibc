#ifndef JN_LIST_H
#define JN_LIST_H

#include <string.h>
#include "error.h"
#include "comparison.h"

struct list_elem {
	void* data;
	
	struct list_elem* next;
	struct list_elem* prev;
};

struct list {
	int size;
	
	struct list_elem* head;
	struct list_elem* tail;
};

struct list* list_init();
void list_destroy(struct list* list, int free_data);//if free_data is true, this will free the data stored in each list_elem TEST

int list_size(struct list* list);

int list_index_of(struct list* list, struct list_elem* elem);//-1 if not found
int list_index_of(struct list* list, void* data, compare_func func /*see comparison.h*/);

int list_contains(struct list* list, struct list_elem* elem);//0 if not found
int list_contains(struct list* list, void* data, compare_func func /*see comparison.h*/);

void* list_at(struct list* list, int index);

void* list_entry(struct list_elem* elem);

struct list_elem* list_next(struct list_elem* elem);
struct list_elem* list_prev(struct list_elem* elem);

struct list_elem* list_begin(struct list* list);//head
struct list_elem* list_end(struct list* list);//tail

struct list_elem* list_insert(struct list* list, int index, void* data);//inserts AT index (before the current element at that index)
struct list_elem* list_insert_before(struct list* list, struct list_elem* next, void* data);//inserts before next
struct list_elem* list_insert_after(struct list* list, struct list_elem* prev, void* data);//inserts after prev
struct list_elem* list_push_front(struct list* list, void* data);
struct list_elem* list_push_back(struct list* list, void* data);//inserted at end

void* list_pop_front(struct list* list);//returns data at head, removes head TEST
void* list_pop_back(struct list* list);//returns data at tail, removes tail TEST

int list_remove(struct list* list, int index);//0 if found, -1 otherwise TEST
int list_remove(struct list* list, struct list_elem* elem);
int list_remove(struct list* list, void* data, compare_func func /*see comparison.h*/);//TEST

#endif// JN_LIST_H