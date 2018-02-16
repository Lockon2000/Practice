#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct person {
    int number ;
    int timezone ;
    int partner ;
    int timediff ;
};

int main()
{
    bool finished = false ;

    int n ;
    cin >> n ;

    vector<person> lovers(n) ;
    {
        int j = 0 ;
        for (person & i: lovers)
        {
            i.number = j++ ;
            cin >> i.timezone ;
            i.timediff = 24 ;
        }
    }

    while (!finished)
    {
        finished = true ;
        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = 0 ; j < n ; ++j)
            {
                int mini ;

                if (lovers[i].timediff == 0)
                {
                    continue ;
                }

                if (j == lovers[i].number)
                {
                    continue ;
                }
                else if ((mini = min(abs(lovers[i].timezone - lovers[j].timezone) , 24 - abs(lovers[i].timezone - lovers[j].timezone))) < lovers[i].timediff)
                {
                    if (lovers[j].partner == 0)
                    {
                        if (lovers[i].partner == 0)
                        {
                            lovers[i].partner = j + 1 ;
                            lovers[j].partner = i + 1 ;
                            lovers[i].timediff = lovers[j].timediff = mini ;
                            finished = false ;
                        }
                        else
                        {
                            int k = lovers[i].partner - 1 ;
                            lovers[k].partner = 0 ;
                            lovers[k].timediff = 24 ;
                            lovers[i].partner = j + 1 ;
                            lovers[j].partner = i + 1 ;
                            lovers[i].timediff = lovers[j].timediff = mini ;
                            finished = false ;
                        }

                    }
                    else
                    {
                        if (mini < lovers[j].timediff)
                        {
                            if (lovers[i].partner == 0)
                            {
                                lovers[i].partner = j + 1 ;
                                lovers[j].partner = i + 1 ;
                                lovers[i].timediff = lovers[j].timediff = mini ;
                                finished = false ;
                            }
                            else
                            {
                                int k = lovers[i].partner - 1 ;
                                lovers[k].partner = 0 ;
                                lovers[k].timediff = 24 ;
                                lovers[i].partner = j + 1 ;
                                lovers[j].partner = i + 1 ;
                                lovers[i].timediff = lovers[j].timediff = mini ;
                                finished = false ;
                            }
                        }
                    }
                }
            }
        }
    }

    int total = 0 ;

    vector<int> indiv(n) ;          // could be replaced by number member in struct person.
    {
        int k = 0 ;
        for (int & i: indiv)
            i = k++ ;
    }

    for (int i = 0 ; i < n ; ++i)
    {
        if (indiv[i] != -1)
            indiv[lovers[i].partner - 1] = -1 ;
    }
    int u = 0 ;
    for (person i:lovers)
    {
        if (indiv[u++] != -1)
        {
            total += i.timediff ;
        }
    }
    cout << total << '\n' ;

    int t = 0 ;
    for (person i:lovers)
    {
        cout << "lovers[" << t << "].timezone = " << i.timezone << '\n' ;
        cout << "lovers[" << t << "].partner = " << i.partner << '\n' ;
        cout << "lovers[" << t << "].timediff = " << i.timediff << '\n' ;
        cout << '\n' ;
        ++t;
    }

    return 0;
}
