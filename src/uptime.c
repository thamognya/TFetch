#include "./include/uptime.h"
#include <stdio.h>
#include <sys/sysinfo.h>

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
        struct sysinfo info;
        sysinfo(&info);
        printf(RED "%s" RESET, "UPTIME: ");
        printf("%02ld ", info.uptime/3600);
        printf(BLU "%s " RESET, "hours");
        printf("%02ld ", info.uptime%3600/60);
        printf(BLU "%s " RESET, "mins");
        printf("%02ld ", info.uptime%60);
        printf(BLU "%s " RESET, "secs");
        printf("\n");
        return 0;
    #elif __APPLE__
        printf(RED "%s" RESET, "OS: ");
        printf("%s", "macOS");
        printf("\n");
        return 0;
    #endif

}
