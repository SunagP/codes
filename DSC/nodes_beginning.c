#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *first;
typedef struct node s;
void insertBeginning();
void traverse(s*n);
int main()
{ int x=1;
   first= (struct node*)malloc(sizeof(struct node));
    
    printf("Enter 1st node \n");
    scanf("%d",&first->data);
    first->next=NULL;
    while(x)
    {
        printf("Enter 1 to add node at the beginning\nEnter 2 to display list\nEnter 0 to exit : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : insertBeginning();
            break;
            case 2 : traverse(first);
            break;
            case 0 : break;
            default : printf("wrong input\n");
            break;
        }
    }


}

void insertBeginning()
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter data of new node : ");
    scanf("%d",&new->data);
    new->next=first;
    first=new;

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