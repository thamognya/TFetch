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


/*
fdskfjfkjdklsfd
f
sf
dsfdsfdsafdsfd
fdsf
fdsfds
dsfd
df
sfad
fds
fds
fd
fdsf
das
fdafsf
dsf
dsf
asdf
dsfads

f
df
dsf

ds
fdsfds
f
sfd
f
sfdsaf
df
s

dsfdasfdsufidsufdsfhjdsklfj
sdf
ds
fds
af
dfsfasf
dfasf
ds
f
sdf
dsfa
dfs
dfdfasdfsdf
dsf
dsf
dsf
sdf
ds
dsf
s
*/
	
	return 0;
}