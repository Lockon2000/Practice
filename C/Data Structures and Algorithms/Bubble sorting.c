#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    const int n = 1000 ;
    int arr[n];
    int temp ;

//  Initialize
    for (int i = 0 ; i < n ; ++i)
    {
        arr[i] = rand() - rand();
    }

//  Bubble sort
    for (int i = 0 ; i < n - 1 ; ++i)
        for (int j = 0 ; j < n - i - 1 ; ++j)
        {
            if (arr[j] < arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp ;
            }
        }

//  show results
    for (int i = 0 ; i < n ; ++i)
    {
        if (i%6 == 0 && i != 0)
            putchar('\n');
        printf("%6d , ", arr[i]);
    }
    putchar('\n');


    return(0);
}
