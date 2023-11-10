#pragma once
/************************************
 * INCLUDES
 ************************************/

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
struct sbiret {
    long error;
    long value;
};

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4, 
                       long arg5, long fid, long eid);
