#include <stdio.h>

int main()
{
    short mary, john, n, i, j ;

    while (scanf("%hd", &n) , n != 0)
    {
        mary = john = 0;

        for (i = 0 ; i < n ; ++i)
        {
            scanf("%hd", &j);
            if (j == 0)
                ++mary;
            else
                ++john;
        }

        printf("Mary won %d times and John won %d times\n", mary, john);
    }
    return 0;


}
