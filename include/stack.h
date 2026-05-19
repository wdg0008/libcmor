/*!
 * \file stack.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Implements a generic stack using statically allocated arrays.
 * \version 0.1
 * \date 2026-05-19
 * 
 * \copyright Copyright (c) 2026
 * 
 */

#include <stdbool.h>
#include <string.h>

/*! Type-generic stack using void pointers */
typedef struct {
    void* data; //!< Pointer to the stack's data array
    size_t itemSize; //!< Size of each element in bytes
    int itemCap; //!< Total capacity of the stack (number of elements)
    size_t top; //!< Index of the top element (0-based)
} Stack;

/*! Errror codes for stack functions */
typedef enum {
    STACK_SUCCESS = 0, //!< function completed normally
    STACK_FULL, //!< function terminated due to stack overflow
    STACK_EMPTY, //!< function terminated due to stack underflow
    STACK_INVALID //!< function terminated due to invalid state or parameters
} StackStatus;

/*!
 * \brief Initialize the stack with an external buffer
 * 
 * \param s Pointer to the stack to initialize
 * \param buf Pointer to buffer to manipulate and store data in
 * \param bufSize Buffer size in bytes
 * \param size Size of the type to store in the stack
 * \param cap Maximum number of items to configure the stack for
 * \return StackStatus Error code indicating success or describing failure
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
StackStatus stack_init(Stack *s, void *buf, size_t bufSize, size_t size, int cap);

/*!
 * \brief Check whether the stack is empty.
 * 
 * \param s Pointer to the stack to check
 * \return true when it is empty
 * \return false if there is anything in the stack or it is null
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
bool stack_isEmpty(const Stack *s);

/*!
 * \brief Check whether the stack is full
 * 
 * \param s Pointer to the stack to check
 * \return true when it is full
 * \return false if there is more room in the stack or it is null
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
bool stack_isFull(const Stack *s);

/*!
 * \brief Push an item onto the stack through a pointer
 * 
 * \param s Pointer to the stack
 * \param item Pointer to the item to copy onto the stack
 * \return StackStatus Indicates success or overflow
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
StackStatus stack_push(Stack *s, const void *item);

/*!
 * \brief Pop an item off of the stack into the destination buffer
 * 
 * \param s Pointer to the stack
 * \param dest Pointer to the buffer in which to save the popped item
 * \return StackStatus Indicates success or underflow
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
StackStatus stack_pop(Stack *s, void *dest);