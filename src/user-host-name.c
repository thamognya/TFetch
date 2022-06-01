#include "user-host-name.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char hostname()
{
	char hostname[_SC_HOST_NAME_MAX + 1];
	gethostname(hostname, _SC_HOST_NAME_MAX + 1);
	
	return hostname;
}