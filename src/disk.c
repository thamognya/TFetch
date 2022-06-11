#include "./include/disk.h"
#include "./include/color.h"
#define _POSIX_C_SOURCE 200809L
#ifdef __linux__
    #include <sys/statvfs.h>
#elif __APPLE__
#endif

// work in progress
