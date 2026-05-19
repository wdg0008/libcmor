#include "queue.h"

QueueStatus queue_init(Queue *q, void *buf, size_t bufSize, size_t size, int cap) {
    if (q == NULL || buf == NULL || size == 0 || cap <= 0 || bufSize < size * cap) {
        return QUEUE_INVALID;
    }
    q->data = buf;
    q->itemSize = size;
    q->itemCap = cap;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return QUEUE_SUCCESS;
}

bool queue_isEmpty(const Queue *q) {
    if (q == NULL) {
        return false;
    }
    return q->count == 0;
}

bool queue_isFull(const Queue *q) {
    if (q == NULL) {
        return false;
    }
    return q->count == q->itemCap;
}

QueueStatus queue_clear(Queue *q) {
    if (q == NULL) {
        return QUEUE_INVALID;
    }
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return QUEUE_SUCCESS;
}

QueueStatus queue_enqueue(Queue *q, const void *item) {
    if (q == NULL || item == NULL) {
        return QUEUE_INVALID;
    }
    if (queue_isFull(q)) {
        return QUEUE_FULL;
    }
    unsigned char *base = q->data;
    memcpy(base + (q->rear * q->itemSize), item, q->itemSize);
    q->rear = (q->rear == q->itemCap - 1) ? 0 : q->rear + 1;
    q->count++;
    return QUEUE_SUCCESS;
}

QueueStatus queue_dequeue(Queue *q, void *dest) {
    if (q == NULL || dest == NULL) {
        return QUEUE_INVALID;
    }
    if (queue_isEmpty(q)) {
        return QUEUE_EMPTY;
    }
    const unsigned char *base = q->data;
    memcpy(dest, base + (q->front * q->itemSize), q->itemSize);
    q->front = (q->front == q->itemCap - 1) ? 0 : q->front + 1;
    q->count--;
    return QUEUE_SUCCESS;
}