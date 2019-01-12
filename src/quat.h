#ifndef JN_QUAT_H
#define JN_QUAT_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "vector3.h"

struct quaternion {
    double a;
    double b;
    double c;
    double d;
};
typedef struct quaternion quaternion;

extern void quat_add(struct quaternion* quat, struct quaternion* other);
extern void quat_sub(struct quaternion* quat, struct quaternion* other);
extern void quat_mult(struct quaternion* quat, struct quaternion* other); // Hamilton product (pq)
extern void quat_div(struct quaternion* quat, struct quaternion* other); // inverse Hamilton product (pq^-1)
extern void quat_scale(struct quaternion* quat, struct quaternion* other); // typical member multiplication

extern double quat_mag(struct quaternion* quat);
extern struct quaternion* quat_norm(struct quaternion* quat);
extern struct quaternion* quat_conj(struct quaternion* quat);

extern struct quaternion* quat_inverse(struct quaternion* quat);
extern void quat_rot(struct quaternion* quat, struct vector3* vec);

extern int quat_equ(struct quaternion* one, struct quaternion* two);
extern struct quaternion* quat_dup(struct quaternion* quat);

#endif //JN_QUAT_H