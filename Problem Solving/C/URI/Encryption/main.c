#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i, n, j ;
    char line[1001], linerev[1001] ;

    scanf("%d", &i);
    getchar();

    for (n = 0 ; n < i ; ++n)
    {
        gets(line);

        for (j = 0; j < strlen(line) ; ++j )
        {
            if (isalpha(line[j]))
                line[j] += 3;
        }

        for (j = 0 ; j < strlen(line) ; ++j)
        {
            linerev[j] = line[strlen(line)-1-j];
        }
        linerev[j] = '\0';

        j = strlen(linerev) / 2;

        for ( ; j < strlen(linerev) ; ++j)
            linerev[j] -= 1;

        printf("%s\n", linerev);
    }



    return 0;
}
