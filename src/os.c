#define _POSIX_C_SOURCE 200809L
#include "./include/os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
// get colors
#include "./include/color.h"
#include "./include/extra_functions.h"

void os()
{
    #ifdef __linux__
	    struct utsname uts;
	    uname(&uts);
		char *osname = get_linux_distro();
    	printf(RED "%s" RESET, "OS: ");
    	printf("%s", osname);
		printf("%s", " GNU/LINUX");
		printf("%s%s%s", " [" , uts.machine , "]");
    	printf("\n");
    #elif __APPLE__
        printf(RED "%s" RESET, "OS: ");
        printf("%s", "macOS");
        printf("\n");
	#else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
    #endif
}
