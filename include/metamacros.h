/*!
 * \file metamacros.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Includes macros for metaprogramming tasks in C.
 * \remarks Type iteration and generic function mapping are cool, but gross.
 *
 * This was inspired by generic programming in C++ templates.
 * It turns out that C11's _Generic is powerful enough to do some of the same things.
 *
 * You start by writing a normal function that operates on a single type.
 * That type is typedef'd to something -- int, short, whatever.
 * Rewrite the function as a macro that takes the type as a parameter.
 * Call the macro once for each type you want to support.
 * Then, you can use _Generic to map a function name to each macro instantiation.
 *
 * Managing all these macros is a pain -- hence this file, AND MORE MACROS!
 *
 * \warning If you use these well, you may write more macros than C.
 *
 * \version 0.1
 * \date 2025-09-04
 *
 * "Your scientists were so preoccupied with whether or not they could,
 * they didn't stop to think if they should." - Dr. Ian Malcolm, Jurassic Park
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#ifndef METAMACROS_H
#define METAMACROS_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Iterates a macro or function over all supported types.
 * \remarks Useful for shortening repetitive declarations and definitions.
 *
 * This macro is used to define and declare eight functions in a single line.
 * \see QUICK_SORT_DECLARE and QUICK_SORT_DEFINE in quicksort.h for an example of its usage.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define TYPE_ITERATOR(FMACRO) \
    FMACRO(int8_t)   \
    FMACRO(int16_t)  \
    FMACRO(int32_t)  \
    FMACRO(int64_t)  \
    FMACRO(uint8_t)  \
    FMACRO(uint16_t) \
    FMACRO(uint32_t) \
    FMACRO(uint64_t) \
    FMACRO(float)    \
    FMACRO(double)

/*!
 * \brief Maps a function to a supported type for _Generic usage.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define FTYPE_MAP(FUNC, T) T: FUNC##_##T

/*!
 * \brief Expands a _Generic mapping to function implementations for all supported types.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define TYPE_TABLE(FUNC) \
    FTYPE_MAP(FUNC, int8_t), \
    FTYPE_MAP(FUNC, int16_t), \
    FTYPE_MAP(FUNC, int32_t), \
    FTYPE_MAP(FUNC, int64_t), \
    FTYPE_MAP(FUNC, uint8_t), \
    FTYPE_MAP(FUNC, uint16_t), \
    FTYPE_MAP(FUNC, uint32_t), \
    FTYPE_MAP(FUNC, uint64_t), \
    FTYPE_MAP(FUNC, float), \
    FTYPE_MAP(FUNC, double)

/*!
 * \brief Maps a function to a pointer of a supported type for _Generic usage.
 * 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2025-09-04
 * \copyright Copyright (c) 2025
 */
#define FPTR_MAP(FUNC, T) T*: FUNC##_##T
    
#define TYPE_PTR_TABLE(FUNC) \
    FPTR_MAP(FUNC, int8_t), \
    FPTR_MAP(FUNC, int16_t), \
    FPTR_MAP(FUNC, int32_t), \
    FPTR_MAP(FUNC, int64_t), \
    FPTR_MAP(FUNC, uint8_t), \
    FPTR_MAP(FUNC, uint16_t), \
    FPTR_MAP(FUNC, uint32_t), \
    FPTR_MAP(FUNC, uint64_t), \
    FPTR_MAP(FUNC, float), \
    FPTR_MAP(FUNC, double)

#ifdef __cplusplus
}
#endif

#endif // METAMACROS_H
