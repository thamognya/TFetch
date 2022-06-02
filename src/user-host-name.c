//#define _GNU_SOURCE
//#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include "./include/user-host-name.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int hostname()
{
	#ifdef __linux__
		char hostname[HOST_NAME_MAX+1];
		gethostname(hostname, HOST_NAME_MAX+1);
		printf("Hostname: %s\n", hostname);
	#elif __APPLE__
		int HOST_NAME_MAX = 1024; // for mac only
		char hostname[HOST_NAME_MAX+1];
		gethostname(hostname, HOST_NAME_MAX+1);
		printf("Hostname: %s\n", hostname);
	#endif

  	return EXIT_SUCCESS;
}

int username()
{
	#ifdef __linux__
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf("Username: %s\n", username);
	#elif __APPLE__
		int LOGIN_NAME_MAX = 1024; // for mac only
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf("Username: %s\n", username);
	#endif

  	return EXIT_SUCCESS;
}
