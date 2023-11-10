#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common/common.h"
#include "common/types.h"
#include "page.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
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

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
extern struct process procs[PROCS_MAX];
extern struct process *current_proc;
extern struct process *idle_proc;
__attribute__((naked)) void user_entry(void);
__attribute__((naked)) void switch_context(uint32_t *prev_sp, uint32_t *next_sp);
struct process *create_process(const void *image, size_t image_size);
void yield(void);