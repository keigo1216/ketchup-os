#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "types.h"

/************************************
 * MACROS AND DEFINES
 ************************************/
#define PANIC(fmt, ...) \
    do { \
        printf("PANIC: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
        while (1) { } \
    } while (0)

#define READ_CSR(reg) \
    ({ \
        unsigned long __tmp; \
        __asm__ __volatile__("csrr %0, " #reg : "=r"(__tmp)); \
        __tmp; \
    })

#define WRITE_CSR(reg, value) \
    ({ \
        uint32_t __tmp = (value); \
        __asm__ __volatile__("csrw " #reg ", %0" :: "r"(__tmp)); \
    })

/************************************
 * TYPEDEFS
 ************************************/
typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);