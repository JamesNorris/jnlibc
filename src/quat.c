#include "quat.h"

void quat_add(struct quaternion* quat, struct quaternion* other) {
    quat->a += other->a;
    quat->b += other->b;
    quat->c += other->c;
    quat->d += other->d;
}

void quat_sub(struct quaternion* quat, struct quaternion* other) {
    quat->a -= other->a;
    quat->b -= other->b;
    quat->c -= other->c;
    quat->d -= other->d;
}

// Hamilton product
void quat_mult(struct quaternion* quat, struct quaternion* other) {
    quat->a = quat->a * other->a - quat->b * other->b - quat->c * other->c - quat->d * other->d;
    quat->b = quat->a * other->b + quat->b * other->a + quat->c * other->d - quat->d * other->c;
    quat->c = quat->a * other->c + quat->c * other->a + quat->d * other->b - quat->b * other->d;
    quat->d = quat->a * other->d + quat->d * other->a + quat->b * other->c - quat->c * other->b;
}

// inverse Hamilton product
void quat_div(struct quaternion* quat, struct quaternion* other) {
    struct quaternion* inv = quat_dup(other);

    quat_inverse(inv);
    quat_mult(quat, inv);

    free(inv);
}

void quat_scale(struct quaternion* quat, struct quaternion* other) {
    quat->a *= other->a;
    quat->b *= other->b;
    quat->c *= other->c;
    quat->d *= other->d;
}

double quat_mag(struct quaternion* quat) {
    return sqrt(quat->a * quat->a + quat->b * quat->b + quat->c * quat->c + quat->d * quat->d);
}

void quat_norm(struct quaternion* quat) {
    struct quaternion* dup = quat_dup(quat);
    quat_scale(quat, dup);
    free(dup);
}

void quat_conj(struct quaternion* quat) {
    quat->b *= -1;
    quat->c *= -1;
    quat->d *= -1;
}

void quat_inverse(struct quaternion* quat) {
    double inv_scale = 1.0 / quat_mag(quat);

    quat->a *= inv_scale;
    quat->b *= -inv_scale;
    quat->c *= -inv_scale;
    quat->d *= -inv_scale;
}

void quat_rot(struct quaternion* quat, struct vector3* vec) {
    struct quaternion* axis = malloc(sizeof(struct quaternion));
    axis->a = 0;
    axis->b = vec->x;
    axis->c = vec->y;
    axis->d = vec->z;

    struct quaternion* inv = quat_dup(quat);
    quat_inverse(inv);

    quat_mult(quat, axis);
    quat_mult(quat, inv);

    free(inv);
    free(axis);
}

int quat_equ(struct quaternion* one, struct quaternion* two) {
    return one->a == two->a && one->b == two->b && one->c == two->c && one->d == two->d;
}

struct quaternion* quat_dup(struct quaternion* quat) {
    struct quaternion* copy = malloc(sizeof(struct quaternion));
    memcpy(quat, copy, sizeof(struct quaternion));
    return copy;
}