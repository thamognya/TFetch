#define _POSIX_SOURCE

#include "./include/os.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
// get colors
#include "./include/color.h"

void os()
{
    #ifdef __linux__
		struct utsname uts;
		uname(&uts);
		// copied from https://github.com/13-CF/afetch/blob/master/src/fetch.c
		// I need more time before I can start with this my self
		// copied part start
		char *osContents = malloc(512);
		char *osname = malloc(512);
		int line = 0;
		FILE *f = fopen("/etc/os-release", "rt");
		if (f == NULL || osContents == NULL)
		{
			// copied part end
    		printf(RED "%s" RESET, "OS: ");
    		printf("%s", "GNU/Linux");
			printf("%s%s%s", " [" , uts.machine , "]");
    		printf("\n");
			// copied part start
		}
		while (fgets(osContents, 512, f)) {
			snprintf(osname, 512, "%.*s", 511, osContents + 4);
			if (strncmp(osname, "=", 1) == 0)
				break;
			line++;
		}
		fclose(f);
		free(osContents);
		if (strncmp(osname, "=", 1) == 0) {
			int len = strlen(osname);
			for (int i = 0; i < len; i++) {
				if (osname[i] == '\"' ||
				    osname[i] == '=') {
					for (int ii = 0; ii < len; ii++)
						osname[ii] =
						    osname[ii + 1];
					osname[strlen(osname) - 1] = '\0';
				}
			}
		}
		// copied part end
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

/*
	static struct utsname sysInfo;
	uname(&sysInfo);
	if (strncmp(sysInfo.sysname, "Linux", 5) == 0) {
		char *osContents = malloc(512);
		char *osname = malloc(512);
		int line = 0;
		FILE *f = fopen("/etc/os-release", "rt");
		if (f == NULL || osContents == NULL)
			return "Linux";
		while (fgets(osContents, 512, f)) {
			snprintf(osname, 512, "%.*s", 511, osContents + 4);
			if (strncmp(osname, "=", 1) == 0)
				break;
			line++;
		}
		fclose(f);
		free(osContents);
		if (strncmp(osname, "=", 1) == 0) {
			int len = strlen(osname);
			for (int i = 0; i < len; i++) {
				if (osname[i] == '\"' ||
				    osname[i] == '=') {
					for (int ii = 0; ii < len; ii++)
						osname[ii] =
						    osname[ii + 1];
					osname[strlen(osname) - 1] =
					    '\0';
				}
			}
		}
		if (osname == NULL)
			osname = malloc(512);
		strcpy(osname, osname);
		free(osname);
*/
