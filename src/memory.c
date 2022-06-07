#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
#endif

// get colors
#include "./include/color.h"

int memory()
{
    #ifdef __linux__
        // make type info
        struct sysinfo info;
        sysinfo(&info);
        printf(RED "%s" RESET, "FREE/TOTAL RAM (mib): ");
        printf("%02ld", (((info.freeram)/1024)/1024)); // total free ram = free + buffer/cache + swap total
        printf(BLU "%s" RESET, "/");
        printf("%02ld", (((info.totalram)/1024)/1024)); // total ram
        printf("\n");
        return 0;
    #elif __APPLE__
        // I need something to replace sys/sysinfo
        return 0;
    #else
        return 1;
    #endif
}
