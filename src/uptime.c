#define _POSIX_C_SOURCE 200809L
#include "./include/uptime.h"
#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
    #include <sys/sysctl.h>
#endif
// get colors
#include "./include/color.h"

void uptime()
{
    #ifdef __linux__
        // make type info
        struct sysinfo info;
        sysinfo(&info);
        // print uptime
        printf(RED "%s" RESET, "UPTIME: ");
        // print the uptime / 3600 to get hours
        printf("%02ld ", info.uptime/3600);
        // print hours
        printf(BLU "%s " RESET, "hours");
        // print the uptime in hours
        printf("%02ld ", info.uptime%3600/60);
        // print mins
        printf(BLU "%s " RESET, "mins");
        // print hte up time in seconds
        printf("%02ld ", info.uptime%60);
        // print seconds
        printf(BLU "%s " RESET, "secs");
        // print new line
        printf("\n");
    #elif __APPLE__
        // need to find way to get uptime future
    #else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
    #endif

}
