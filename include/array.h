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

/*******************************************************************
TODO: Convert the following to regular C functions.


void QuickSort(std::string data[], int start, int stop) { // the wrapper function for quicksort
    if (start < stop) { // the call is valid because there are elements to sort
        int partitionIndex = partition(data, start, stop); // find the partition
        QuickSort(data, start, partitionIndex - 1);
        QuickSort(data, partitionIndex + 1, stop);
        // TestDump(data, stop - start, 5); // TODO: REMOVE BEFORE FLIGHT!!!!!
    }
    return; // skips to here on a bad call, arrives here on a good one
}

int partition(std::string words[], int leftend, int rightend) { // the partitioning does ALL the work
    std::string pivot = words[(leftend+rightend)/2]; // the pivot point to start the chaos
    // the pivot is selected at the middle in case it is already sorted
    pivot = LowerString(pivot); // comparisons should all be based on lowercase strings
    int i = leftend - 1; // left-hand iteraror variable
    int j = rightend + 1; // right-hand iterator variable
    while (true) { // looks weird, but lets the return be more elegant
        do { // do-whiles ensure that variables are always valid indices
            i++; // moves i from Left to Right (LTR)
        } while (LowerString(words[i]).compare(pivot) < 0);
        do {
            j--; // moves j from RIght to Left (RTL)
        } while (LowerString(words[j]).compare(pivot) > 0);
        if (i >= j) // we got to the middle
            return j; // all done here
        std::swap(words[i], words[j]); // swaps like the book, but doesn't have to undo
    }
}

void MergeSort(std::string A[], int left, int right, std::string temp[]) {
    if (left < right) { // this means there is data to sort (left < right)
        int mid = (left + right) / 2; // C++ always does the floor of int div
        MergeSort(A, left, mid, temp);
        MergeSort(A, mid + 1, right, temp);
        merge(A, left, mid, mid + 1, right, temp);
        // TestDump(A, left - right, 5); // TODO: REMOVE BEFORE FLIGHT!!!!!
    }
    return; // explicit calls to return make me happier (not much, but it helps)
}

void merge(std::string A[], int left, int leftend, int right, int rightend, std::string temp[]) {
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
