#include <iostream>
#include <stack>

using namespace std;

inline bool isoperator(char a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^': return true ;
    default: return false ;
    }
}

inline int priority(char a)
{
    int pri ;

    switch (a)
    {
    case '+': pri = 0 ;
            break ;
    case '-': pri = 0 ;
            break ;
    case '*': pri = 1 ;
            break ;
    case '/': pri = 1 ;
            break ;
    case '^': pri = 2 ;
            break ;
    }

    return pri ;
}

void parenthesis(void);

int main()
{
    int n ;
    cin >> n ;
    getchar();

    stack<char> op ;
    char ch ;

    for (int i = 0 ; i < n ; ++i)
    {
        while ((ch = getchar()) != '\n')
        {
            if (isoperator(ch))
            {
                if (op.empty())
                {
                    op.push(ch);
                }
                else if (priority(ch) <= priority(op.top()))
                {
                    putchar(op.top());
                    op.pop();

                    while (!op.empty())
                    {
                        if (priority(ch) <= priority(op.top()))
                        {
                            putchar(op.top());
                            op.pop();
                        }
                        else
                            break ;
                    }
                    op.push(ch);
                }
                else
                {
                    op.push(ch);
                }
            }
            else if (ch == '(')
                parenthesis();
            else
                putchar(ch);
        }

        while (!op.empty())
        {
            putchar(op.top());
            op.pop();
        }
        putchar('\n');
    }


    return 0;
}

void parenthesis(void)
{
    stack<char> oper ;
    char che ;

    while ((che = getchar()) != ')')
    {
        if (isoperator(che))
        {
            if (oper.empty())
            {
                oper.push(che);
            }
            else if (priority(che) <= priority(oper.top()))
            {
                putchar(oper.top());
                oper.pop();

                while (!oper.empty())
                {
                    if (priority(che) <= priority(oper.top()))
                    {
                        putchar(oper.top());
                        oper.pop();
                    }
                    else
                        break ;
                }
                oper.push(che);
            }
            else
            {
                oper.push(che);
            }
        }
        else if (che == '(')
            parenthesis();
        else
            putchar(che);
    }

    while (!oper.empty())
    {
        putchar(oper.top());
        oper.pop();
    }
}
