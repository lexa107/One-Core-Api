/*
 * COPYRIGHT:  See COPYING in the top level directory
 * PROJECT:    ReactOS system libraries
 * FILE:       lib/kernel32/thread/i386/thread.S
 * PURPOSE:    Thread Start Thunks
 * PROGRAMMER: Alex Ionescu (alex@relsoft.net)
 */

#include <asm.inc>
#include <ks386.inc>

.code

EXTERN _BaseThreadStartup@8:PROC
EXTERN _BaseProcessStartup@4:PROC

PUBLIC _BaseThreadStartupThunk@0
_BaseThreadStartupThunk@0:
    
    /* Start out fresh */
    xor ebp, ebp
    
    push ebx                  /* lpParameter */
    push eax                  /* lpStartAddress */
    push 0                    /* Return EIP */
    jmp _BaseThreadStartup@8


PUBLIC _BaseProcessStartThunk@2
_BaseProcessStartThunk@2:
    /* Start out fresh */
    xor ebp, ebp
    
    push eax                  /* lpStartAddress */
    push 0                    /* Return EIP */
    jmp _BaseProcessStartup@4


END

/* EOF */
