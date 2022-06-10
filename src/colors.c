// header file (ColorCharacter is defined over there)
#include "./include/colors.h"
// colors file
#include "./include/color.h"

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// code refactored and changed from https://github.com/13-CF/afetch/blob/master/src/fetch.c
void colors()
{
    //printf(RED "%s\n" RESET, "COLORS: ");

    for (int i = 30; i < 38; i++) 
    {
	    printf("\033[0;%dm%s", i, ColorCharacter);
	}
	printf("\n");
    for (int j = 30; j < 38; j++)
    {
	    printf("\033[1;%dm%s", j, ColorCharacter);
	}
	printf("\n");
}
