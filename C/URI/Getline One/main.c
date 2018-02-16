#include <stdio.h>

int main()
{
    int sum = 0, n = 0 ;
    int local_avrg ;
    double total_avrg ;
    char name[50];

    while (gets(name) , scanf("%d", &local_avrg) != EOF)
    {
        sum += local_avrg ;
        ++n;
        getchar();
    }

    total_avrg = (double) sum / n;

    printf("%.1f\n", total_avrg);

    return 0;
}
