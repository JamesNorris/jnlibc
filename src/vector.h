#ifndef JN_VECTOR_H
#define JN_VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

struct vector {
    double x;
    double y;
};
typedef struct vector vector;

extern void vec_add(struct vector* vec, struct vector* other);
extern void vec_sub(struct vector* vec, struct vector* other);
extern void vec_mult(struct vector* vec, struct vector* other);
extern void vec_div(struct vector* vec, struct vector* other);

extern double vec_mag(struct vector* vec);
extern void vec_conj(struct vector* vec);

extern int vec_equ(struct vector* one, struct vector* two);
extern struct vector* vec_dup(struct vector* vec);

#endif