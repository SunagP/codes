#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,*ptr,sum=0;
    printf("Enter num of elements\n");
    scanf("%d",&n);

    ptr = (int*) malloc(n * sizeof(int));

    if(ptr==NULL)
    { printf("no memory allocated\n");
    exit(0);
    }
    else
    printf("Enter %d elements\n",n);
    {
        for(i=0;i<n;i++)
        {
        scanf("%d",ptr+i);
        }
     printf(" entered numbers are\n");
        for(i=0;i<n;i++)
        {
           
           // printf("%d ",*(ptr+i));
           // printf("%d ",ptr[i]);
            printf("%d ",i[ptr]);
        }
       
    }



    return 0;
}
