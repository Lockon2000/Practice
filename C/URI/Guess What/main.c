#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, tnum, snum, dis, cwt ;

    scanf("%d", &n);

    for(i = 0 ; i < n ; ++i)
    {
        scanf("%d%d", &tnum, &snum);
        int team[tnum];

        dis = 101 ;

        for (j = 0 ; j < tnum ; ++j)
        {
            scanf("%d", &team[j]);

            if (abs(team[j] - snum) < dis)
            {
                dis = abs(team[j] - snum) ;
                cwt = j ;
            }
        }

        printf("%d\n", cwt + 1);
    }
    return 0;
}
