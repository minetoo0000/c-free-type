#include "cobject.h"

int main( int argc, char* args[] )
{
    for ( int i=0; i<argc; i++ )
    {
        printf("\n");
        printf(args[i]);
    }
    
    getchar();
    return( 0 );
}