#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, width, max ;


    while ( scanf("%d", &n),n != 0)
    {
        max = (int) pow(2,2*n - 2);
        if (max < 10)
            width = 1 ;
        else if (max < 100)
            width = 2 ;
        else if (max < 1000)
            width = 3 ;
        else if (max < 10000)
            width = 4 ;
        else if (max < 100000)
            width = 5 ;
        else if (max < 1000000)
            width = 6 ;
        else if (max < 10000000)
            width = 7 ;
        else if (max < 100000000)
            width = 8 ;
        else
            width = 9 ;

        for (i = 0 ; i < n ; ++i)
        {
            for (j = 0 ; j < n - 1 ;  ++j)
                printf("%*d ", width, (int) pow(2, i+j));
            printf("%*d", width, (int) pow(2, i+j));
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
