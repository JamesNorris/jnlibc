#include "vector.h"

void vec_add(struct vector* vec, struct vector* other) {
    vec->x += other->x;
    vec->y += other->y;
    vec->z += other->z;
}

void vec_sub(struct vector* vec, struct vector* other) {
    vec->x -= other->x;
    vec->y -= other->y;
    vec->z -= other->z;
}

void vec_mult(struct vector* vec, struct vector* other) {
    vec->x *= other->x;
    vec->y *= other->y;
    vec->z *= other->z;
}

void vec_div(struct vector* vec, struct vector* other) {
    vec->x /= other->x;
    vec->y /= other->y;
    vec->z /= other->z;
}

double vec_mag(struct vector* vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

struct vector* vec_norm(struct vector* vec) {
    double mag = vec_mag(vec);

    struct vector* norm = (struct vector*) malloc(sizeof(struct vector));
    norm->x = vec->x / mag;
    norm->y = vec->y / mag;
    norm->z = vec->z / mag;

    return norm;
}

int vec_equ(struct vector* one, struct vector* two) {
    return one->x == two->x && one->y == two->y && one->z == two->z;
}

struct vector* vec_dup(struct vector* vec) {
    struct vector* copy = (struct vector*) malloc(sizeof(struct vector));
    copy->x = vec->x;
    copy->y = vec->y;
    copy->z = vec->z;
    return copy;
}