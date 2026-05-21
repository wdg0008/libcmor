/*!
 * \brief Quaternion structs and related functions
 * \remarks Uses double for extra precision
 * \sa QuaternionF
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */

/*! Struch representing a quaternion as four separate real numbers*/
typedef struct QuatD {
    double a; //!< scalar component
    double b; //!< i component
    double c; //!< j component
    double d; //!< k component
} QuaternionD;

// constant convenience values defined in *.c file

extern const QuaternionD quatd_0; //!< convenience value = 0
extern const QuaternionD quatd_1; //!< convenience value = 1
extern const QuaternionD quatd_i; //!< convenience value = i
extern const QuaternionD quatd_j; //!< convenience value = j
extern const QuaternionD quatd_k; //!< convenience value = k

/*!
 * \brief Adds two quaternions and returns a new one
 * 
 * \param q1 First quaternion to add
 * \param q2 Second quaternion to add
 * \return QuaternionD Sum of two quaternions
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_add(const QuaternionD *q1, const QuaternionD *q2);

/*!
 * \brief Returns the difference of two quaternions as another
 * 
 * \param q1 The minuend (quaternion being subtracted from)
 * \param q2 The subtrahend (quaternion beingsubtracted)
 * \return QuaternionD Difference between two quaternions
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_sub(const QuaternionD *q1, const QuaternionD *q2);

/*!
 * \brief Computes the hamiltonian product of two quaternions
 * \warning LOTS of multiplications, very computationally intense
 * 
 * \param q1 Multiplier
 * \param q2 Multiplicand
 * \return QuaternionD Hamiltonian product of operands
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_mult(const QuaternionD *q1, const QuaternionD *q2);

/*!
 * \brief Calculates the conjugate of a quaternion
 * 
 * \param q QuaternionD to conjugate
 * \return QuaternionD Conjugated quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_conj(const QuaternionD *q);

/*!
 * \brief Calculates the inerse of a Quaternion
 * \sa quad_smul
 * \sa quad_normsq
 * 
 * \param q QuaternionD to invert
 * \return QuaternionD Inverted Quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_inv(const QuaternionD *q);

/*!
 * \brief Performs scalar multiplication on a quaternion
 * 
 * \param s Scalar value by which to multiply the quaternion
 * \param q QuaternionD to multuply
 * \return QuaternionD Product of the scalar and miltiplicand quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
QuaternionD quatd_smul(double s, const QuaternionD *q);

/*!
 * \brief Calculates the square of the norm
 * \remarks Useful for calculating inverses. Sum of element squares.
 * Find norm with sqrt()
 * 
 * \param q QuaternionD to normalize
 * \return double Square of the norm of the quaternion
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-21
 * \copyright Copyright (c) 2026
 */
double quatd_normsq(const QuaternionD *q);
