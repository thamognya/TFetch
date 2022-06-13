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
		char pkgs[32];
		char osname[512];
		char oscontent[512];
		get_linux_distro(oscontent, osname);
        if (strncmp(osname, "Gentoo", 6) == 0) 
        {
			get_shell_output("qlist -I | wc -l", pkgs);
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s (portage)", pkgs);
			printf("\n");
        }
        else if (strncmp(osname, "Arch", 4) == 0)
		{
            get_shell_output("pacman -Q | wc -l", pkgs);
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s (pacman)", pkgs);
			printf("\n");
        }
        else if (strncmp(osname, "Debian GNU/Linux", 16) == 0)
        {
            get_shell_output("dpkg -l | tail -n+6 | wc -l", pkgs);
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s (apt)", pkgs);
			printf("\n");
        }
	    else if (strncmp(osname, "void", 4) == 0)
	    {
	        pkgs = get_shell_output("xbps-query -l | wc -l");
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s (xbps)", pkgs);
			printf("\n");
	    }
	    else if (strncmp(osname, "NixOS", 5) == 0)
	    {
	        pkgs = get_shell_output("nix-store -q --requisites /run/current-system/sw | wc -l");
			printf(RED "%s" RESET, "PACKAGES: ");
		    printf("%s (nix)", pkgs);
		   printf("\n");
	    }
        else if (strncmp(osname, "EndeavourOS", 11) == 0)
        {
            pkgs = get_shell_output("pacman -Q | wc -l");
			printf(RED "%s" RESET, "PACKAGES: ");
			printf("%s (pacman)", pkgs);
			printf("\n");
        }
        else
        {
            printf("Linux distro not yet supported. Please make a pr at https://github.com/Thamognya/TFetch");
        }
    #elif __APPLE__
    #else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
    #endif
}
