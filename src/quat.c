#include "quat.h"

void quat_add(struct quaternion* quat, struct quaternion* other) {
    quat->w += other->w;
    quat->x += other->x;
    quat->y += other->y;
    quat->z += other->z;
}

void quat_sub(struct quaternion* quat, struct quaternion* other) {
    quat->w -= other->w;
    quat->x -= other->x;
    quat->y -= other->y;
    quat->z -= other->z;
}

void quat_mult(struct quaternion* quat, struct quaternion* other) {
    quat->w *= other->w;
    quat->x *= other->x;
    quat->y *= other->y;
    quat->z *= other->z;
}

void quat_div(struct quaternion* quat, struct quaternion* other) {
    quat->w /= other->w;
    quat->x /= other->x;
    quat->y /= other->y;
    quat->z /= other->z;
}

double quat_mag(struct quaternion* quat) {
    return sqrt(quat->w * quat->w + quat->x * quat->x + quat->y * quat->y + quat->z * quat->z);
}

struct quaternion* quat_norm(struct quaternion* quat) {
    double mag = quat_mag(quat);

    struct quaternion* norm = malloc(sizeof(struct quaternion));
    norm->w = quat->w / mag;
    norm->x = quat->x / mag;
    norm->y = quat->y / mag;
    norm->z = quat->z / mag;

    return norm;
}

struct quaternion* quat_conj(struct quaternion* quat) {
    struct quaternion* conj = malloc(sizeof(struct quaternion));
    conj->w = quat->w;
    conj->x = -quat->x;
    conj->y = -quat->y;
    conj->z = -quat->z;

    return conj;
}

int quat_equ(struct quaternion* one, struct quaternion* two) {
    return one->w == two->w && one->x == two->x && one->y == two->y && one->z == two->z;
}

struct quaternion* quat_dup(struct quaternion* quat) {
    struct quaternion* copy = malloc(sizeof(struct quaternion));
    memcpy(quat, copy, sizeof(struct quaternion));
    return copy;
}