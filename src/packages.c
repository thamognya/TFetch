#include "./include/packages.h"

#include <stdio.h>
#include <stdlib.h>

void packages()
{
    #ifdef __linux__
    #elif __APPLE__
    #else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
        return 1;
    #endif
}