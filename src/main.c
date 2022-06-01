#include "main.h"
#include "user-host-name.h"
#include <stdio.h>

int main()
{
	#ifdef __linux__
		printf("%s", hostname());
	#else
		printf("%s\n", "Your OS is not using GNU/linux which as of now is the only os supported, if you would like to expand support do make a pr at https://github.com/ThamognyaKodi/TFetch ; Thank you for trying this program out");
	#endif
	return 0;
}