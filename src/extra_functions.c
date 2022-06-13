#define _POSIX_C_SOURCE 200809L
// external functions to be used in other files that are not the primary function.
#include "./include/extra_functions.h"
// always define this
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

char *get_shell_output(const char *command, char *returnOutput) // get output of shell command not to use for shell env as it is done by /bin/sh
{
    FILE *output = popen(command, "r");
    if (output == NULL)
    {
        return NULL;
    }
    else
    {
        const int scanf_return = fscanf(output, "%[^\n]256s", returnOutput);
        pclose(output);
        if (scanf_return == EOF)
        {
            fprintf(stderr, "Error: Scanf Failed sucks to be you");
            exit(EXIT_FAILURE);
        }
        else
        {
            return returnOutput;
        }
    }
}

// since this specific part is getting reused a lot I am going to make a function here to not copy paste that much
char *get_linux_distro(char *oscontent, char *osname)
{
    struct utsname uts;
    uname(&uts);
    int line = 0;
    FILE *f = fopen("/etc/os-release", "rt");
    if (f == NULL || oscontent == NULL)
    {
        return NULL;
    }
    else
    {
        while (fgets(oscontent, 512, f))
        {
            snprintf(osname, 512, "%.*s", 511, oscontent + 4);
            if (strncmp(osname, "=", 1) == 0)
            {
                break;
            }
            line++;
        }
        fclose(f);
        if (strncmp(osname, "=", 1) == 0)
        {
            int len = strlen(osname);
            for (int i = 0; i < len; i++)
            {
                if (osname[i] == '\"' ||
                    osname[i] == '=')
                {
                    for (int ii = 0; ii < len; ii++)
                        osname[ii] =
                            osname[ii + 1];
                    osname[strlen(osname) - 1] = '\0';
                }
            }
        }
        return osname;
    }
}
