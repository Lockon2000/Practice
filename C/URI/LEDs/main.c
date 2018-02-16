#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, j, sum ;
    char led[102];

    scanf("%d", &i);

    for (n = 0 ; n < i ; ++n)
    {
        scanf("%s", led);

        sum = 0;

        for (j = 0 ; j < strlen(led) ; ++j )
        {
            switch (led[j])
            {
                case '0' : sum += 6;
                            break;
                case '1' : sum += 2;
                            break;
                case '2' : sum += 5;
                            break;
                case '3' : sum += 5;
                            break;
                case '4' : sum += 4;
                            break;
                case '5' : sum += 5;
                            break;
                case '6' : sum += 6;
                            break;
                case '7' : sum += 3;
                            break;
                case '8' : sum += 7;
                            break;
                case '9' : sum += 6;
                            break;
            }
        }

        printf("%d leds\n", sum);
    }
    return 0;
}
