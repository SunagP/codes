#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *first;
typedef struct node s;
void traverse(s*n);
void minimum();
void inputs(int n)
{
     s *temp,*new;
     int i;
    
    first= (struct node*)malloc(sizeof(struct node));
    
    printf("Enter 1st node \n");
    scanf("%d",&first->data);
    first->next=NULL;
    temp=first;
    for(i=1;i<n;i++)
    {  
        new= (struct node*)malloc(sizeof(struct node));
        printf("Enter %d node \n",i+1);
        scanf("%d",&new->data);
        new->next=NULL;
       temp->next = new;
       temp = temp->next;
    }

}

int main()
{
    int n;

    printf("Enter number of elements\n");
    scanf("%d",&n);
    inputs(n);
    traverse(first);
    minimum();

    return 0;

}
void traverse(s *n)
{   //iterating over all the nodes untill last node
    int i=1;
    printf("Entered elements are\n");
    while(n!=NULL)
    {   printf("Node %d data : %d\n",i,n->data);
       // printf("%d ",n->data);
        n=n->next;
        i++;
    }
}
void minimum()
{ int min= first;
    while(first!=NULL)
    { 
        //printf("%d ",n->data);
        if(min < first->data)
        {
            min=min;
        }
        else
        {
            min = first->data;
        }
        
        first = first->next;
       
    }
     printf("\nMinimum value is : %d\n\n\n",min);
}