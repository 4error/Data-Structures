//pointer to an array
#include <stdio.h>
int main()
{
   int a[5] = {5, 23, 4, 2, 1};
   int *p;
   p=a; //or p=&a[0];
   
   for (int i = 0; i < 5; i++)
   {
    printf("The value of a[%d] is %d\n", i, *(p+i));
   }

   return 0;
}
   