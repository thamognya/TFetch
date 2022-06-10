#include "./include/logo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// get colors
#include "./include/color.h"

// good idea from https://github.com/13-CF/afetch/blob/master/src/fetch.c


int logo()
{
    #ifdef __linux__
    /*
        for testing purposes
    	printf("%s\n", "  ____            _              ");
    	printf("%s\n", " / ___| ___ _ __ | |_ ___   ___  ");
    	printf("%s\n", "| |  _ / _ \\ '_ \\| __/ _ \\ / _ \\ ");
    	printf("%s\n", "| |_| |  __/ | | | || (_) | (_) |");
    	printf("%s\n", " \\____|\\___|_| |_|\\__\\___/ \\___/ ");
    */
    /*  contributing guideline
        firstly use figlet
        secondly paste the figlet in a multiline comments before using the printf 
        if there are \ replace them with \\ in the printf (leaving the comment intact)
        use the macos one as an example
    */
		// copied from https://github.com/13-CF/afetch/blob/master/src/fetch.c
		// I need more time before I can start with this my self
        // get the osname
		char *osContents = malloc(512);
		char *osname = malloc(512);
		int line = 0;
		FILE *f = fopen("/etc/os-release", "rt");
		if (f == NULL || osContents == NULL)
		{
    		printf(RED "%s" RESET, "OS: ");
    		printf("%s", "Linux");
    		printf("\n");
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
        // check for the os name
        // using strncmp as it can define the number of charecters
        /*
  ____            _
 / ___| ___ _ __ | |_ ___   ___
| |  _ / _ \ '_ \| __/ _ \ / _ \
| |_| |  __/ | | | || (_) | (_) |
 \____|\___|_| |_|\__\___/ \___/
        */
        if (strncmp(osname, "Gentoo", 6) == 0) 
        {
            printf(MAG "%s\n" RESET, "  ____            _");
            printf(MAG "%s\n" RESET, " / ___| ___ _ __ | |_ ___   ___");
            printf(MAG "%s\n" RESET, "| |  _ / _ \\ '_ \\| __/ _ \\ / _ \\");
            printf(MAG "%s\n" RESET, "| |_| |  __/ | | | || (_) | (_) |");
            printf(MAG "%s\n" RESET, " \\____|\\___|_| |_|\\__\\___/ \\___/");
        }
        else
        {
            printf(WHT "%s\n" RESET, " _____ _____    _       _");
            printf(WHT "%s\n" RESET, "|_   _|  ___|__| |_ ___| |__");
            printf(WHT "%s\n" RESET, "  | | | |_ / _ \\ __/ __| '_ \\");
            printf(WHT "%s\n" RESET, "  | | |  _|  __/ || (__| | | |");
            printf(WHT "%s\n" RESET, "  |_| |_|  \\___|\\__\\___|_| |_|");
            printf(WHT "%s\n" RESET, "---------------------------------");
            printf(WHT "%s\n" RESET, "Hey your linux distrobution is not supported, do you mind making a pr adding it to https://github.com/Thamognya/TFetch.git");
        }
        return 0;
    #elif __APPLE__
        /*
                               ___  ____
         _ __ ___   __ _  ___ / _ \/ ___|
        | '_ ` _ \ / _` |/ __| | | \___ \
        | | | | | | (_| | (__| |_| |___) |
        |_| |_| |_|\__,_|\___|\___/|____/
        */
            printf(RED "%s\n" RESET, "                       ___  ____");
            printf(YEL "%s\n" RESET, " _ __ ___   __ _  ___ / _ \\/ ___|");
            printf(GRE "%s\n" RESET, "| '_ ` _ \\ / _` |/ __| | | \\___ \\");
            printf(BLU "%s\n" RESET, "| | | | | | (_| | (__| |_| |___) |");
            printf(MAG "%s\n" RESET, "|_| |_| |_|\\__,_|\\___|\\___/|____/");
        return 0;
    #endif
}
