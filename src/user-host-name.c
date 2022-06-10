//#define _GNU_SOURCE
//#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include "./include/user-host-name.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
// get colors
#include "./include/color.h"

int username_hostname()
{
	// if linux then just use HOST_NAME_MAX else for macos use 1024
	#ifdef __linux__
		// get hostname
		char hostname[HOST_NAME_MAX+1];
		gethostname(hostname, HOST_NAME_MAX+1);
		// get the username
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf(BLU "%s" RESET, username);
		printf("@");
		printf(BLU "%s" RESET, hostname);
		printf("\n");
  		return EXIT_SUCCESS;
	#elif __APPLE__
		// get hostname
		int HOST_NAME_MAX = 1024; // for mac only
		char hostname[HOST_NAME_MAX+1];
		gethostname(hostname, HOST_NAME_MAX+1);
		// get the username
		int LOGIN_NAME_MAX = 1024; // for mac only
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf(BLU "%s" RESET, username);
		printf("@");
		printf(BLU "%s" RESET, hostname);
		printf("\n");
  		return EXIT_SUCCESS;
  	#else
        printf("%s\n", "Your OS is not supported. Please make a pr at https://github.com/Thamognya/TFetch");
        return 1;
	#endif

}

/*
int username()
{
	// if linux then just use LOGIN_NAME_MAX else for macos use 1024
	#ifdef __linux__
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf("USERNAME: %s\n", username);
	#elif __APPLE__
		int LOGIN_NAME_MAX = 1024; // for mac only
		char username[LOGIN_NAME_MAX+1];
		getlogin_r(username, LOGIN_NAME_MAX+1);
		printf("USERNAME: %s\n", username);
	#endif

  	return EXIT_SUCCESS;
}
*/
