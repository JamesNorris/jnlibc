#ifndef JN_ERROR_H
#define JN_ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define PANIC(TEXT)                               \
	printf(#TEXT);                                \
	exit(0);

#define ASSERT(COND)                              \
	if (!(COND)) {                                \
		PANIC(ASSERTION FAILED: #COND);           \
	}

#endif// JN_ERROR_H