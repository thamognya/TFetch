#include "./include/uptime.h"
#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
    #include <sys/sysctl.h>
#endif

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int uptime()
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
        return 0;
    #elif __APPLE__
        // need to find way to get uptime future
        return 0;
    #else
        printf("%s\n", "Your OS Not supported");
        return 1;
    #endif

}
