#include "list.h"

int voidptr_to_int(void* ptr) {
	return *((int*) (&ptr));
}

int integer_compare(void* one, void* two) {
	return voidptr_to_int(one) - voidptr_to_int(two);
}

int main(int argc, char* argv[]) {
	struct list* list = list_init();
	
	printf("SIZE: %d EXPECTED: 0\n", list_size(list));
	
	list_push_back(list, (void*) 500);
	
	printf("SIZE: %d EXPECTED: 1\n", list_size(list));
	
	struct list_elem* thousand = list_push_back(list, (void*) 1000);
	list_push_back(list, (void*) 1500);
	
	printf("SIZE: %d EXPECTED: 3\n", list_size(list));
	
	printf("EXPECT 1: %d\n", list_contains(list, thousand));
	
	/*
	500
	1000
	1500
	*/
	
	printf("BEGIN\n");
	
	struct list_elem* elem = list_begin(list);
	for (int i = 0; i < 7; i++) {
		printf("LOOP\n");
		printf("%d\n", (list_at(list, i % 3)));
		printf("%d\n", list_entry(elem));
		elem = list_prev(elem);
		printf("INDEX: %d\n", i);
	}
	
	printf("END\n");
	
	printf("EXPECT 1: %d\n", list_contains(list, (void*) 500, &integer_compare));
	printf("EXPECT 0: %d\n", list_contains(list, (void*) 525, &integer_compare));
	
	elem = list_begin(list);
	for (int i = 0; i < list_size(list); i++) {
		printf("%d\n", list_entry(elem));
		elem = list_next(elem);
	}
	
	list_remove(list, list_begin(list));
	
	/*
	1000
	1500
	*/
	
	printf("EXPECT 0: %d\n", list_contains(list, (void*) 500, &integer_compare));
	
	printf("EXPECT -1: %d\n", list_index_of(list, (void*) 500, &integer_compare));
	printf("EXPECT 1: %d\n", list_index_of(list, (void*) 1500, &integer_compare));
	
	elem = list_begin(list);
	for (int i = 0; i < list_size(list); i++) {
		printf("%d\n", list_entry(elem));
		elem = list_next(elem);
	}
	
	printf("EXPECT 1500: %d\n", voidptr_to_int(list_at(list, 1)));
	
	list_push_front(list, (void*) 1500);
	
	/*
	1500
	1000
	1500
	*/
	
	printf("EXPECT 1500: %d\n", voidptr_to_int(list_at(list, 0)));
	
	list_remove(list, (void*) 1500, &integer_compare);
	list_remove(list, list_begin(list));
	list_remove(list, 0);
	
	/*
	EMPTY
	*/
	
	printf("EXPECT 0: %d\n", list_at(list, 0));
	
	list_insert(list, 0, (void*) 500);
	
	printf("EXPECT 500: %d\n", list_at(list, 0));
	
	printf("EXPECT 0: %d\n", list_contains(list, (struct list_elem*) malloc(sizeof(struct list_elem))));
	
	printf("TERMINATED");
	
	return 0;
}