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
    case '^':
    case '<':
    case '>':
    case '=':
    case '#':
    case '.':
    case '|':return true ;
    default: return false ;
    }
}

inline int priority(char a)
{
    int pri ;

    switch (a)
    {
    case '|': pri = 0 ;
        break ;
    case '.': pri = 1 ;
        break ;
    case '#': pri = 2 ;
        break ;
    case '=': pri = 2 ;
        break ;
    case '>': pri = 2 ;
        break ;
    case '<': pri = 2 ;
        break ;
    case '-': pri = 3 ;
        break ;
    case '+': pri = 3 ;
        break ;
    case '/': pri = 4 ;
        break ;
    case '*': pri = 4 ;
        break ;
    case '^': pri = 5 ;
        break ;
    }

    return pri ;
}

inline bool lexical(char ch)
{
    if (isalnum(ch))
        return true ;
    else if (ch == '|' || ch == '.' || ch == '#' || ch == '=' || ch == '>' || ch == '<' || ch == '-' ||
              ch == '+' || ch == '/' || ch == '*' || ch == '^' || ch == '(' || ch == ')' || ch == '\n')
        return true ;
    else
        return false ;
}

inline bool syntax(char ch)
{
    static int flag = 0 ;       // dummy first value
                                // first parenthesis after
                                // operand or vice versa 1
                                // operator              2
                                // alphabetical operand  3

    if (isoperator(ch) && flag == 2)
        return false ;

    if (isalpha(ch) && flag == 3)
        return false ;

    if (ch == '(' || ch == ')')
    {
        if (flag != 1)
            flag = 1 ;
        else
            flag = 2 ;
    }
    else if (isoperator(ch))
    {
        if (flag == 1)
            flag = 1 ;
        else
            flag = 2 ;
    }
    else if (isalpha(ch))
        flag = 3 ;
    else
        flag = 0 ;

    return true ;
}


inline void eatline(void)
{
    while (getchar() != '\n')
        continue ;
}

int parenthesis(string &);

bool finished_case = false ;    // dummy first value

int main()
{
    stack<char> op ;
    char ch ;
    string output ;

    while (1)
    {
        while ((ch = getchar()) != '\n')
        {
            if (ch == EOF)
            {
                if (!finished_case)
                {
                    cout << "Syntax Error!\n" ;
                }

                return 0 ;
            }

            if (!lexical(ch))
            {
                eatline();
                cout << "Lexical Error!" ;
                output.clear();
                while (!op.empty())
                    op.pop();
                break ;
            }

            if (!syntax(ch))
            {
                eatline();
                cout << "Syntax Error!" ;
                output.clear();
                while (!op.empty())
                    op.pop();
                break ;
            }

            if (isoperator(ch))
            {
                if (op.empty())
                {
                    op.push(ch);
                }
                else if (priority(ch) <= priority(op.top()))
                {
                    output += op.top() ;
                    op.pop();

                    while (!op.empty())
                    {
                        if (priority(ch) <= priority(op.top()))
                        {
                            output += op.top() ;
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
            {
                int circum = parenthesis(output);
                if (circum == 1)    //lexical error
                {
                    eatline();
                    cout << "Lexical Error!" ;
                    output.clear();
                    while (!op.empty())
                        op.pop();
                    break ;
                }
                else if (circum == 2)   // syntax error
                {
                    eatline();
                    cout << "Syntax Error!" ;
                    output.clear();
                    while (!op.empty())
                        op.pop();
                    break ;
                }
                else if (circum == 3)   // new line syntax error
                {
                    cout << "Syntax Error!" ;
                    output.clear();
                    while (!op.empty())
                        op.pop();
                    break ;
                }
            }
            else
                output += ch ;
        }

        while (!op.empty())
        {
            output += op.top() ;
            op.pop();
        }
        cout << output << '\n' ;

        syntax(ch);         // for resetting purposes
        output.clear();
        finished_case = true ;
    }


    return 0;
}

int parenthesis(string & output_p)
{
    stack<char> op_p ;
    char ch_p ;

    while ((ch_p = getchar()) != ')')
    {
        if (ch_p == EOF)
        {
            cout << "Syntax Error!\n" ;

            exit(0) ;
        }

        if (!lexical(ch_p))
            return 1 ;

        if (!syntax(ch_p))
            return 2 ;

        if (ch_p == '\n')
            return 3 ;

        if (isoperator(ch_p))
        {
            if (op_p.empty())
            {
                op_p.push(ch_p);
            }
            else if (priority(ch_p) <= priority(op_p.top()))
            {
                output_p += op_p.top() ;
                op_p.pop();

                while (!op_p.empty())
                {
                    if (priority(ch_p) <= priority(op_p.top()))
                    {
                        output_p += op_p.top() ;
                        op_p.pop();
                    }
                    else
                        break ;
                }
                op_p.push(ch_p);
            }
            else
            {
                op_p.push(ch_p);
            }
        }
        else if (ch_p == '(')
            parenthesis(output_p);
        else
            output_p += ch_p ;
    }

    while (!op_p.empty())
    {
        output_p += op_p.top() ;
        op_p.pop();
    }

    return 0 ;
}
