#include <iostream>
#include <vector>

using namespace std;

struct interval {
    int start , finish ;
};

bool overlap(interval & , interval &);
void check(vector<interval> &);

int main()
{
    int n , k , total ;
    vector<interval> set ;
    interval session ;
    int size ;

    cin >> n ;

    for (int i = 0 ; i < n ; ++i)
    {
        size = 0 ;
        total = 0 ;

        cin >> k ;

        for (int j = 0 ; j < k ; ++j)
        {
            cin >> session.start >> session.finish ;

            if (set.empty())
            {
                set.push_back(session);
                ++size;
            }
            else
            {
                for (int g = 0 ; g < size ; ++g)
                {
                    if (overlap(session , set[g]))
                    {
                        check(set);
                        size = set.size();
                        break;
                    }
                    else
                    {
                        set.push_back(session);
                        ++size;
                        break;
                    }
                }
            }
        }

        for (int j = 0 ; j < size ; ++j)
        {
            total += set[j].finish - set[j].start ;
        }

        cout << total << '\n' ;

        set.clear();
    }


    return 0;
}

bool overlap(interval & session , interval & previous)
{
    if (previous.start <= session.start && session.start <= previous.finish)
    {
        if (previous.start <= session.finish && session.finish <= previous.finish)
            return true ;
        else
        {
            previous.finish = session.finish ;
            return true ;
        }
    }
    else if (previous.start <= session.finish && session.finish <= previous.finish)
    {
        previous.start = session.start ;
        return true ;
    }
    else if (session.start <= previous.start && previous.finish <= session.finish)
    {
        previous.start = session.start ;
        previous.finish = session.finish ;
        return true ;
    }
    else
        return false ;
}

void check(vector<interval> & set)
{
    int intervals = set.size() ;

again:
    for (int i = 0 ; i < intervals-1 ; ++i)
    {
        for (int j = i+1 ; j < intervals ; ++j)
        {
            if (overlap(set[i],set[j]))
            {
                set.erase(set.begin()+i);
                --intervals;
                goto again ;
            }
        }
    }
}
