#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Swaps two variables in place using XOR bitwise operation. */
#define SWAP(a,b) (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)))

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

    GM_AVG_DECLARE(int8_t)
    GM_AVG_DECLARE(int16_t)
    GM_AVG_DECLARE(int32_t)
    GM_AVG_DECLARE(int64_t)
    GM_AVG_DECLARE(uint8_t)
    GM_AVG_DECLARE(uint16_t)
    GM_AVG_DECLARE(uint32_t)
    GM_AVG_DECLARE(uint64_t)
    GM_AVG_DECLARE(float)
    GM_AVG_DECLARE(double)

#undef GM_AVG_DECLARE

/*!
 * \brief Shorthand for generic average function selection based on array type.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define ARR_AVG_LOOKUP(T) T*: Array_TAvg_##T

    /*!
     * \brief Generic macro to compute the average of an array.
     * 
     * \version 0.1
     * \author William (116991920+wdg0008@users.noreply.github.com)
     * \date 2025-08-31
     * \copyright Copyright (c) 2025
     */
    #define Array_TAvg(arr, length) (_Generic((arr), \
        ARR_AVG_LOOKUP(int8_t), \
        ARR_AVG_LOOKUP(int16_t), \
        ARR_AVG_LOOKUP(int32_t), \
        ARR_AVG_LOOKUP(int64_t), \
        ARR_AVG_LOOKUP(uint8_t), \
        ARR_AVG_LOOKUP(uint16_t), \
        ARR_AVG_LOOKUP(uint32_t), \
        ARR_AVG_LOOKUP(uint64_t), \
        ARR_AVG_LOOKUP(float), \
        ARR_AVG_LOOKUP(double) \
    )(arr, length))

#undef ARR_AVG_LOOKUP

#define GM_SWAP_DECLARE(T) void swap_##T(T* a, T* b);

    GM_SWAP_DECLARE(int8_t)
    GM_SWAP_DECLARE(int16_t)
    GM_SWAP_DECLARE(int32_t)
    GM_SWAP_DECLARE(int64_t)
    GM_SWAP_DECLARE(uint8_t)
    GM_SWAP_DECLARE(uint16_t)
    GM_SWAP_DECLARE(uint32_t)
    GM_SWAP_DECLARE(uint64_t)
    GM_SWAP_DECLARE(float)
    GM_SWAP_DECLARE(double)

#undef GM_SWAP_DECLARE

#define swap(a, b) _Generic((a), \
    int8_t *: swap_int8_t, \
    int16_t *: swap_int16_t, \
    int32_t *: swap_int32_t, \
    int64_t *: swap_int64_t, \
    uint8_t *: swap_uint8_t, \
    uint16_t *: swap_uint16_t, \
    uint32_t *: swap_uint32_t, \
    uint64_t *: swap_uint64_t, \
    float *: swap_float, \
    double *: swap_double \
)(a, b)


typedef uint8_t TSort;

void QuickSort(TSort data[], int start, int stop);

int partition(TSort data[], int leftend, int rightend);


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
