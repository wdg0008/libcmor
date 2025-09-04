#ifndef BITCONVERTER_H
#define BITCONVERTER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int8_t Int8, int8, i8;
typedef uint8_t UInt8, uint8, u8;
typedef int16_t Int16, int16, i16;
typedef uint16_t UInt16, uint16, u16;
typedef int64_t Int64, int64, i64;
typedef uint32_t UInt32, uint32, u32;
typedef int32_t Int32, int32, i32;
typedef uint64_t UInt64, uint64, u64;

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
double BitConverter_DoubleFromUInt64(uint64_t value);

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
float BitConverter_FloatFromUInt32(uint32_t value);

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
uint64_t BitConverter_UInt64FromDouble(double value);

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
uint32_t BitConverter_UInt32FromFloat(float value);

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
    int16_t: BitConverter_GetBytes_Int16, \
    uint16_t: BitConverter_GetBytes_UInt16, \
    int32_t: BitConverter_GetBytes_Int32, \
    uint32_t: BitConverter_GetBytes_UInt32, \
    int64_t: BitConverter_GetBytes_Int64, \
    uint64_t: BitConverter_GetBytes_UInt64, \
    float: BitConverter_GetBytes_Float, \
    double: BitConverter_GetBytes_Double  \
)(x, byteArr)

void BitConverter_GetBytes_Int16(int16_t value, uint8_t bytes[2]);
void BitConverter_GetBytes_UInt16(uint16_t value, uint8_t bytes[2]);
void BitConverter_GetBytes_Int32(int32_t value, uint8_t bytes[4]);
void BitConverter_GetBytes_UInt32(uint32_t value, uint8_t bytes[4]);
void BitConverter_GetBytes_Int64(int64_t value, uint8_t bytes[8]);
void BitConverter_GetBytes_UInt64(uint64_t value, uint8_t bytes[8]);
void BitConverter_GetBytes_Float(float value, uint8_t bytes[4]);
void BitConverter_GetBytes_Double(double value, uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
int16_t BitConverter_ToInt16(const uint8_t bytes[2]);

/*! \brief Constructs a value from its byte representation. */
uint16_t BitConverter_ToUInt16(const uint8_t bytes[2]);

/*! \brief Constructs a value from its byte representation. */
int32_t BitConverter_ToInt32(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
uint32_t BitConverter_ToUInt32(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
int64_t BitConverter_ToInt64(const uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
uint64_t BitConverter_ToUInt64(const uint8_t bytes[8]);

/*! \brief Constructs a value from its byte representation. */
float BitConverter_ToFloat(const uint8_t bytes[4]);

/*! \brief Constructs a value from its byte representation. */
double BitConverter_ToDouble(const uint8_t bytes[8]);

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
    int16_t: BitConverter_Reverse_Int16, \
    uint16_t: BitConverter_Reverse_UInt16, \
    int32_t: BitConverter_Reverse_Int32, \
    uint32_t: BitConverter_Reverse_UInt32, \
    int64_t: BitConverter_Reverse_Int64, \
    uint64_t: BitConverter_Reverse_UInt64, \
    float: BitConverter_Reverse_Float, \
    double: BitConverter_Reverse_Double  \
)(x)

int16_t BitConverter_Reverse_Int16(int16_t value);
uint16_t BitConverter_Reverse_UInt16(uint16_t value);
int32_t BitConverter_Reverse_Int32(int32_t value);
uint32_t BitConverter_Reverse_UInt32(uint32_t value);
int64_t BitConverter_Reverse_Int64(int64_t value);
uint64_t BitConverter_Reverse_UInt64(uint64_t value);
float BitConverter_Reverse_Float(float value);
double BitConverter_Reverse_Double(double value);

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
    int8_t: BitConverter_Join_Int16, \
    uint8_t: BitConverter_Join_UInt16, \
    int16_t: BitConverter_Join_Int32, \
    uint16_t: BitConverter_Join_UInt32, \
    int32_t: BitConverter_Join_Int64, \
    uint32_t: BitConverter_Join_UInt64, \
    float: BitConverter_Join_Double  \
)(x, y)

int16_t BitConverter_Join_Int16(int8_t high, int8_t low);
uint16_t BitConverter_Join_UInt16(uint8_t high, uint8_t low);
int32_t BitConverter_Join_Int32(int16_t high, int16_t low);
uint32_t BitConverter_Join_UInt32(uint16_t high, uint16_t low);
int64_t BitConverter_Join_Int64(int32_t high, int32_t low);
uint64_t BitConverter_Join_UInt64(uint32_t high, uint32_t low);
double BitConverter_Join_Double(float high, float low);

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
    int16_t: BitConverter_Split_Int16, \
    uint16_t: BitConverter_Split_UInt16, \
    int32_t: BitConverter_Split_Int32, \
    uint32_t: BitConverter_Split_UInt32, \
    int64_t: BitConverter_Split_Int64, \
    uint64_t: BitConverter_Split_UInt64, \
    double: BitConverter_Split_Double  \
)(x, highPtr, lowPtr)

void BitConverter_Split_Int16(int16_t value, int8_t* high, int8_t* low);
void BitConverter_Split_UInt16(uint16_t value, uint8_t* high, uint8_t* low);
void BitConverter_Split_Int32(int32_t value, int16_t* high, int16_t* low);
void BitConverter_Split_UInt32(uint32_t value, uint16_t* high, uint16_t* low);
void BitConverter_Split_Int64(int64_t value, int32_t* high, int32_t* low);
void BitConverter_Split_UInt64(uint64_t value, uint32_t* high, uint32_t* low);
void BitConverter_Split_Double(double value, float* high, float* low);

#ifdef __cplusplus
}
#endif

#endif // BITCONVERTER_H
