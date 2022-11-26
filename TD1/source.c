#include <stdio.h>


int main (int argc , char **argv) {

    #ifdef _POSIX_SOURCE
    printf("_POSIX_SOURCE=%d\n ", _POSIX_SOURCE);
    # endif

    #ifdef _POSIX_C_SOURCE
    printf ("_POSIX_C_SOURCE=%d\n " ,_POSIX_C_SOURCE);
    # endif

    # ifdef _XOPEN_SOURCE
    printf ("_XOPEN_SOURCE=%d\n " ,_XOPEN_SOURCE);
    #endif

    #ifdef _XOPEN_SOURCE_EXTENDED
    printf ("_XOPEN_SOURCE_EXTENDED=%d\n" ,_XOPEN_SOURCE_EXTENDED);
    #endif

    /*if (_POSIX_C_SOURCE == )
        printf ("Code de 2008 inclu ! \ n");
    else
        printf( "Code par defaut \n ");
*/	
    return 0;

}
