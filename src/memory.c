#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
#endif

// get colors
#include "./include/color.h"

void memory()
{
    #ifdef __linux__
        // make type info
        struct sysinfo info;
        sysinfo(&info);
        printf(RED "%s" RESET, "FREE/TOTAL_RAM: ");
        printf("%02ld", (((info.freeram)/1024)/1024)); // total free ram = free + buffer/cache + swap total
        printf(BLU "%s" RESET, "/");
        printf("%02ld", (((info.totalram)/1024)/1024)); // total ram
        printf("\n");
    #elif __APPLE__
        // I need something to replace sys/sysinfo
    #else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
    #endif
}
