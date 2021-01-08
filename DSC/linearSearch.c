#include <stdio.h>
#include <stdlib.h>

int linear(int*, int, int);

int main()
{
   int key, i, n, position;

   printf("Enter the number of elements in array\n");
   scanf("%d",&n);
   int array[n];
   printf("Enter %d numbers\n",n);

   for ( i = 0 ; i < n ; i++ )
      scanf("%d",&array[i]);

   printf("Enter the number to search\n");
   scanf("%d",&key);

   position = linear(array, n, key);

   if ( position == -1 )
      printf("%d is not present in array.\n", key);
   else
      printf("%d is present at position %d.\n", key, position+1);

   return 0;
}

int linear(int *p, int n, int find)
{
   int i;

   for ( i = 0 ; i < n ; i++ )
   {
      if ( i[p] == find )

         return i;
   }

   return -1;
}
