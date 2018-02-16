#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i ;
    char a[51] , b[51] ;
    char * ptr1 , * ptr2 ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%s%s", a , b);

        ptr1 = a ;
        ptr2 = b ;

        while ( (*ptr1 != 0) || (*ptr2 != 0) )
        {
            if (*ptr1 != 0)
            {
                putchar(*ptr1);
                ++ptr1 ;
            }

            if (*ptr2 != 0)
            {
                putchar(*ptr2);
                ++ptr2 ;
            }
        }
        putchar('\n');
    }
    return 0;
}
