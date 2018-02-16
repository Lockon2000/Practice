#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n ;

    cin >> n ;
    getchar();

    for (int i = 0 ; i < n ; ++i)
    {
        stack<char> mine ;
        stack<int> prev_count ;
        bool potent = false ;
        int counter ;
        int result = 0 ;

        while (mine.push(getchar()), mine.top() != '\n')
        {
            if (mine.top() == '<')
            {
                if (potent == false)
                {
                    potent = true ;
                    counter = 0 ;
                }
                else
                {
                    prev_count.push(counter);
                    counter = 0 ;
                }
            }

            if (potent == true)
                ++counter ;

            if (mine.top() == '>' && potent == true)
            {
                for (int j = 0 ; j < counter ; ++j)
                    mine.pop();
                ++result ;
                if (!prev_count.empty())
                {
                    counter = prev_count.top();
                    prev_count.pop();
                }
                else
                    potent = false ;
            }
        }

        cout << result << '\n' ;
    }

    return 0 ;
}
