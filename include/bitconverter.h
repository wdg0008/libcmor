#ifndef BITCONVERTER_H
#define BITCONVERTER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "metamacros.h"

#ifdef __cplusplus
extern "C" {
#endif


extern bool g_is_little_endian; //!< Set by BitConverter_Init()

/*!
 * \brief Initializes the BitCovnerter library, detecting endianness.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
void BitConverter_Init();

/*!
 * \brief Returns the base-2 logarithm of an integer value, rounded down.
 * 
 * \param value 
 * \return uint8_t 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
uint8_t BitConverter_Log2Int(uint64_t value);

/*! \brief Datects whether an integer is a power of 2 */
inline bool BitConverter_IsPow2(uint64_t value) {
    return value && !(value & (value - 1));
}

/*!
 * \brief Constructs a double from its uint64_t representation.
 * 
 * \param value The raw 64-bit integer interpretation of the double.
 * \return double The resulting double value.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
double BitConverter_doubleFromuint64_t(uint64_t value);

/*!
 * \brief Constructs a float from its uint32_t representation.
 * 
 * \param value The raw 32-bit integer interpretation of the float.
 * \return float The resulting float value.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
float BitConverter_floatFromuint32_t(uint32_t value);

/*!
 * \brief Extracts the uint64_t representation of a double.
 * 
 * \param value The double to convert.
 * \return uint64_t The raw 64-bit integer interpretation of the double.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
uint64_t BitConverter_uint64_tFromdouble(double value);

/*!
 * \brief Extracts the uint32_t representation of a float.
 * 
 * \param value The float to convert.
 * \return uint32_t The raw 32-bit integer interpretation of the float.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
uint32_t BitConverter_uint32_tFromfloat(float value);

/*!
 * \brief Generic macro to extract bytes from various data types.
 * \param x The value to convert to bytes.
 * \param byteArr The byte array to fill with the byte representation of x.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define BitConverter_GetBytes(x, byteArr) _Generic((x), \
    TYPE_TABLE(BitConverter_GetBytes) \
)(x, byteArr)

void BitConverter_GetBytes_int16_t(int16_t value, uint8_t bytes[2]);
void BitConverter_GetBytes_int32_t(int32_t value, uint8_t bytes[4]);
void BitConverter_GetBytes_int64_t(int64_t value, uint8_t bytes[8]);
void BitConverter_GetBytes_uint16_t(uint16_t value, uint8_t bytes[2]);
void BitConverter_GetBytes_uint32_t(uint32_t value, uint8_t bytes[4]);
void BitConverter_GetBytes_uint64_t(uint64_t value, uint8_t bytes[8]);
void BitConverter_GetBytes_float(float value, uint8_t bytes[4]);
void BitConverter_GetBytes_double(double value, uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
int16_t BitConverter_To_int16_t(const uint8_t bytes[2]);

/*! \brief Constructs a value from its byte representation. */
int32_t BitConverter_To_int32_t(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
int64_t BitConverter_To_int64_t(const uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
uint16_t BitConverter_To_uint16_t(const uint8_t bytes[2]);

/*! \brief Constructs a value from its byte representation. */
uint32_t BitConverter_To_uint32_t(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
uint64_t BitConverter_To_uint64_t(const uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
float BitConverter_To_float(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
double BitConverter_To_double(const uint8_t bytes[8]);

/**
 * \brief Swaps the byte order of the given byte array in-place.
 * \param bytes Pointer to the byte array.
 * \param length Length of the byte array.
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 */
void BitConverter_Reverse_Bytes(uint8_t* bytes, size_t length);

/*!
 * \brief Reverses the byte order of various data types.
 * \param x The value to reverse.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define BitConverter_Reverse(x) _Generic((x), \
    TYPE_TABLE(BitConverter_Reverse) \
)(x)

int16_t BitConverter_Reverse_int16_t(int16_t value);
int32_t BitConverter_Reverse_int32_t(int32_t value);
int64_t BitConverter_Reverse_int64_t(int64_t value);
uint16_t BitConverter_Reverse_uint16_t(uint16_t value);
uint32_t BitConverter_Reverse_uint32_t(uint32_t value);
uint64_t BitConverter_Reverse_uint64_t(uint64_t value);
float BitConverter_Reverse_float(float value);
double BitConverter_Reverse_double(double value);

/*!
 * \brief Concatenates two smaller values into a larger one.
 * \param x The high part or upper half.
 * \param y The low part or lower half.
 * \warning This macro will misbehave if x and y are of different types!
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define BitConverter_Join(x, y) _Generic((x), \
    TYPE_TABLE(BitConverter_Join) \
)(x, y)

int16_t BitConverter_Join_int16_t(int8_t high, int8_t low);
int32_t BitConverter_Join_int32_t(int16_t high, int16_t low);
int64_t BitConverter_Join_int64_t(int32_t high, int32_t low);
uint16_t BitConverter_Join_uint16_t(uint8_t high, uint8_t low);
uint32_t BitConverter_Join_uint32_t(uint16_t high, uint16_t low);
uint64_t BitConverter_Join_uint64_t(uint32_t high, uint32_t low);
double BitConverter_Join_double(float high, float low);

/*!
 * \brief Splits a larger value into two smaller parts.
 * \param x The value to split.
 * \param highPtr Pointer to store the high part or upper half.
 * \param lowPtr Pointer to store the low part or lower half. 
 *
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-08-31
 * \copyright Copyright (c) 2025
 */
#define BitConverter_Split(x, highPtr, lowPtr) _Generic((x), \
    TYPE_TABLE(BitConverter_Split) \
)(x, highPtr, lowPtr)

void BitConverter_Split_int16_t(int16_t value, int8_t* high, int8_t* low);
void BitConverter_Split_int32_t(int32_t value, int16_t* high, int16_t* low);
void BitConverter_Split_int64_t(int64_t value, int32_t* high, int32_t* low);
void BitConverter_Split_uint16_t(uint16_t value, uint8_t* high, uint8_t* low);
void BitConverter_Split_uint32_t(uint32_t value, uint16_t* high, uint16_t* low);
void BitConverter_Split_uint64_t(uint64_t value, uint32_t* high, uint32_t* low);
void BitConverter_Split_double(double value, float* high, float* low);

#ifdef __cplusplus
}
#endif

#endif // BITCONVERTER_H
