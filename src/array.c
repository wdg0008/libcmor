#include "array.h"

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