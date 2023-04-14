#include <stdio.h>

#define SIZEOF(a) sizeof(a) / sizeof(*a)

int main(void)
{
   int arr[] = {1, 2, 3, 4, 5};
   size_t n = SIZEOF(arr);

   printf("The size of the array is %d", n);

   return 0;
}