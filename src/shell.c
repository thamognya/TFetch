#include "./include/shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int shell()
{
    /*  
	char *shell = getenv("SHELL");
	char *slash = strrchr(shell, '/');
	if (slash) {
		shell = slash + 1;
	}
	shellname = shell;
	return NULL;
	*/
	// got this code from https://github.com/13-CF/afetch/blob/master/src/fetch.c
	char *shell = getenv("SHELL");
	char *slash = strrchr(shell, '/');
	if (slash)
	{
		shell = slash + 1;
	}
	// print the output
	printf(RED "%s" RESET, "SHELL: ");
	printf("%s", shell);
	printf("\n");

    return 0;
}
