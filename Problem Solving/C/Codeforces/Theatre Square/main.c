#include <stdio.h>

int main()
{
    long long int n, m ,a ;

    scanf("%I64d%I64d%I64d", &n, &m, &a);

    printf("%I64d\n", ((m+a-1)/a)*((n+a-1)/a));

    return 0;
}
