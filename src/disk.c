#include "./include/disk.h"
#include "./include/color.h"
#define _POSIX_C_SOURCE 200809L

#include "../config/config.h"
#include <stdio.h>

#ifdef __linux__
    #include <sys/statvfs.h>
#elif __APPLE__
#endif

// work in progress

void disk()
{
    struct statvfs st;
    statvfs("/", &st);
    unsigned long free_space = st.f_bfree * st.f_frsize;
    free_space = free_space / 1024 / 1024 / 1024;
    unsigned long total_space = st.f_blocks * st.f_frsize;
    total_space = total_space / 1024 / 1024 / 1024;
    printf(RED "%s" RESET, "FREE/TOTAL_DISK: ");
    printf("%luGB / %luGB\n", free_space, total_space);
}
