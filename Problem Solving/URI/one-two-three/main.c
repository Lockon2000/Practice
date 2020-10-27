#include <stdio.h>
#include <string.h>

int main()
{
    int i, n ;
    char word[6];

    scanf("%d", &i);

    for (n = 0; n < i ; ++n)
    {
        scanf("%s", word);

        if (strlen(word) == 5)
            printf("3\n");
        else
            if (word[0] == 'o' && word [1] == 'n')
                printf("1\n");
            else
                if (word[1] == 'n' && word[2] == 'e')
                    printf("1\n");
                else
                    if(word[0] == 'o' && word[2] == 'e')
                        printf("1\n");
                    else
                        printf("2\n");
    }
    return 0;
}
