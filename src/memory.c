#include <stdio.h>

#ifdef __linux__
    #include <sys/sysinfo.h>
#elif __APPLE__
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

int memory()
{
    #ifdef __linux__
        // make type info
        struct sysinfo info;
        sysinfo(&info);
        printf(RED "%s" RESET, "RAM: ");
        printf("%02ld", (((info.freeram)/1024)/1024));
        printf(BLU "%s" RESET, "/");
        printf("%02ld", (((info.totalram)/1024)/1024));
        printf("\n");
        return 0;
    #elif __APPLE__
        // I need something to replace sys/sysinfo
        return 0;
    #else
        return 1;
    #endif
}
