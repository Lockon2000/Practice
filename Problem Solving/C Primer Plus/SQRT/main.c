#include <stdio.h>
#include <math.h>

int main()
{
    double num , sqrt , epsilon ;

    printf("Enter The desired Number :");
    scanf("%lf", &num);

    sqrt = 1.0;
    epsilon = 1.0;

    while(epsilon > 0.00001)
    {
        sqrt = (sqrt + num/sqrt) / 2;
        epsilon = fabs(num - sqrt*sqrt);
        printf("\nThe current approximation is %.10f", sqrt);
        printf("\nThe current approximations square is %.10f", sqrt*sqrt);
        printf("\nThe current deviation is %.10f\n", epsilon);
    }
    printf("\nThe estimated square root is %.10f", sqrt);

    getchar();
    getchar();

    return 0;
}
