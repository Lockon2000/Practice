#include <stdio.h>

void one();
void two();
void three();

int main()
{
    printf("starting now\n");
    one();
    printf("done!");

    return 0;
}


void one()
{
    printf("one....\n");
    two();
}

void two()
{
    printf("two....\n");
    three();
}

void three()
{
    printf("three....\n");
}
