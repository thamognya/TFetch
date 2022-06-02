#include "./include/os.h"
#include <stdio.h>

int os()
{
    #ifdef __linux__
        printf("%s\n", "Temporary");
    #elif __APPLE__
        printf("OS: %s\n", "macOS");
    #endif

    return 0;
}
