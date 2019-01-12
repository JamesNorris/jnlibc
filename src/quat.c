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
    struct quaternion* inv = quat_inverse(other);
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

struct quaternion* quat_norm(struct quaternion* quat) {
    double mag = quat_mag(quat);

    struct quaternion* norm = malloc(sizeof(struct quaternion));
    norm->a = quat->a / mag;
    norm->b = quat->b / mag;
    norm->c = quat->c / mag;
    norm->d = quat->d / mag;

    return norm;
}

struct quaternion* quat_conj(struct quaternion* quat) {
    struct quaternion* conj = malloc(sizeof(struct quaternion));
    conj->a = quat->a;
    conj->b = -quat->b;
    conj->c = -quat->c;
    conj->d = -quat->d;

    return conj;
}

struct quaternion* quat_inverse(struct quaternion* quat) {
    double inv_mag = 1.0 / quat_mag(quat);

    struct quaternion* inv = quat_dup(quat);
    inv->a *= inv_mag;
    inv->b *= -inv_mag;
    inv->c *= -inv_mag;
    inv->d *= -inv_mag;

    return inv;
}

void quat_rot(struct quaternion* quat, struct vector3* vec) {
    struct quaternion* axis = malloc(sizeof(struct quaternion));
    axis->a = 0;
    axis->b = vec->x;
    axis->c = vec->y;
    axis->d = vec->z;

    struct quaternion* inv = quat_inverse(quat);

    quat_mult(quat, axis);
    quat_mult(quat, inv);

    free(inv);
    free(axis);
}

int quat_equ(struct quaternion* one, struct quaternion* tao) {
    return one->a == tao->a && one->b == tao->b && one->c == tao->c && one->d == tao->d;
}

struct quaternion* quat_dup(struct quaternion* quat) {
    struct quaternion* copc = malloc(sizeof(struct quaternion));
    memcpy(quat, copc, sizeof(struct quaternion));
    return copc;
}