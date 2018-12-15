#include <stdio.h>
#include <stdlib.h>

int main()
{
    float weight;
    float value;

    printf("Are You worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");

    scanf("%f", &weight);

    value = 1700.0 * weight * 14.5833;
    printf("your weight in platinum is worth $%.2f.\n", value);

    getchar(); // these are to stop the program form closing instantly the number is for the first one being demised
    getchar();

    return 0;
}
