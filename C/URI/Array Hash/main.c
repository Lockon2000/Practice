#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i , k , j;
    int total , sum , elem , pos ;
    char ch ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d", &k);
        total = 0 ;
        elem = 0 ;
        getchar();

        for (j = 0 ; j < k ; ++j)
        {
            pos = 0 ;

            while ((ch = getchar()) != '\n')
            {
                sum = (ch - 'A') + elem + pos ;
                total += sum ;
                ++pos ;
            }
            ++elem ;
        }
        printf("%d\n", total);
    }
    return 0;
}
