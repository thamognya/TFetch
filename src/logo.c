#include "./include/logo.h"
#include <stdio.h>
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
        return 0;
    #elif __APPLE__
        /*
                               ___  ____
         _ __ ___   __ _  ___ / _ \/ ___|
        | '_ ` _ \ / _` |/ __| | | \___ \
        | | | | | | (_| | (__| |_| |___) |
        |_| |_| |_|\__,_|\___|\___/|____/
        */
        printf("%s\n", "                       ___  ____");
        printf("%s\n", " _ __ ___   __ _  ___ / _ \\/ ___|");
        printf("%s\n", "| '_ ` _ \\ / _` |/ __| | | \\___ \\");
        printf("%s\n", "| | | | | | (_| | (__| |_| |___) |");
        printf("%s\n", "|_| |_| |_|\\__,_|\\___|\\___/|____/");
        return 0;
    #endif
}
