#include <stdio.h>

int main()
{
    int x , y , a , b , r ;

    int z ;
    scanf("%d", &z);

    for (int u = 0 ; u < z ; ++u)
    {
        scanf("%d%d", &x , &y );
        a = x ;
        b = y ;
        r = x % y ;

        while (r > 0 )
        {
            a = b ;
            b = r ;
            r = a % b ;
        }

        printf("\nthe G.C.D of %d and %d is %d\n", x , y , b );
    }

    return 0;
}
