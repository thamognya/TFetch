#include "./include/logo.h"
#include <stdio.h>

int logo()
{
    #ifdef __linux__
        printf("%s\n", "Temporary");
    #elif __APPLE__
/*
                    'c.        
                 ,xNMM.         
               .OMMMMo           
               OMMM0,            
     .;loddo:' loolloddol;.      
   cKMMMMMMMMMMNWMMMMMMMMMM0:    
 .KMMMMMMMMMMMMMMMMMMMMMMMWd.    
 XMMMMMMMMMMMMMMMMMMMMMMMX.      
;MMMMMMMMMMMMMMMMMMMMMMMM:       
:MMMMMMMMMMMMMMMMMMMMMMMM:       
.MMMMMMMMMMMMMMMMMMMMMMMMX.      
 kMMMMMMMMMMMMMMMMMMMMMMMMWd.    
 .XMMMMMMMMMMMMMMMMMMMMMMMMMMk   
  .XMMMMMMMMMMMMMMMMMMMMMMMMK.   
    kMMMMMMMMMMMMMMMMMMMMMMd     
     ;KMMMMMMMWXXWMMMMMMMk.
       .cooc,.    .,coo:.

*/
        printf("%s\n", "");
    #endif

    return 0;
}
