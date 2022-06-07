#include "./include/logo.h"
#include <stdio.h>
// get colors
#include "./include/color.h"

// good idea from https://github.com/13-CF/afetch/blob/master/src/fetch.c


int logo()
{
    #ifdef __linux__
    	printf("%s\n", "tmp");
    #elif __APPLE__
        printf("%s\n", "");
    #endif

    return 0;
}
