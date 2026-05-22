/*!
 * \file mempool.h
 * \author William (116991920+wdg0008@users.noreply.github.com)
 * \brief Chunk-based homogeneous memory allocator using external buffer
 * \remarks Designed to be efficient and operate in O(1) time usually
 * \version 0.1
 * \date 2026-05-19
 * 
 * \copyright Copyright (c) 2026
 * 
 */

#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
 
typedef struct {
    unsigned char *buf;
    size_t blockSize;
    size_t blockCount;
    void *freeList;
    bool initialized;
} MemoryPool;

bool mp_init(
    MemoryPool *pool, 
    void *buf, 
    size_t bufSize, 
    size_t blockSize,
    size_t blockCount, 
    size_t *roundedBlockSize
);

void* mp_alloc(MemoryPool *pool);

void mp_free(MemoryPool *pool, void *ptr);

size_t mp_openBlocks(const MemoryPool *pool);

bool mp_isEmpty(const MemoryPool *pool);

#ifdef __cplusplus
}
#endif