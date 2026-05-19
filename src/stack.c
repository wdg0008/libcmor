#include "stack.h"

StackStatus stack_init(Stack *s, void *buf, size_t bufSize, size_t size, int cap) {
    if (buf == NULL || bufSize < size * cap) {
        return STACK_INVALID;
    }

    s->data = buf;
    s->itemSize = size;
    s->itemCap = cap;
    s->top = -1;
    return STACK_SUCCESS;
}

bool stack_isEmpty(Stack *s) {
    return (s->top == 0);
}

bool stack_isFull(Stack *s) {
    return (s->top == s->itemCap - 1);
}

StackStatus stack_push(Stack *s, const void *item) {
    if (s->top == s->itemCap - 1) {
        return STACK_FULL;
    }
    void *target = s->data + (++(s->top) * s->itemSize);
    memcpy(target, item, s->itemSize);
    return STACK_SUCCESS;
}


StackStatus stack_pop(Stack *s, void *dest) {
    if (s->top == -1) {
        return STACK_EMPTY;
    }
    void *source = s->data + (s->top * s->itemSize);
    memcpy(dest, source, s->itemSize);
    s->top--;
    return STACK_SUCCESS;
}