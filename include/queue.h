/*!
 * \file queue.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Implements a generic queue using statically allocated arrays.
 * \version 0.1
 * \date 2026-05-19
 * 
 * \copyright Copyright (c) 2026
 * 
 */

#include <stdbool.h>
#include <string.h>

/*! Type-generic queue using pointers */
typedef struct {
    void* data; //!< Pointer to the queue's data array
    size_t itemSize; //!< Size of each element in bytes
    int itemCap; //!< Total capacity of the queue (number of elements)
    size_t front; //!< Index of the front element (0-based)
    size_t rear; //!< Index of the rear element (0-based)
    size_t count; //!< Number of elements currently in the queue
} Queue;

/*! Error codes for queue functions */
typedef enum {
    QUEUE_SUCCESS = 0, //!< function completed normally
    QUEUE_FULL, //!< function terminated becasue queue filled up
    QUEUE_EMPTY, //!< function terminated because queue empty
    QUEUE_INVALID //!, function terminated due to invalid state or parameters
} QueueStatus;

/*!
 * \brief Initialize the queue with an external buffer
 * 
 * \param q Pointer to the queue to initialize
 * \param buf Pointer to buffer to manipulate and store data in
 * \param bufSize Buffer size in bytes
 * \param size Size of the type to store in the queue
 * \param cap Maximum number of items to configure the queue for
 * \return QueueStatus Error code indicating success or describing failure
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
QueueStatus queue_init(Queue *q, void *buf, size_t bufSize, size_t size, int cap);

/*!
 * \brief Check whether the queue is empty.
 * 
 * \param q Pointer to the queue to check
 * \return true when it is empty
 * \return false if there is anything in the queue or it is null
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
bool queue_isEmpty(const Queue *q);

/*!
 * \brief Check whether the queue is full
 * 
 * \param q Pointer to the queue to check
 * \return true when it is full
 * \return false if there is more room or it is null
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
bool queue_isFull(const Queue *q);

/*!
 * \brief Clear the contents of an initialized queue
 * 
 * \param q pointer to the queue
 * \return QueueStatus 
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
QueueStatus queue_clear(Queue *q);

/*!
 * \brief Enqueue an item through a pointer to it
 * 
 * \param q Pointer to the queue
 * \param item Pointer to the item to copy into the queue
 * \return QueueStatus Indicates success or full queue
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
QueueStatus queue_enqueue(Queue *q, const void *item);

/*!
 * \brief Dequeue an item and copy it into the destination buffer
 * 
 * \param q Pointer to tthe queue
 * \param dest Pointer to the buffer in which to save the dequeued item
 * \return QueueStatus Indicates success or empty queue
 * \version 0.1
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \date 2026-05-19
 * \copyright Copyright (c) 2026
 */
QueueStatus queue_dequeue(Queue *q, void *dest);