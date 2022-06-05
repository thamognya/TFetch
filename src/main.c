#include "./include/main.h"
// get functions hostname() and username()
#include "./include/user-host-name.h"
// get functions uptime()
#include "./include/uptime.h"
// get functions os()
#include "./include/os.h"
// get the functions in line-break
#include "./include/line-break.h"
// standard library
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
    // if the os is windows then print error message else continue
    #ifdef _WIN32
        printf("%s\n", "This does not work on windows. If you would like to contribute to make this work make a pr or issue request in https://github.com/ThamognyaKodi/TFetch");
    #else
        username_hostname();
        linebreak();
        os();
        uptime();
    #endif

    return 0;
}
