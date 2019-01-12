#include "vector.h"

void vec_add(struct vector* vec, struct vector* other) {
    vec->x += other->x;
    vec->y += other->y;
}

void vec_sub(struct vector* vec, struct vector* other) {
    vec->x -= other->x;
    vec->y -= other->y;
}

void vec_mult(struct vector* vec, struct vector* other) {
    vec->x *= other->x;
    vec->y *= other->y;
}

void vec_div(struct vector* vec, struct vector* other) {
    vec->x /= other->x;
    vec->y /= other->y;
}

double vec_mag(struct vector* vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y);
}

struct vector* vec_conj(struct vector* vec) {
    struct vector* conj = malloc(sizeof(struct vector));
    conj->x = vec->x;
    conj->y = -vec->y;

    return conj;
}

int vec_equ(struct vector* one, struct vector* two) {
    return one->x == two->x && one->y == two->y;
}

struct vector* vec_dup(struct vector* vec) {
    struct vector* copy = malloc(sizeof(struct vector));
    memcpy(vec, copy, sizeof(struct vector));
    return copy;
}