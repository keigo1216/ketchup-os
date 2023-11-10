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
#include "trap.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/
extern char __bss[], __bss_end[], __stack_top[];
extern char _binary_shell_bin_start[], _binary_shell_bin_size[];

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/