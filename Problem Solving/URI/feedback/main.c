#include <stdio.h>

int main()
{
    int n, k, i, j, team ;

    scanf("%d", &n);

    for (i = 0 ; i < n ; ++i)
    {
        scanf("%d", &k);
        for (j = 0 ; j < k ; ++j)
        {
            scanf("%d", &team);
            switch (team)
            {
            case 1 : printf("Rolien\n");
                     break;
            case 2 : printf("Naej\n");
                     break;
            case 3 : printf("Elehcim\n");
                     break;
            case 4 : printf("Odranoel\n");
                     break;
            }
        }
    }
    return 0;
}
