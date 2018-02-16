#include <stdio.h>

int operation(char, int *);

int main()
{
    char op, discard[1000000] ;
    int ans, check = 10 ;

    while ((op = getchar()) != EOF)
    {
        check = 10 ;

        if (op == EOF)
        {
            printf(("Invalid expression.\n"));
            return 0 ;
        }

        while (op = getchar() , op != '+' && op != '-' && op != '*' && op != '/')
        {
            if (op == EOF)
            {
                printf(("Invalid expression.\n"));
                return 0 ;
            }

            if (op == '0' || op == '1' || op == '2' || op == '3' || op == '4' || op == '5' || op == '6' || op == '7' || op == '8' || op == '9')
            {
                gets(discard);
                printf(("Invalid expression.\n"));
                continue;
            }
        }


        ans = operation(op, &check);

        if (check == 0)
        {
            printf("Division by zero.\n");
            continue;
        }

        printf("The answer is %d.\n", ans);
    }

    return 0;
}

int operation(char op, int * ptr)
{
    int x, y ;
    char op2 ;

    scanf("%d", &x);

    if (scanf("%d", &y) == 0)
    {
        op2 = getchar();
        y = operation(op2, &x);
    }

    if (x == 0)
    {
        *ptr = 0 ;
        return 1 ;
    }

    switch (op)
    {
    case '+': return y + x;
    case '-': return y - x;
    case '*': return y*x;
    case '/': return y/x;
    }

    return 1 ;
}
