#define _POSIX_C_SOURCE 200809L
#include "./include/line-break.h"
#include "../config/config.h"
#include <stdio.h>
// get colors
#include "./include/color.h"

void linebreak()
{
    // print the line break
    printf(BMAG "------------" RESET "\n");
}
