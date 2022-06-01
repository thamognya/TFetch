//#define _GNU_SOURCE
//#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include "user-host-name.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int hostname()
{
	char hostname[HOST_NAME_MAX+1];
	gethostname(hostname, HOST_NAME_MAX+1);
	// will change this later
	printf("Hostname: %s\n", hostname);
  	return EXIT_SUCCESS;
}

int username()
{
	char *buf;
	buf=(char *)malloc(10*sizeof(char));
	buf=getlogin();
	printf("Username: %s\n",buf);
	return 0;
}
