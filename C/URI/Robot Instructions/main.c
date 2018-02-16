#include <stdio.h>

int main()
{
    int n, i, j, ins_num, x, a ;
    char ch ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d", &ins_num);
        getchar();

        x = 0;

        int ins[ins_num];

        for (j = 0 ; j < ins_num ; ++j)
        {
            ch = getchar() ;

            if (ch == 'L')
            {
                x -= 1;
                ins[j] = -1;
                while (getchar() != '\n')
                    continue ;
            }
            else if (ch == 'R')
            {
                x += 1;
                ins[j] = 1;
                while (getchar() != '\n')
                    continue ;
            }
            else
            {
                scanf("%*s%*s%d", &a);
                x += ins[a - 1];
                ins[j] = ins[a - 1];
                getchar();
            }
        }
        printf("%d\n", x);
    }

    return 0;
}
