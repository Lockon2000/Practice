#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;

    printf("Please enter a Number between 0 and 127 :");
    scanf("%d", &ch);
    printf("\nThe number you enterd (%d) correspondes to the ASCII symbole %c\n\n", ch, ch);

    getchar();
    getchar();

    return 0;
}
