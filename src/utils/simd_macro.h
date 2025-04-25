#ifndef SIMD_MACRO_H
#define SIMD_MACRO_H
#include <stdlib.h>
// If the architecture supports vector size 512 (AVX-512 instructions)
#if defined(__AVX512F__)
#define ALIGNMENT 64
// else if it supports vector size 256 (AVX instructions)
#elif defined(__AVX__)
#define ALIGNMENT 32
// else probably it supports vector size 128 (SSE instructions).
#else
#define ALIGNMENT 16
#endif

#define ALIGNED _Alignas(ALIGNMENT)

// calloc_aligned combines calloc and alloc_aligned
// void* calloc_aligned(size_t alignment, size_t size) {
//     void* p = aligned_alloc(alignment, size);
//     memset(p, 0, size);
//     return p;
// }
  
#endif