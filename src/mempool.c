#include "mempool.h"
#include <stdalign.h>

bool mp_init(
    MemoryPool *pool, 
    void *buf,
    size_t bufSize,
    size_t blockSize,
    size_t blockCount,
    size_t *roundedBlockSize
) {
    if (!pool || !buf || blockSize < sizeof(void*) || bufSize < blockSize * blockCount) {
        return false;
    }

    size_t align = alignof(void*); // portably calculate pointer alignment

    // round up blockSize to prevent alignment issues
    size_t alignedSize = (blockSize + align - 1) & ~(align - 1);

    pool->buf = buf;
    pool->blockSize = alignedSize;
    pool->blockCount = blockCount;
    pool->freeList = NULL;
    pool->initialized = true;

    // abuse pointers horrifically
    unsigned char *p = (unsigned char*)buf;

    for (size_t i = 0; i < blockCount; ++i) {
        void *block = p + (i * alignedSize);
        // store in each block the pointer to the next block
        *(void **)block = pool->freeList;
        pool->freeList = block;
    }

    if (roundedBlockSize) { // optionally return the rounded block size
        *roundedBlockSize = alignedSize;
    }

    return true;
}

void* mp_alloc(MemoryPool *pool) {
    if (!pool || !pool->initialized || !pool->freeList) {
        return NULL;
    }
    
    void *block = pool->freeList;
    if (block == NULL) {
        return NULL; // no free blocks
    }

    // dereference pointer to next block
    pool->freeList = *(void **)block; // effectively a "pop"
    return block;
}

void mp_free(MemoryPool *pool, void *ptr) {
    if (!pool || !pool->initialized || !ptr) {
        return;
    }

    // write the pointer to freeList in the block
    *(void **)ptr = pool->freeList; // effectively a "push"
    pool->freeList = ptr;
}

size_t mp_openBlocks(const MemoryPool *pool) {
    if (!pool || !pool->initialized) {
        return 0;
    }

    size_t count = 0;
    void *node = pool->freeList;

    while (node) {
        count++;
        node = *(void **)node;
    }
    return count;
}

bool mp_isEmpty(const MemoryPool *pool) {
    if (!pool || !pool->initialized) {
        return true;
    }
    return pool->freeList == NULL;
}