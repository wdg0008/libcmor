/*!
 * \file array.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Provides array manipulation utilities (averaging, sorting, swapping, etc.)
 * \remarks Makes extensive use of C11 _Generic for type-generic programming.
 * Also uses \ref metamacros.h for iterating thhrough all of those types.
 *
 * \version 0.1
 * \date 2025-09-04
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdint.h>
#include "metamacros.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Swaps two variables in place using XOR bitwise operation. */
#define SWAP_INPLACE(a,b) (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)))

/*! \brief The type returned by the average functions. */
typedef double TAvg;

/*!
 * \brief Shorthand for declaring average functions for different types.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define GM_AVG_DECLARE(T) TAvg Array_TAvg_##T(const T* arr, size_t length);

    TYPE_ITERATOR(GM_AVG_DECLARE) // Declare average functions

#undef GM_AVG_DECLARE

/*!
 * \brief Generic macro to compute the average of an array.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define Array_TAvg(arr, length) (_Generic((arr), \
    TYPE_PTR_TABLE(Array_TAvg) \
)(arr, length))

#define GM_SWAP_DECLARE(T) void swap_##T(T* a, T* b);

    TYPE_ITERATOR(GM_SWAP_DECLARE) // Declare swap functions

#undef GM_SWAP_DECLARE

/*!
 * \brief Generic macro to swap two variables of the same type.
 * \warning Do not call this on two variables of different types!
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define swap(a, b) _Generic((a), \
    TYPE_PTR_TABLE(swap) \
)(a, b)

#define QUICK_SORT_DECLARE(T) void QuickSort_##T(T data[], int start, int stop);

    TYPE_ITERATOR(QUICK_SORT_DECLARE) // Declare quicksort functions

#undef QUICK_SORT_DECLARE

/*!
 * \brief Generic macro to perform quicksort on an array.
 * \remark This sorts the array in place using recursvie function calls.
 * \warning Be careful with array bounds! Total length is irrelevant.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define QuickSort(data, start, stop) _Generic((data), \
    TYPE_PTR_TABLE(QuickSort) \
)(data, start, stop)

#define PARTITION_DECLARE(T) int partition_##T(T data[], int leftend, int rightend);

    TYPE_ITERATOR(PARTITION_DECLARE) // Declare partition functions

#undef PARTITION_DECLARE

/*!
 * \brief Generic macro to partition an array for quicksort.
 * \remark This is called internally by QuickSort; you should not need to call it directly.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define partition(data, leftend, rightend) _Generic((data), \
    TYPE_PTR_TABLE(partition) \
)(data, leftend, rightend)

#define MERGE_SORT_DECLARE(T) void MergeSort_##T(T A[], int left, int right, T temp[]);

    TYPE_ITERATOR(MERGE_SORT_DECLARE) // Declare merge sort functions)

#undef MERGE_SORT_DECLARE

/*!
 * \brief Generic macro to perform merge sort on an array.
 * \remark This sorts the array in place using recursvie function calls.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define MergeSort(A, left, right, temp) _Generic((A), \
    TYPE_PTR_TABLE(MergeSort) \
)(A, left, right, temp)

#define MERGE_DECLARE(T) void merge_##T(T A[], int left, int leftend, int right, int rightend, T temp[]);

    TYPE_ITERATOR(MERGE_DECLARE) // Declare merge functions

#undef MERGE_DECLARE

/*!
 * \brief Generic macro to merge two sorted subarrays.
 * \remark Called internally by MergeSort.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define merge(A, left, leftend, right, rightend, temp) _Generic((A), \
    TYPE_PTR_TABLE(merge) \
)(A, left, leftend, right, rightend, temp)

#define CONVOLVE_DECLARE(T) \
void convolve_##T(const T x[], size_t x_len, \
                  const T h[], size_t h_len, \
                  T y[], size_t y_len);

    TYPE_ITERATOR(CONVOLVE_DECLARE) // Declare convolution functions

#undef CONVOLVE_DECLARE

/*!
 * \brief Macro for generic convolution function definitions.
 * \remarks Computes the discrete linear convolution of two sequences.
 * This implementation uses the direct summation method in O(N*M) time complexity.
 * \warning The output array y must be preallocated and of sufficient size (at least x_len + h_len - 1).
 * For invalid inputs (NULL pointers or zero lengths), the function does nothing. 
 *
 * \param x Input array (signal).
 * \param x_len Number of elements in input array x.
 * \param h Impulse response array (kernel).
 * \param h_len Number of elements in impulse response array h.
 * \param y Output array to store the convolution result.
 * \param y_len Number of elements in output array y.
 *
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-13
 * \copyright Copyright (c) 2025
 */
#define convolve(x, x_len, h, h_len, y, y_len) _Generic((x), \
    TYPE_PTR_TABLE(convolve) \
)(x, x_len, h, h_len, y, y_len)

#ifdef __cplusplus
}
#endif

#endif // ARRAY_H
