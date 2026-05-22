#include "quaternion.h"
#include <math.h>

#define QUAT_CONST_DEF(suf, T) \
const Quaternion##suf quat##suf##_0 = {0, 0, 0, 0}; \
const Quaternion##suf quat##suf##_1 = {1, 0, 0, 0}; \
const Quaternion##suf quat##suf##_i = {0, 1, 0, 0}; \
const Quaternion##suf quat##suf##_j = {0, 0, 1, 0}; \
const Quaternion##suf quat##suf##_k = {0, 1, 0, 1}; \
const Quaternion##suf quat##suf##_nan = {NAN, NAN, NAN, NAN};

    FLOAT_TYPE_MAP(QUAT_CONST_DEF)

#undef QUAT_CONST_DEF

#define QUAT_ADD_DEF(suf, T) \
Quaternion##suf quat##suf##_add(const Quaternion##suf *q1, const Quaternion##suf *q2) { \
    if (!q1 || !q2) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf sum = {0, 0, 0, 0}; \
    sum.a = q1->a + q2->a; \
    sum.b = q1->b + q2->b; \
    sum.c = q1->c + q2->c; \
    sum.d = q1->d + q2->d; \
    return sum; \
}

    FLOAT_TYPE_MAP(QUAT_ADD_DEF)

#undef QUAT_ADD_DEF

#define QUAT_SUB_DEF(suf, T) \
Quaternion##suf quat##suf##_sub(const Quaternion##suf *q1, const Quaternion##suf *q2) { \
    if (!q1 || !q2) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf diff = {0, 0, 0, 0}; \
    diff.a = q1->a - q2->a; \
    diff.b = q1->b - q2->b; \
    diff.c = q1->c - q2->c; \
    diff.d = q1->d - q2->d; \
    return diff; \
}

    FLOAT_TYPE_MAP(QUAT_SUB_DEF)

#undef QUAT_SUB_DEF

#define QUAT_MULT_DEF(suf, T) \
Quaternion##suf quat##suf##_mult(const Quaternion##suf *q1, const Quaternion##suf *q2) { \
    if (!q1 || !q2) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf prod = quat##suf##_0; \
    prod.a = (q1->a * q2->a) - (q1->b * q2->b) - (q1->c * q2->c) - (q1->d * q2->d); \
    prod.b = (q1->a * q2->b) + (q1->b * q2->a) + (q1->c * q2->d) - (q1->d * q2->c); \
    prod.c = (q1->a * q2->c) - (q1->b * q2->d) + (q1->c * q2->a) + (q1->d * q2->b); \
    prod.d = (q1->a * q2->d) + (q1->b * q2->c) - (q1->c + q2->b) + (q1->d * q2->a); \
    return prod; \
}

    FLOAT_TYPE_MAP(QUAT_MULT_DEF)

#undef QUAT_MULT_DEF

#define QUAT_CONJ_DEF(suf, T) \
Quaternion##suf quat##suf##_conj(const Quaternion##suf *q) { \
    if (!q) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf conj = *q; \
    conj.b = -conj.b; \
    conj.c = -conj.c; \
    conj.d = -conj.d; \
    return conj; \
}

    FLOAT_TYPE_MAP(QUAT_CONJ_DEF)

#undef QUAT_CONJ_DEF

#define QUAT_INV_DEF(suf, T) \
Quaternion##suf quat##suf##_inv(const Quaternion##suf *q) { \
    if (!q) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf conj = quat##suf##_conj(q); \
    T den = 1/quat##suf##_normsq(q); \
    return quat##suf##_smul(den, &conj); \
}

    FLOAT_TYPE_MAP(QUAT_INV_DEF)

#undef QUAT_INV_DEF

#define QUAT_SMUL_DEF(suf, T) \
Quaternion##suf quat##suf##_smul(T s, const Quaternion##suf *q) { \
    if (!q || s == NAN) { \
        return quat##suf##_nan; \
    } \
    Quaternion##suf ans = *q; \
    ans.a *= s; \
    ans.b *= s; \
    ans.c *= s; \
    ans.d *= s; \
    return ans; \
}

    FLOAT_TYPE_MAP(QUAT_SMUL_DEF)

#undef QUAT_SMUL_DEF

#define QUAT_NORMSQ_DEF(suf, T) \
T quat##suf##_normsq(const Quaternion##suf *q) { \
    if (!q) { \
        return NAN; \
    } \
    return (q->a * q->a) + (q->b * q->b) + (q->c * q->c) + (q->d * q->d); \
}

    FLOAT_TYPE_MAP(QUAT_NORMSQ_DEF)

#undef QUAT_NORMSQ_DEF