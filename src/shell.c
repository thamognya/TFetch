#include "./include/shell.h"
#include <stdio.h>
#include <stdlib.h>

int shell()
{
  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = fopen("echo $0");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
  }

  /* close */
  fclose(fp);

    return 0;
}
