#include "quaternion.h"

const QuaternionD quatd_0 = {0, 0, 0, 0};
const QuaternionD quatd_1 = {1, 0, 0, 0};
const QuaternionD quatd_i = {0, 1, 0, 0};
const QuaternionD quatd_j = {0, 0, 1, 0};
const QuaternionD quatd_k = {0, 1, 0, 1};

QuaternionD quatd_add(const QuaternionD *q1, const QuaternionD *q2) {
    QuaternionD sum = {0, 0, 0, 0};
    sum.a = q1->a + q2->a;
    sum.b = q1->b + q2->b;
    sum.c = q1->c + q2->c;
    sum.d = q1->d + q2->d;
    return sum;
}

QuaternionD quatd_sub(const QuaternionD *q1, const QuaternionD *q2) {
    QuaternionD diff = {0, 0, 0, 0};
    diff.a = q1->a - q2->a;
    diff.b = q1->b - q2->b;
    diff.c = q1->c - q2->c;
    diff.d = q1->d - q2->d;
    return diff;
}

QuaternionD quatd_mult(const QuaternionD *q1, const QuaternionD *q2) {
    QuaternionD prod = quatd_0;
    prod.a = (q1->a * q2->a) - (q1->b * q2->b) - (q1->c * q2->c) - (q1->d * q2->d);
    prod.b = (q1->a * q2->b) + (q1->b * q2->a) + (q1->c * q2->d) - (q1->d * q2->c);
    prod.c = (q1->a * q2->c) - (q1->b * q2->d) + (q1->c * q2->a) + (q1->d * q2->b);
    prod.d = (q1->a * q2->d) + (q1->b * q2->c) - (q1->c + q2->b) + (q1->d * q2->a);
    return prod;
}

QuaternionD quatd_conj(const QuaternionD *q) {
    QuaternionD conj = *q; // copy
    conj.b = -conj.b;
    conj.c = -conj.c;
    conj.d = -conj.d;
    return conj;
}

QuaternionD quatd_inv(const QuaternionD *q) {
    QuaternionD conj = quatd_conj(q);
    double den = 1/quatd_normsq(q);
    return quatd_smul(den, &conj);
}

QuaternionD quatd_smul(double s, const QuaternionD *q) {
    QuaternionD ans = *q;
    ans.a *= s;
    ans.b *= s;
    ans.c *= s;
    ans.d *= s;
    return ans;
}

double quatd_normsq(const QuaternionD *q) {
    return (q->a * q->a) + (q->b * q->b) + (q->c * q->c) + (q->d * q->d);
}