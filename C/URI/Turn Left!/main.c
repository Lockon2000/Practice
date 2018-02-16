#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, n, i ;
    char c ;

    while (scanf("%d", &n ), n != 0)
    {
        a = 0 ;
        getchar();
        for (i = 0 ; i < n ; ++i)
        {
            c = getchar();
            if (c == 'E')
                --a;
            else
                ++a;
        }

        i = a % 4 ;
        if (i == 0)
            putchar('N');
        else if (i == 1)
            putchar('L');
        else if (i == 2)
            putchar('S');
        else if (i == 3)
            putchar('O');
        else if (i == -1)
            putchar('O');
        else if (i == -2)
            putchar('S');
        else if (i == -3)
            putchar('L');

            putchar('\n');
    }
    return 0;
}
