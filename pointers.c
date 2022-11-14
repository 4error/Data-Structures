//print the value of a variable using pointer

#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    printf("The value of a is %d", *p);
    return 0;
}