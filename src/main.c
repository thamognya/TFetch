#include "./include/main.h"
// get functions hostname() and username()
#include "./include/user-host-name.h"
// get functions uptime()
#include "./include/uptime.h"
// get functions os()
#include "./include/os.h"
// get the functions in line-break
#include "./include/line-break.h"
// get the functions shell()
#include "./include/shell.h"
// get kernel()
#include "./include/kernel.h"
// get memeory()
#include "./include/memory.h"
// get colors()
#include "./include/colors.h"
// get color
#include "./include/color.h"
// get logo
#include "./include/logo.h"
// new line ()
#include "./include/newline.h"
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
    // if the os is windows then print error message else continue cause I hate windows
    #ifdef _WIN32
        printf(RED "%s\n" RESET, "ERROR: This does not work on windows. If you would like to contribute to make this work make a pr or issue request in https://github.com/ThamognyaKodi/TFetch");
        return 1;
    #else
        newline();
        username_hostname(); // user name @ hostname
        linebreak(); // -----
        logo(); // get logo 
        linebreak(); // ----- 
        os(); // the os
        kernel(); // the kernel
        uptime(); // uptime
        shell(); // shell used
        memory(); // memeory (free / total)
        linebreak(); // -----
        colors(); // colors
        newline();

        return 0;
    #endif
}
