/*!
 * \file array.c
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Provides function implementations for array manipulation.
 * \version 0.1
 * \date 2025-09-04
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#include "array.h"
#include "metamacros.h"
#include <stdbool.h>
#include <string.h>

/*!
 * \brief Defines functions to calculate array averages for various data types.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define GM_AVG_DEFINE(T) TAvg Array_TAvg_##T(const T* arr, size_t length) {\
    if (length == 0) {\
        return 0.0;\
    }\
    TAvg sum = 0.0;\
    for (size_t i = 0; i < length; ++i) {\
        sum += arr[i];\
    }\
    return sum / length;\
}

TYPE_ITERATOR(GM_AVG_DEFINE) // Define average functions

#undef GM_AVG_DEFINE

#define MEMSWAP(a, b, size) memswap(&(a), &(b), size)

#define MEMSWAP_ARR(a, b, T) memswap(a, b, sizeof(T))

/*!
 * \brief Swaps two memory regions of given size.
 * 
 * \param a Pointer to the first memory region.
 * \param b Pointer to the second memory region.
 * \param size The number of bytes to swap.
 * \warning The memory regions must be the same size and non-overlapping.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
void memswap(void* a, void* b, size_t size) {
    uint8_t temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

/*!
 * \brief Macro for generic swap function definitions.
 * \remarks Swaps two variables using a temporary variable.
 * Call it using reference operators, as in swap(&a, &b);
 *
 * \warning Make sure the pointers are valid and of the same type!
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define GM_SWAP_DEFINE(T) void swap_##T(T* a, T* b) { \
    T temp = *a; \
    *a = *b; \
    *b = temp; \
}

TYPE_ITERATOR(GM_SWAP_DEFINE) // Define swap functions

#undef GM_SWAP_DEFINE

/*!
 * \brief Macro for generic QuickSort function definitions.
 * \remarks Recusively sorts the array in place.
 * Calls the \ref partition function-like macro to partition the array.

 * \warning This function only validates order of indices and does not check for out-of-bounds access.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define QUICK_SORT_DEFINE(T) void QuickSort_##T(T data[], int start, int stop) { \
    if (start < stop) { \
        int partitionIndex = partition(data, start, stop); \
        QuickSort(data, start, partitionIndex - 1); \
        QuickSort(data, partitionIndex + 1, stop); \
    } \
    return; \
}

TYPE_ITERATOR(QUICK_SORT_DEFINE) // Define quicksort functions

#undef QUICK_SORT_DEFINE

/*!
 * \brief Macro for generic partition function definitions.
 * Chooses the middle element as a pivot to minimize worst-case performance on sorted data.
 * Uses the Hoare partition scheme. i is the LHS iterator, and j the is RHS iterator.
 * The do-whiles ensure that variables are always valid indices.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define PARTITION_DEFINE(T) int partition_##T(T data[], int leftend, int rightend) { \
    T pivot = data[(leftend+rightend)/2]; \
    int i = leftend - 1; \
    int j = rightend + 1; \
    while (true) { \
        do { \
            i++; \
        } while (data[i] < pivot); \
        do { \
            j--; \
        } while (data[j] > pivot); \
        if (i >= j) \
            return j; \
        swap(&data[i], &data[j]); \
    } \
}

    TYPE_ITERATOR(PARTITION_DEFINE) // Define partition functions

#undef PARTITION_DEFINE

/*!
 * \brief Macro for generic MergeSort function definitions.
 * \remarks Recusively sorts the array in place using a temporary array of equal size.
 * The temporary array must be allocated by the caller and is reused in recursive calls.
 * The \ref merge function-like macro is called to merge the two sorted halves.
 * The midpoint calculation relies on integer division flooring.
 *
 * \warning This function only validates order of indices and does not check for out-of-bounds access.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define MERGE_SORT_DEFINE(T) void MergeSort_##T(T A[], int left, int right, T temp[]) { \
    if (left < right) { \
        int mid = (left + right) / 2; \
        MergeSort(A, left, mid, temp); \
        MergeSort(A, mid + 1, right, temp); \
        merge(A, left, mid, mid + 1, right, temp); \
    } \
    return; \
}

    TYPE_ITERATOR(MERGE_SORT_DEFINE) // Define merge sort functions

#undef MERGE_SORT_DEFINE

/*!
 * \brief Merges two sorted subarrays into a single sorted array.
 * \remarks Unlike \ref MergeSort, this function is not recursive.
 * Data is copied into the temporary array and then back to the original array.
 * This function is called internally by \ref MergeSort and not meant to be called directly.
 *
 * \warning Out-of-bounds access is not checked, and temp must be the same size as A.
 *
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define MERGE_DEFINE(T) void merge_##T(T A[], int left, int leftend, int right, int rightend, T temp[]) { \
    int SaveStart = left; \
    int index = left; \
    while (left <= leftend && right <= rightend) { \
        if (A[left] < A[right]) { \
            temp[index++] = A[left++]; \
        } \
        else if (A[left] > A[right]) { \
            temp[index++] = A[right++]; \
        } \
        else { \
            temp[index++] = A[left++]; \
        } \
    } \
    while (left <= leftend) { \
        temp[index++] = A[left++]; \
    } \
    while (right <= rightend) { \
        temp[index++] = A[right++]; \
    } \
    for (int i = SaveStart; i <= rightend; i++) { \
        A[i] = temp[i]; \
    } \
}

    TYPE_ITERATOR(MERGE_DEFINE) // Define merge functions

#undef MERGE_DEFINE

#define CONVOLVE_DEFINE(T) \
void convolve_##T(const T x[], size_t x_len, \
                  const T h[], size_t h_len, \
                  T y[], size_t y_len) { \
    if (!x || !h || !y) return; \
    if (x_len == 0 || h_len == 0 || y_len == 0) return; \
    if (y_len < x_len + h_len - 1) return; \
    \
    memset(y, 0, y_len * sizeof(T)); \
    \
    for (size_t n = 0; n < x_len + h_len - 1; n++) { \
        size_t m_min = (n >= h_len - 1) ? (n - (h_len - 1)) : 0; \
        size_t m_max = (n < x_len - 1) ? n : (x_len - 1); \
        for (size_t m = m_min; m <= m_max; m++) { \
            y[n] += x[m] * h[n - m]; \
        } \
    } \
}

    TYPE_ITERATOR(CONVOLVE_DEFINE) // Define convolution functions

#undef CONVOLVE_DEFINE