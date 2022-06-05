#include "./include/os.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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
