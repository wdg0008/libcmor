/*!
 * \file quaternion.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Quaternion structs and related function declarations.
 * \remarks Implemented with template and generic macros for all float types
 * \version 0.1
 * \date 2026-05-21
 * 
 * \copyright Copyright (c) 2026
 * 
 */

#ifndef QUATERNION_H
#define QUATERNION_H

#include "metamacros.h" // it's back...

#ifdef __cplusplus
extern "C" {
#endif

/*! Declare quaternion types */
#define QUAT_DECLARE(suf, T)                         \
/*! Struct representing quaternion as four reals */ \
typedef struct {                                     \
    T a; /*!< scalar component */                    \
    T b; /*!< i component */                         \
    T c; /*!< j component */                         \
    T d; /*!< k component */                         \
} Quaternion##suf;

    FLOAT_TYPE_MAP(QUAT_DECLARE) // declare Quaternion struct types

#undef QUAT_DECLARE
// constant convenience values defined in *.c file

/*! Defines macro to declare helper convenience values */
#define QUAT_CONST_DECLARE(suf, T)\
extern const Quaternion##suf quat##suf##_0; /*!< convenience value = 0 */ \
extern const Quaternion##suf quat##suf##_1; /*!< convenience value = 1 */ \
extern const Quaternion##suf quat##suf##_i; /*!< convenience value = i */ \
extern const Quaternion##suf quat##suf##_j; /*!< convenience value = j */ \
extern const Quaternion##suf quat##suf##_k; /*!< convenience value = k */ \
extern const Quaternion##suf quat##suf##_nan; /*<! convenience value (all NaN)*/

    FLOAT_TYPE_MAP(QUAT_CONST_DECLARE) // declare Quaternion helper values

#undef QUAT_CONST_DECLARE

/*! Passed as a parameter to expand for all supported types and their suffixes */
#define QUAT_FUNC_DECLARE(suf, T)\
/*! Add two quaternions */ \
Quaternion##suf quat##suf##_add(const Quaternion##suf *q1, const Quaternion##suf *q2); \
/*! Subtract two quaternion */ \
Quaternion##suf quat##suf##_sub(const Quaternion##suf *q1, const Quaternion##suf *q2); \
/*! Multiply left and right quaternions (Hamiltonian Product) */ \
Quaternion##suf quat##suf##_mult(const Quaternion##suf *q1, const Quaternion##suf *q2); \
/*! Conjugate a quaternion */ \
Quaternion##suf quat##suf##_conj(const Quaternion##suf *q); \
/*! Invert a quaternion */ \
Quaternion##suf quat##suf##_inv(const Quaternion##suf *q); \
/*! Multiply a quaternion by a scalar */ \
Quaternion##suf quat##suf##_smul(T s, const Quaternion##suf *q); \
/*! Find the square of a quaternion's norm */ \
T quat##suf##_normsq(const Quaternion##suf *q); \

    FLOAT_TYPE_MAP(QUAT_FUNC_DECLARE) // declare function for all the types

#undef QUAT_FUNC_DECLARE

#define QUAT_GEN_ADD(suf, T) Quaternion##suf *: quat##suf##_add

/*!
 * \brief Adds two quaternions and returns a new one
 * 
 * \param q1 First quaternion to add
 * \param q2 Second quaternion to add
 * \return Quaternion Sum of two quaternions
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_add(q1, q2) \
    _Generic((q1), \
        FLOAT_TYPE_MAP(QUAT_GEN_ADD) \
    )(q1, q2)

#undef QUAT_GEN_ADD
#define QUAT_GEN_SUB(suf, T) Quaternion##suf *: quat##suf##_sub

/*!
 * \brief Returns the difference of two quaternions as another
 * 
 * \param q1 The minuend (quaternion being subtracted from)
 * \param q2 The subtrahend (quaternion beingsubtracted)
 * \return Quaternion Difference between two quaternions
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_sub(q1, q2) \
    _Generic((q1), \
        FLOAT_TYPE_MAP(QUAT_GEN_SUB) \
    )(q1, q2)

#undef QUAT_GEN_SUB
#define QUAT_GEN_MULT(suf, T) Quaternion##suf *: quat##suf##_mult

/*!
 * \brief Computes the hamiltonian product of two quaternions
 * \warning LOTS of multiplications, very computationally intense
 * 
 * \param q1 Multiplier
 * \param q2 Multiplicand
 * \return Quaternion Hamiltonian product of operands
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_mult(q1, q2) \
    _Generic((q1), \
        FLOAT_TYPE_MAP(QUAT_GEN_MULT) \
    )(q1, q2)

#undef QUAT_GEN_MULT
#define QUAT_GEN_CONJ(suf, T) Quaternion##suf *: quat##suf##_conj

/*!
 * \brief Calculates the conjugate of a quaternion
 * 
 * \param q Quaternion to conjugate
 * \return Quaternion Conjugated quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_conj(q) \
    __Generic((q), \
        Quaternionf*: quatf_conj, \
        Quaterniond*: quatd_conj, \
        Quaternionld*: quatld_conj \
    )(q)

#undef QUAT_GEN_CONJ
#define QUAT_GEN_INV(suf, T) Quaternion##suf *: quat##suf##_inv

/*!
 * \brief Calculates the inverse of a Quaternion
 * \sa quad_smul
 * \sa quad_normsq
 * 
 * \param q Quaternion to invert
 * \return Quaternion Inverted Quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_inv(q) \
    __Generic((q), \
        FLOAT_TYPE_MAP(QUAT_GEN_INV) \
    )(q)

#undef QUAT_GEN_INV
#define QUAT_GEN_SMUL(suf, T) Quaternion##suf *: quat##suf##_smul

/*!
 * \brief Performs scalar multiplication on a quaternion
 * 
 * \param s Scalar value by which to multiply the quaternion
 * \param q Quaternion to multuply
 * \return Quaternion Product of the scalar and miltiplicand quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_smul(q) \
    __Generic((q), \
        FLOAT_TYPE_MAP(QUAT_GEN_SMUL) \
    )(q)

#undef QUAT_GEN_SMUL
#define QUAT_GEN_NORMSQ(suf, T) Quaternion##suf *: quat##suf##_normsq

/*!
 * \brief Calculates the square of the norm
 * \remarks Useful for calculating inverses. Sum of element squares.
 * Find norm with sqrt()
 * 
 * \param q Quaternion to normalize
 * \return double Square of the norm of the quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
#define quat_normsq(q) \
    __Generic((q), \
        FLOAT_TYPE_MAP(QUAT_GEN_NORMSQ) \
    )(q)

#undef QUAT_GEN_NORMSQ

#ifdef __cplusplus
}
#endif

#endif // QUATERNION_H