#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
#endif

int memory()
{
    #ifdef __linux__
        // make type info
        struct sysinfo info;
        sysinfo(&info);
        printf("total ram: %s", info.totalram);
        return 0;
    #elif __APPLE__
    return 0;
    #endif
}
