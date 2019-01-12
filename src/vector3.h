#ifndef JN_VECTOR3_H
#define JN_VECTOR3_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

struct vector3 {
    double x;
    double y;
    double z;
};
typedef struct vector3 vector3;

extern void vec3_add(struct vector3* vec, struct vector3* other);
extern void vec3_sub(struct vector3* vec, struct vector3* other);
extern void vec3_mult(struct vector3* vec, struct vector3* other);
extern void vec3_div(struct vector3* vec, struct vector3* other);

extern double vec3_mag(struct vector3* vec);
extern void vec3_norm(struct vector3* vec);

extern int vec3_equ(struct vector3* one, struct vector3* two);
extern struct vector3* vec3_dup(struct vector3* vec);

#endif //JN_VECTOR3_H