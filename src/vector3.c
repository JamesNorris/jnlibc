#include "vector3.h"

void vec3_add(struct vector3* vec, struct vector3* other) {
    vec->x += other->x;
    vec->y += other->y;
    vec->z += other->z;
}

void vec3_sub(struct vector3* vec, struct vector3* other) {
    vec->x -= other->x;
    vec->y -= other->y;
    vec->z -= other->z;
}

void vec3_mult(struct vector3* vec, struct vector3* other) {
    vec->x *= other->x;
    vec->y *= other->y;
    vec->z *= other->z;
}

void vec3_div(struct vector3* vec, struct vector3* other) {
    vec->x /= other->x;
    vec->y /= other->y;
    vec->z /= other->z;
}

double vec3_mag(struct vector3* vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void vec3_norm(struct vector3* vec) {
    double mag = vec3_mag(vec);

    vec->x /= mag;
    vec->y /= mag;
    vec->z /= mag;
}

int vec3_equ(struct vector3* one, struct vector3* two) {
    return one->x == two->x && one->y == two->y && one->z == two->z;
}

struct vector3* vec3_dup(struct vector3* vec) {
    struct vector3* copy = malloc(sizeof(struct vector3));
    memcpy(vec, copy, sizeof(struct vector3));
    return copy;
}