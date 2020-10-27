#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1 , b = 2 , c = 3 , d = 4 , e = 5 , f = 6 , g = 7 ;

    g = ( f =  b , e = a + ++b );

    printf("\n\n a = %d , b = %d , c = %d , d = %d , e = %d , f = %d , g = %d\n\n", a,b,c,d,e,f,g);


    return 0;
}
