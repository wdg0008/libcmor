#include "array.h"
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

    GM_AVG_DEFINE(int8_t)
    GM_AVG_DEFINE(int16_t)
    GM_AVG_DEFINE(int32_t)
    GM_AVG_DEFINE(int64_t)
    GM_AVG_DEFINE(uint8_t)
    GM_AVG_DEFINE(uint16_t)
    GM_AVG_DEFINE(uint32_t)
    GM_AVG_DEFINE(uint64_t)
    GM_AVG_DEFINE(float)
    GM_AVG_DEFINE(double)

#undef GM_AVG_DEFINE

#define MEMSWAP(a, b, size) memswap(&(a), &(b), size)

#define MEMSWAP_ARR(a, b, T) memswap(a, b, sizeof(T))

void memswap(void* a, void* b, size_t size) {
    uint8_t temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

#define GM_SWAP_DEFINE(T) void swap_##T(T* a, T* b) { \
    T temp = *a; \
    *a = *b; \
    *b = temp; \
}
    GM_SWAP_DEFINE(int8_t)
    GM_SWAP_DEFINE(int16_t)
    GM_SWAP_DEFINE(int32_t)
    GM_SWAP_DEFINE(int64_t)
    GM_SWAP_DEFINE(uint8_t)
    GM_SWAP_DEFINE(uint16_t)
    GM_SWAP_DEFINE(uint32_t)
    GM_SWAP_DEFINE(uint64_t)
    GM_SWAP_DEFINE(float)
    GM_SWAP_DEFINE(double) 

#undef GM_SWAP_DEFINE

void QuickSort(TSort data[], int start, int stop) { // the wrapper function for quicksort
    if (start < stop) { // the call is valid because there are elements to sort
        int partitionIndex = partition(data, start, stop); // find the partition
        QuickSort(data, start, partitionIndex - 1);
        QuickSort(data, partitionIndex + 1, stop);
    }
    return; // skips to here on a bad call, arrives here on a good one
}

int partition(TSort data[], int leftend, int rightend) { // the partitioning does ALL the work
    TSort pivot = data[(leftend+rightend)/2]; // the pivot point to start the chaos
    // the pivot is selected at the middle in case it is already sorted
    int i = leftend - 1; // left-hand iteraror variable
    int j = rightend + 1; // right-hand iterator variable
    while (true) { // looks weird, but lets the return be more elegant
        do { // do-whiles ensure that variables are always valid indices
            i++; // moves i from Left to Right (LTR)
        } while (data[i] < pivot);
        do {
            j--; // moves j from RIght to Left (RTL)
        } while (data[j] > pivot);
        if (i >= j) // we got to the middle
            return j; // all done here
        swap(&data[i], &data[j]); // swaps like the book, but doesn't have to undo
    }
}