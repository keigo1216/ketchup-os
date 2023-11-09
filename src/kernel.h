#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common.h"
#include "types.h"
#include "fs.h"
#include "page.h"

/************************************
 * MACROS AND DEFINES
 ************************************/
// #define PANIC(fmt, ...) \
//     do { \
//         printf("PANIC: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
//         while (1) { } \
//     } while (0)

// #define READ_CSR(reg) \
//     ({ \
//         unsigned long __tmp; \
//         __asm__ __volatile__("csrr %0, " #reg : "=r"(__tmp)); \
//         __tmp; \
//     })

// #define WRITE_CSR(reg, value) \
//     ({ \
//         uint32_t __tmp = (value); \
//         __asm__ __volatile__("csrw " #reg ", %0" :: "r"(__tmp)); \
//     })

/************************************
 * TYPEDEFS
 ************************************/
// for virtio-blk
// struct virtq_desc {
//     uint64_t addr;
//     uint32_t len;
//     uint16_t flags;
//     uint16_t next;
// } __attribute__((packed));

// struct virtq_avail {
//     uint16_t flags;
//     uint16_t index;
//     uint16_t ring[VIRTQ_ENTRY_NUM];
// } __attribute__((packed));

// struct virtq_used_elem {
//     uint32_t id;
//     uint32_t len;
// } __attribute__((packed));

// struct virtq_used {
//     uint16_t flags;
//     uint16_t index;
//     struct virtq_used_elem ring[VIRTQ_ENTRY_NUM];
// } __attribute__((packed));

// struct virtio_virtq {
//     struct virtq_desc descs[VIRTQ_ENTRY_NUM];
//     struct virtq_avail avail;
//     struct virtq_used used __attribute__((aligned(PAGE_SIZE)));
//     int queue_index;
//     volatile uint16_t *used_index;
//     uint16_t last_used_index;
// } __attribute__((packed));

// struct virtio_blk_req {
//     uint32_t type;
//     uint32_t reserved;
//     uint64_t sector;
//     uint8_t data[512];
//     uint8_t status;
// } __attribute__((packed));

struct trap_frame {
    uint32_t ra;
    uint32_t gp;
    uint32_t tp;
    uint32_t t0;
    uint32_t t1;
    uint32_t t2;
    uint32_t t3;
    uint32_t t4;
    uint32_t t5;
    uint32_t t6;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t a6;
    uint32_t a7;
    uint32_t s0;
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s4;
    uint32_t s5;
    uint32_t s6;
    uint32_t s7;
    uint32_t s8;
    uint32_t s9;
    uint32_t s10;
    uint32_t s11;
    uint32_t sp;
} __attribute__((packed));

struct sbiret {
    long error;
    long value;
};

struct process {
    int pid;
    int state;
    vaddr_t sp;
    uint32_t *page_table;
    uint8_t stack[8192];
};

/************************************
 * EXPORTED VARIABLES
 ************************************/
extern char __bss[], __bss_end[], __stack_top[];
// extern char __free_ram[], __free_ram_end[];
extern char __kernel_base[];
extern char _binary_shell_bin_start[], _binary_shell_bin_size[];

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
struct process procs[PROCS_MAX];
struct process *current_proc;
struct process *idle_proc;