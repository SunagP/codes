#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *first;
void input(int n)
{   int i;
    struct node *new,*temp;
    first=(struct node*)malloc(sizeof(struct node));
    printf("data of node 1 : \n");
    scanf("%d",&first->data);
    first->next=NULL;
    temp=first;
    for(i=2;i<=n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data of node %d :\n",i);
        scanf("%d",&new->data);
        new->next=NULL;
        temp->next=new;
        temp=temp->next;
    }
}
void disp()
{
    struct node *temp;
    temp=first;
    int i=1;
    while(temp!=NULL)
    {  // printf("node %d : %u\n",i,temp);
        printf("Node %d data is => %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
   printf("\n\n");
}
void reverseList()
{
    struct node *prevNode, *cur;

   
        prevNode = first;
        cur = first->next;
        first = first->next;

        prevNode->next = NULL; 
        int i=1;
        while(first != NULL)
        {  // printf("itration %d\n",i);
            first = first->next;
            //printf("first = %u\n",first);
            cur->next = prevNode;
           // printf("cur = %u\n",cur);
            prevNode = cur;
           // printf("prevNode = %u\n",prevNode);
            cur = first;
            i++;
        }

        first = prevNode; 

       
    
}
int recRev(struct node* p)
{
    if(p==NULL )
     return p;
    recRev(p->next);
    printf("%d =>",p->data);
    
}

int main()
{
   int n;
   
    printf("Enter num of nodes\n");
    scanf("%d",&n);
    input(n);
    printf("Entered list:\n");
   disp();
    printf("Reversed list:\n");
    recRev(first);
    //reverseList();
    //recRev(first);
    //disp();
}