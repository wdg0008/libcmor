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
 * \remark This soorts the array in place using recirsvie function calls.
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


/*******************************************************************
TODO: Convert the following to regular C functions.
void MergeSort(TSort A[], int left, int right, TSort temp[]) {
    if (left < right) { // this means there is data to sort (left < right)
        int mid = (left + right) / 2; // C++ always does the floor of int div
        MergeSort(A, left, mid, temp);
        MergeSort(A, mid + 1, right, temp);
        merge(A, left, mid, mid + 1, right, temp);
        // TestDump(A, left - right, 5); // TODO: REMOVE BEFORE FLIGHT!!!!!
    }
    return; // explicit calls to return make me happier (not much, but it helps)
}

void merge(TSort A[], int left, int leftend, int right, int rightend, TSort temp[]) {
    // go from 0 to n/2 and (n/2)+1 to n-1
    // each half is already sorted, we are now combining them
    int SaveStart = left;
    int index = left;
    while (left <= leftend && right <= rightend) { // is this correct? Might should be >= leftend
        // all comparisons are based on lowercase version of ASCII strings
        // the LowerString.compare part kind of hurt to write, but the lecture helped a lot.
        if (LowerString(A[left]).compare(LowerString(A[right])) < 0) { // left value goes first
            temp[index++] = A[left++]; // copy the value to temp
        }
        else if (LowerString(A[left]).compare(LowerString(A[right])) > 0) { // right value goes first
            temp[index++] = A[right++]; // copy value to temp
        }
        else { // they are equal
            temp[index++] = A[left++]; // choose the left half arbitrarily
        }
    } // we have reached the end of either the left or right half
    while (left <= leftend) { // copy remaining left half data
        temp[index++] = A[left++]; // copy to each index and then increment
    }
    while (right <= rightend) { // copy remaining right half data
        temp[index++] = A[right++];
    } // everything is now in temp and in the correct position
    for (int i = SaveStart; i <= rightend; i++) {
        A[i] = temp[i]; // copies everything in temp back to A
    }
}

 *******************************************************************/
#ifdef __cplusplus
}
#endif

#endif // ARRAY_H
