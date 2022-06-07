#define _POSIX_SOURCE

#include "./include/os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <regex.h>
// get colors
#include "./include/color.h"

int os()
{
    #ifdef __linux__
    // code inspired from https://stackoverflow.com/questions/35095887/print-system-name-in-c 
    struct utsname uts;
    if(uname(&uts) !=0 )
    {
        return EXIT_FAILURE;
    }
    // print the OS of linux
    // get the os name instead of os and kernel

    char command[50];
    strcpy( command, "uname -o" );
    system(command);
    
    printf(RED "%s" RESET, "OS: ");
    printf("%s", uts.release);

    printf("\n");

    return EXIT_SUCCESS;
    #elif __APPLE__
        printf(RED "%s" RESET, "OS: ");
        printf("%s", "macOS");
        printf("\n");
        return 0;
    #endif
}
