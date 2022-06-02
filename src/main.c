#include "./include/main.h"
#include "./include/user-host-name.h"
#include <stdio.h>

/*int main(int argc, string argv[])
{
    printf("%s %s\n", "Hello", argv[1]);
    if (argc > 2)
    {
        printf("%s\n", "Why tho?");
    }
    else
    {

    }

	#ifdef __linux__
		printf("%s", hostname());
	#else
		printf("%s\n", "Your OS is not using GNU/linux which as of now is the only os supported, if you would like to expand support do make a pr at https://github.com/ThamognyaKodi/TFetch ; Thank you for trying this program out");
	#endif

	return 0;
}

*/

int main()
{
    hostname();
    username();
    return 0;
}
