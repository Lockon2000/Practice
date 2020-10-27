/* typesize.c -- prints out type sizes */
#include <stdio.h>
int main(void)
{
    printf("Type int has a size of %zd bytes.\n"
           "Type short has a size of %zd bytes\n", sizeof(int), sizeof(short));
    printf("Type char has a size of %zd bytes.\n"
           "Type long has a size of %zd bytes.\n"
           "type long long has a size of %zd bytes.\n"
           "Type float has a size of %zd bytes.\n"
           "Type double has a size of %zd bytes.\n"
           "Type long double has a size of %zd bytes.\n"
           , sizeof(char), sizeof(long), sizeof(long long), sizeof(float), sizeof(double), sizeof(long double));

    int var;
    printf("\n\nThe variable var has a size of %zd bytes.\n", sizeof(var));

    return 0;
}
