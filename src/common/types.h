#pragma once

/************************************
 * MACROS AND DEFINES
 ************************************/
// Boolean
#define true 1
#define false 0

// NULL Pointer
#define NULL ((void *) 0)

// Cause of exception (When set scause register to 8, it means ecall)
#define SCAUSE_ECALL 8
// Change S-Mode to U-Mode
#define SSTATUS_SPIE (1 << 5)

// For paging
#define PAGE_V (1 << 0) // Valiable
#define PAGE_R (1 << 1) // Readable
#define PAGE_W (1 << 2) // Writable
#define PAGE_X (1 << 3) // Executable
#define PAGE_U (1 << 4) // Accessible from user mode

// align up value to align (exsample: align_up(0x1234, 0x1000) = 0x2000)
#define align_up(value, align)   __builtin_align_up(value, align)
// check if value is aligned to align (exsample: is_aligned(0x1234, 0x1000) = false)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
// get offset of member in struct (exsample: offsetof(struct foo, bar) = 0x10)
#define offsetof(type, member)   __builtin_offsetof(type, member)

#define va_list __builtin_va_list 
#define va_start __builtin_va_start    
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

// memory page size
#define PAGE_SIZE 4096
// enable paging on Sv32 mode
#define SATP_SV32 (1u << 31)

// system call (U-Mode)
#define SYS_PUTCHAR 1
#define SYS_GETCHAR 2
#define SYS_EXIT    3 

// process
#define PROCS_MAX 8
#define PROC_UNUSED 0
#define PROC_RUNNABLE 1
#define PROC_EXITED   2

// start of user memory
#define USER_BASE 0x1000000

// virtio-blk
#define SECTOR_SIZE       512
#define VIRTQ_ENTRY_NUM   16
#define VIRTIO_DEVICE_BLK 2
#define VIRTIO_BLK_PADDR  0x10001000
#define VIRTIO_REG_MAGIC         0x00
#define VIRTIO_REG_VERSION       0x04
#define VIRTIO_REG_DEVICE_ID     0x08
#define VIRTIO_REG_QUEUE_SEL     0x30
#define VIRTIO_REG_QUEUE_NUM_MAX 0x34
#define VIRTIO_REG_QUEUE_NUM     0x38
#define VIRTIO_REG_QUEUE_ALIGN   0x3c
#define VIRTIO_REG_QUEUE_PFN     0x40
#define VIRTIO_REG_QUEUE_READY   0x44
#define VIRTIO_REG_QUEUE_NOTIFY  0x50
#define VIRTIO_REG_DEVICE_STATUS 0x70
#define VIRTIO_REG_DEVICE_CONFIG 0x100
#define VIRTIO_STATUS_ACK       1
#define VIRTIO_STATUS_DRIVER    2
#define VIRTIO_STATUS_DRIVER_OK 4
#define VIRTIO_STATUS_FEAT_OK   8
#define VIRTQ_DESC_F_NEXT          1
#define VIRTQ_DESC_F_WRITE         2
#define VIRTQ_AVAIL_F_NO_INTERRUPT 1
#define VIRTIO_BLK_T_IN  0
#define VIRTIO_BLK_T_OUT 1

/************************************
 * TYPEDEFS
 ************************************/
typedef int bool;                       // For bool type
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;