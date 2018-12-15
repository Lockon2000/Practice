#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i , x , y , r ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d%d", &x , &y);
        r = x % y ;

        while (r > 0)
        {
            x = y ;
            y = r ;
            r = x % y ;
        }
        printf("%d\n", y);
    }
    return 0;
}
