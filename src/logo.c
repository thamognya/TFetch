#define _POSIX_C_SOURCE 200809L
#include "./include/logo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// get colors
#include "./include/color.h"
#include "./include/extra_functions.h"

// good idea from https://github.com/13-CF/afetch/blob/master/src/fetch.c


void logo()
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
				char osname[512];
				char oscontent[512];
				get_linux_distro(oscontent, osname);
        // using strncmp as it can define the number of charecters
        if (strncmp(osname, "Gentoo", 6) == 0) 
        {
            /*
              ____            _
             / ___| ___ _ __ | |_ ___   ___
            | |  _ / _ \ '_ \| __/ _ \ / _ \
            | |_| |  __/ | | | || (_) | (_) |
             \____|\___|_| |_|\__\___/ \___/
            */
            printf(MAG "%s\n" RESET, "  ____            _");
            printf(MAG "%s\n" RESET, " / ___| ___ _ __ | |_ ___   ___");
            printf(MAG "%s\n" RESET, "| |  _ / _ \\ '_ \\| __/ _ \\ / _ \\");
            printf(MAG "%s\n" RESET, "| |_| |  __/ | | | || (_) | (_) |");
            printf(MAG "%s\n" RESET, " \\____|\\___|_| |_|\\__\\___/ \\___/");
        }
        else if (strncmp(osname, "Arch", 4) == 0)
        {
            /*
                _             _
               / \   _ __ ___| |__
              / _ \ | '__/ __| '_ \
             / ___ \| | | (__| | | |
            /_/   \_\_|  \___|_| |_|
            */
            printf(BLU "%s\n" RESET, "    _             _");
            printf(BLU "%s\n" RESET, "   / \\   _ __ ___| |__");
            printf(BLU "%s\n" RESET, "  / _ \\ | '__/ __| '_ \\");
            printf(BLU "%s\n" RESET, " / ___ \\| | | (__| | | |");
            printf(BLU "%s\n" RESET, "/_/   \\_\\_|  \\___|_| |_|");
        }
        else if (strncmp(osname, "Debian GNU/Linux", 16) == 0)
        {
            /*
 ____       _     _
|  _ \  ___| |__ (_) __ _ _ __
| | | |/ _ \ '_ \| |/ _` | '_ \
| |_| |  __/ |_) | | (_| | | | |
|____/ \___|_.__/|_|\__,_|_| |_|
            */
            printf(RED "%s\n" RESET, " ____       _     _");
            printf(RED "%s\n" RESET, "|  _ \\  ___| |__ (_) __ _ _ __");
            printf(RED "%s\n" RESET, "| | | |/ _ \\ '_ \\| |/ _` | '_ \\");
            printf(RED "%s\n" RESET, "| |_| |  __/ |_) | | (_| | | | |");
            printf(RED "%s\n" RESET, "|____/ \\___|_.__/|_|\\__,_|_| |_|");
        }
        else if (strncmp(osname, "EndeavourOS", 11) == 0)
        {
            /*
  ______           _                                   ____   _____
 |  ____|         | |                                 / __ \ / ____|
 | |__   _ __   __| | ___  __ ___   _____  _   _ _ __| |  | | (___
 |  __| | '_ \ / _` |/ _ \/ _` \ \ / / _ \| | | | '__| |  | |\___ \
 | |____| | | | (_| |  __/ (_| |\ V / (_) | |_| | |  | |__| |____) |
 |______|_| |_|\__,_|\___|\__,_| \_/ \___/ \__,_|_|   \____/|_____/
            */
            printf(MAG "%s\n" RESET, " ______           _                                   ____   _____");
            printf(MAG "%s\n" RESET, "|  ____|         | |                                 / __ \\ / ____|");
            printf(MAG "%s\n" RESET, "| |__   _ __   __| | ___  __ ___   _____  _   _ _ __| |  | | (___");
            printf(MAG "%s\n" RESET, "|  __| | '_ \\ / _` |/ _ \\/ _` \\ \\ / / _ \\| | | | '__| |  | |\\___ \\");
            printf(MAG "%s\n" RESET, "| |____| | | | (_| |  __/ (_| |\\ V / (_) | |_| | |  | |__| |____) |");
            printf(MAG "%s\n" RESET, "|______|_| |_|\\__,_|\\___|\\__,_| \\_/ \\___/ \\__,_|_|   \\____/|_____/");
        }
        else
        {
            printf(WHT "%s\n" RESET, " _____ _____    _       _");
            printf(WHT "%s\n" RESET, "|_   _|  ___|__| |_ ___| |__");
            printf(WHT "%s\n" RESET, "  | | | |_ / _ \\ __/ __| '_ \\");
            printf(WHT "%s\n" RESET, "  | | |  _|  __/ || (__| | | |");
            printf(WHT "%s\n" RESET, "  |_| |_|  \\___|\\__\\___|_| |_|");
            printf(WHT "%s\n" RESET, "---------------------------------");
            printf(WHT "%s\n" RESET, "Hey your linux distribution is not supported, do you mind making a pr adding it to https://github.com/Thamognya/TFetch.git");
        }
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
    #else
        printf(WHT "%s\n" RESET, " _____ _____    _       _");
        printf(WHT "%s\n" RESET, "|_   _|  ___|__| |_ ___| |__");
        printf(WHT "%s\n" RESET, "  | | | |_ / _ \\ __/ __| '_ \\");
        printf(WHT "%s\n" RESET, "  | | |  _|  __/ || (__| | | |");
        printf(WHT "%s\n" RESET, "  |_| |_|  \\___|\\__\\___|_| |_|");
        printf(WHT "%s\n" RESET, "---------------------------------");
        printf(WHT "%s\n" RESET, "Hey your OS is not supported, do you mind making a pr adding it to https://github.com/Thamognya/TFetch.git");
    #endif
}
