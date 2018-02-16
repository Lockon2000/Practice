#include <stdio.h>

int main()
{
    char ch ;
    int count = 0 ;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '(')
            ++count ;
        else if (ch == ')')
            --count ;
        else if (ch == '\n')
        {
            if (count != 0)
                printf("incorrect\n");
            else
                printf("correct\n");

            count = 0 ;
            continue ;
        }

        if (count < 0)
        {
            while (getchar() != '\n')
                continue ;
            printf("incorrect\n");
            count = 0 ;
            continue ;
        }
    }

    return 0;
}
