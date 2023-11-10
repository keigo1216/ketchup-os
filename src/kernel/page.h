#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common/common.h"
#include "common/types.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
extern char __kernel_base[];
extern char __free_ram[], __free_ram_end[];
paddr_t alloc_page(uint32_t n);
void map_page(uint32_t *table1, uint32_t vaddr, paddr_t paddr, uint32_t flags);