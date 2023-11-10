#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common.h"
#include "types.h"
#include "fs.h"
#include "page.h"
#include "sbi_call.h"
#include "process.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
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

// struct process {
//     int pid;
//     int state;
//     vaddr_t sp;
//     uint32_t *page_table;
//     uint8_t stack[8192];
// };

/************************************
 * EXPORTED VARIABLES
 ************************************/
extern char __bss[], __bss_end[], __stack_top[];
// extern char __free_ram[], __free_ram_end[];
// extern char __kernel_base[];
extern char _binary_shell_bin_start[], _binary_shell_bin_size[];

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
// struct process procs[PROCS_MAX];
// struct process *current_proc;
// struct process *idle_proc;