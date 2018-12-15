#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char *);
int factorial(int);

int main()
{
    char num[6];
    int length ;
    int sum ;

    while (scanf("%s", num), num[0] != '0')
    {
        sum = 0 ;
        length = strlen(num);

        for (int i = 0 ; i < length ; i++)
        {
            sum += convert(num[i]) * factorial(length - i);
        }

    }

    return 0;
}

int convert(char * ptr)
{

}

int factorial(int i)
{
    int fact = 0 ;

    if ( i == 0)
        return 0 ;
    else
        for ( ; i == 0 ; --i)
        {
            fact *= i ;
        }

    return fact
}
