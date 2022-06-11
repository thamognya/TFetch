#define _POSIX_C_SOURCE 200809L
#include "./include/packages.h"
#include "./include/color.h"
#include "./include/extra_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void packages()
{
    #ifdef __linux__
		char *pkgs;
		char *osname = get_linux_distro();
        if (strncmp(osname, "Gentoo", 6) == 0) 
        {
			pkgs = get_shell_output("qlist -I | wc -l");
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s", pkgs);
			printf("\n");
        }
        else if (strncmp(osname, "Arch", 4) == 0)
		{
        }
        else
        {
            printf("linux distro not yet supported. Please Make a pr at https://github.com/Thamognya/TFetch");
        }
    #elif __APPLE__
    #else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
    #endif
}