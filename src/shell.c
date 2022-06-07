#include "./include/shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get colors
#include "./include/color.h"

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
