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
typedef struct list_elem list_elem;

struct list {
	int size;
	
	struct list_elem* head;
	struct list_elem* tail;
};
typedef struct list list;

extern struct list* list_init();
extern void list_destroy(struct list* list, int free_data);//if free_data, this will free the data stored in each list_elem

extern int list_size(struct list* list);

extern int list_index_of(struct list* list, struct list_elem* elem);//-1 if not found
extern int list_index_of_data(struct list* list, void* data, compare_func func /*see comparison.h*/);

extern int list_contains(struct list* list, struct list_elem* elem);//0 if not found
extern int list_contains_data(struct list* list, void* data, compare_func func /*see comparison.h*/);

extern void* list_at(struct list* list, int index);

extern void* list_entry(struct list_elem* elem);

extern struct list_elem* list_next(struct list_elem* elem);
extern struct list_elem* list_prev(struct list_elem* elem);

extern struct list_elem* list_begin(struct list* list);//head
extern struct list_elem* list_end(struct list* list);//tail

extern struct list_elem* list_insert(struct list* list, int index, void* data);//inserts AT index (before the current element at that index)
extern struct list_elem* list_insert_before(struct list* list, struct list_elem* next, void* data);//inserts before next
extern struct list_elem* list_insert_after(struct list* list, struct list_elem* prev, void* data);//inserts after prev
extern struct list_elem* list_push_front(struct list* list, void* data);
extern struct list_elem* list_push_back(struct list* list, void* data);//inserted at end

extern void* list_pop_front(struct list* list);//returns data at head, removes and replaces head TEST
extern void* list_pop_back(struct list* list);//returns data at tail, removes and replaces tail TEST

extern int list_remove_at(struct list* list, int index);//0 if found, -1 otherwise TEST
extern int list_remove(struct list* list, struct list_elem* elem);
extern int list_remove_data(struct list* list, void* data, compare_func func /*see comparison.h*/);//TEST

#endif// JN_LIST_H