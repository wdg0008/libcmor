#include "../include/bitconverter.h"
#include <string.h> // For memcpy

bool g_is_little_endian = true; // == 1 if little-endian

void BitConverter_Init() {
    const uint16_t test = 0x1;
    g_is_little_endian = (*(uint8_t*)&test); // == 1 if little-endian
}

uint8_t BitConverter_Log2Int(uint64_t value) {
    if (!BitConverter_IsPow2(value)) return 0xFF;
    uint8_t log = 0;
    while (value >>= 1) ++log;
    return log;
}

double BitConverter_DoubleFromUInt64(uint64_t value) {
    double result;
    memcpy(&result, &value, sizeof(double));
    return result;
}

float BitConverter_FloatFromUInt32(uint32_t value) {
    float result;
    memcpy(&result, &value, sizeof(float));
    return result;
}

uint64_t BitConverter_UInt64FromDouble(double value) {
    uint64_t result;
    memcpy(&result, &value, sizeof(double));
    return result;
}

uint32_t BitConverter_UInt32FromFloat(float value) {
    uint32_t result;
    memcpy(&result, &value, sizeof(float));
    return result;
}

void BitConverter_GetBytes_Int16(int16_t value, uint8_t bytes[2]) {
    if (g_is_little_endian) {
        bytes[0] = (uint8_t)(value & 0xFF);
        bytes[1] = (uint8_t)((value >> 8) & 0xFF);
    } else {
        bytes[1] = (uint8_t)(value & 0xFF);
        bytes[0] = (uint8_t)((value >> 8) & 0xFF);
    }
}

void BitConverter_GetBytes_UInt16(uint16_t value, uint8_t bytes[2]) {
    if (g_is_little_endian) {
        bytes[0] = (uint8_t)(value & 0xFF);
        bytes[1] = (uint8_t)((value >> 8) & 0xFF);
    } else {
        bytes[1] = (uint8_t)(value & 0xFF);
        bytes[0] = (uint8_t)((value >> 8) & 0xFF);
    }
}

void BitConverter_GetBytes_Int32(int32_t value, uint8_t bytes[4]) {
    if (g_is_little_endian) {
        for (int i = 0; i < 4; i++) {
            bytes[i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            bytes[3 - i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    }
}

void BitConverter_GetBytes_UInt32(uint32_t value, uint8_t bytes[4]) {
    if (g_is_little_endian) {
        for (int i = 0; i < 4; i++) {
            bytes[i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            bytes[3 - i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    }
}

void BitConverter_GetBytes_Int64(int64_t value, uint8_t bytes[8]) {
    if (g_is_little_endian) {
        for (int i = 0; i < 8; i++) {
            bytes[i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    } else {
        for (int i = 0; i < 8; i++) {
            bytes[7 - i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    }
}

void BitConverter_GetBytes_UInt64(uint64_t value, uint8_t bytes[8]) {
    if (g_is_little_endian) {
        for (int i = 0; i < 8; i++) {
            bytes[i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    } else {
        for (int i = 0; i < 8; i++) {
            bytes[7 - i] = (uint8_t)((value >> (i * 8)) & 0xFF);
        }
    }
}

void BitConverter_GetBytes_Float(float value, uint8_t bytes[4]) {
    uint32_t asInt;
    memcpy(&asInt, &value, sizeof(float));
    BitConverter_GetBytes_UInt32(asInt, bytes);
}

void BitConverter_GetBytes_Double(double value, uint8_t bytes[8]) {
    uint64_t asInt;
    memcpy(&asInt, &value, sizeof(double));
    BitConverter_GetBytes_UInt64(asInt, bytes);
}

int16_t BitConverter_ToInt16(const uint8_t bytes[2]) {
    if (g_is_little_endian) {
        return (int16_t)(bytes[0] | (bytes[1] << 8));
    } else {
        return (int16_t)(bytes[1] | (bytes[0] << 8));
    }
}

uint16_t BitConverter_ToUInt16(const uint8_t bytes[2]) {
    if (g_is_little_endian) {
        return (uint16_t)(bytes[0] | (bytes[1] << 8));
    } else {
        return (uint16_t)(bytes[1] | (bytes[0] << 8));
    }
}

int32_t BitConverter_ToInt32(const uint8_t bytes[4]) {
    int32_t result = 0;
    if (g_is_little_endian) {
        for (int i = 0; i < 4; i++) {
            result |= ((int32_t)bytes[i] << (i * 8));
        }
    } else {
        for (int i = 0; i < 4; i++) {
            result |= ((int32_t)bytes[3 - i] << (i * 8));
        }
    }
    return result;
}

uint32_t BitConverter_ToUInt32(const uint8_t bytes[4]) {
    uint32_t result = 0;
    if (g_is_little_endian) {
        for (int i = 0; i < 4; i++) {
            result |= ((int32_t)bytes[i] << (i * 8));
        }
    } else {
        for (int i = 0; i < 4; i++) {
            result |= ((int32_t)bytes[3 - i] << (i * 8));
        }
    }
    return result;
}

int64_t BitConverter_ToInt64(const uint8_t bytes[8]) {
    int64_t result = 0;
    if (g_is_little_endian) {
        for (int i = 0; i < 8; i++) {
            result |= ((int32_t)bytes[i] << (i * 8));
        }
    } else {
        for (int i = 0; i < 8; i++) {
            result |= ((int32_t)bytes[7 - i] << (i * 8));
        }
    }
    return result;
}

uint64_t BitConverter_ToUInt64(const uint8_t bytes[8]) {
    uint64_t result = 0;
    if (g_is_little_endian) {
        for (int i = 0; i < 8; i++) {
            result |= ((int32_t)bytes[i] << (i * 8));
        }
    } else {
        for (int i = 0; i < 8; i++) {
            result |= ((int32_t)bytes[7 - i] << (i * 8));
        }
    }
    return result;
}

float BitConverter_ToFloat(const uint8_t bytes[4]) {
    uint32_t asInt = BitConverter_ToUInt32(bytes);
    float value;
    memcpy(&value, &asInt, sizeof(float));
    return value;
}

double BitConverter_ToDouble(const uint8_t bytes[8]) {
    uint64_t asInt = BitConverter_ToUInt64(bytes);
    double value;
    memcpy(&value, &asInt, sizeof(double));
    return value;
}

void BitConverter_Reverse_Bytes(uint8_t* bytes, size_t length) {
    for (size_t i = 0; i < length / 2; i++) {
        uint8_t temp = bytes[i];
        bytes[i] = bytes[length - 1 - i];
        bytes[length - 1 - i] = temp;
    }
}

int16_t BitConverter_Reverse_Int16(int16_t value) {
    return (int16_t)BitConverter_Reverse_UInt16((uint16_t)value);
}

uint16_t BitConverter_Reverse_UInt16(uint16_t value) {
    return (uint16_t)((value >> 8) | (value << 8));
}

int32_t BitConverter_Reverse_Int32(int32_t value) {
    return (int32_t)BitConverter_Reverse_UInt32((uint32_t)value);
}

uint32_t BitConverter_Reverse_UInt32(uint32_t value) {
    return ((value >> 24) & 0xFF) | 
           ((value >> 8) & 0xFF00) | 
           ((value << 8) & 0xFF0000) | 
           ((value << 24) & 0xFF000000);
}

int64_t BitConverter_Reverse_Int64(int64_t value) {
    return (int64_t)BitConverter_Reverse_UInt64((uint64_t)value);
}

uint64_t BitConverter_Reverse_UInt64(uint64_t value) {
    uint64_t result = 0;
    for (int i = 0; i < 8; i++) {
        result |= ((value >> (i * 8)) & 0xFF) << ((7 - i) * 8);
    }
    return result;
}

float BitConverter_Reverse_Float(float value) {
    uint32_t asInt;
    memcpy(&asInt, &value, sizeof(float));
    asInt = BitConverter_Reverse_UInt32(asInt);
    float result;
    memcpy(&result, &asInt, sizeof(float));
    return result;
}

double BitConverter_Reverse__Double(double value) {
    uint64_t asInt;
    memcpy(&asInt, &value, sizeof(double));
    asInt = BitConverter_Reverse_UInt32(asInt);
    double result;
    memcpy(&result, &asInt, sizeof(double));
    return result;
}

int16_t BitConverter_Join_Int16(int8_t high, int8_t low) {
    return (int16_t)(BitConverter_Join_UInt16((uint8_t) high, (uint8_t) low));
}

uint16_t BitConverter_Join_UInt16(uint8_t high, uint8_t low) {
    return  ((uint16_t)high << 8) | low;
}

int32_t BitConverter_Join_Int32(int16_t high, int16_t low) {
    return (int32_t)(BitConverter_Join_UInt16((uint16_t) high, (uint16_t) low));
}

uint32_t BitConverter_Join_UInt32(uint16_t high, uint16_t low) {
    return  ((uint32_t)high << 16) | low;
}

int64_t BitConverter_Join_Int64(int32_t high, int32_t low) {
    return (int64_t)(BitConverter_Join_UInt64((uint32_t) high, (uint32_t) low));
}

uint64_t BitConverter_Join_UInt64(uint32_t high, uint32_t low) {
    return ((uint64_t)high << 32) | low;
}

double BitConverter_Join_Double(float high, float low) {
    uint32_t highInt = BitConverter_UInt32FromFloat(high);
    uint32_t lowInt = BitConverter_UInt32FromFloat(low);
    uint64_t combined = BitConverter_Join_UInt64(highInt, lowInt);
    return BitConverter_DoubleFromUInt64(combined);
}

void BitConverter_Split_Int16(int16_t value, int8_t* high, int8_t* low) {
    BitConverter_Split_UInt16((uint16_t)value, (uint8_t*)high, (uint8_t*)low);
}
    
void BitConverter_Split_UInt16(uint16_t value, uint8_t* high, uint8_t* low) {
    *high = (int8_t)((value >> 8) & 0xFF);
    *low = (int8_t)(value & 0xFF);
}

void BitConverter_Split_Int32(int32_t value, int16_t* high, int16_t* low) {
    BitConverter_Split_UInt32((uint16_t)value, (uint16_t*)high, (uint16_t*)low);
}

void BitConverter_Split_UInt32(uint32_t value, uint16_t* high, uint16_t* low) {
    *high = (uint16_t)((value >> 16) & 0xFFFF);
    *low = (uint16_t)(value & 0xFFFF);
}

void BitConverter_Split_Int64(int64_t value, int32_t* high, int32_t* low) {
    BitConverter_Split_UInt64((uint64_t)value, (uint32_t*)high, (uint32_t*)low);
}

void BitConverter_Split_UInt64(uint64_t value, uint32_t* high, uint32_t* low) {
    *high = (uint32_t)((value >> 32) & 0xFFFFFFFF);
    *low = (uint32_t)(value & 0xFFFFFFFF);
}

void BitConverter_Split_Double(double value, float* high, float* low) {
    uint64_t dblInt = BitConverter_UInt64FromDouble(value);
    uint32_t highInt, lowInt;
    BitConverter_Split_UInt64(dblInt, &highInt, &lowInt);
    *high = BitConverter_FloatFromUInt32(highInt);
    *low = BitConverter_FloatFromUInt32(lowInt);
}
