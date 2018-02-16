#include <stdio.h>

int main()
{
    unsigned short lenth, hight, depth_now, depth_new, turning_ons, n ;

    while (scanf("%hu%hu", &hight, &lenth) , !(hight == 0 && lenth == 0))
    {
        unsigned short colum[lenth];

        depth_now = 0;
        turning_ons = 0;

        for (n = 0 ; n < lenth ; ++n)
        {
            scanf("%hu", &colum[n]);

            depth_new = hight - colum[n];

            if (depth_new > depth_now)
                turning_ons += (depth_new - depth_now);

            depth_now = depth_new;
        }

        printf("%hu\n", turning_ons);

    }


    return 0;
}
