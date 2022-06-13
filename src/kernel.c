#define _POSIX_C_SOURCE 200809L
#include "./include/kernel.h"

#include "../config/config.h"
// get colors
#include "./include/color.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>


int kernel()
{
    // code inspired from https://stackoverflow.com/questions/35095887/print-system-name-in-c 
    struct utsname uts;
    if(uname(&uts) !=0 )
    {
        return EXIT_FAILURE;
    }
    // print the OS of linux
    // get the os name instead of os and kernel
    
    printf(RED "%s" RESET, "KERNEL: ");
    printf("%s", uts.release);
    printf("\n");

    return EXIT_SUCCESS;
}
