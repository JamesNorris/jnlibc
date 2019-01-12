#ifndef JN_QUAT_H
#define JN_QUAT_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

struct quaternion {
    double w;
    double x;
    double y;
    double z;
};
typedef struct quaternion quaternion;

extern void quat_add(struct quaternion* quat, struct quaternion* other);
extern void quat_sub(struct quaternion* quat, struct quaternion* other);
extern void quat_mult(struct quaternion* quat, struct quaternion* other);
extern void quat_div(struct quaternion* quat, struct quaternion* other);

extern double quat_mag(struct quaternion* quat);
extern struct quaternion* quat_norm(struct quaternion* quat);
extern struct quaternion* quat_conj(struct quaternion* quat);

extern int quat_equ(struct quaternion* q1, struct quaternion* q2);
extern struct quaternion* quat_dup(struct quaternion* quat);

#endif //JN_QUAT_H