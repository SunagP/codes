#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *first;
typedef struct node s;
void insert();
void add();
void traverse(s*n);
void insert_after_value();
int main()
{ int x;
   first= (struct node*)malloc(sizeof(struct node));
    
    printf("Enter 1st node \n");
    scanf("%d",&first->data);
    first->next=NULL;
    while(x!=-1)
    {

        printf("Enter 1 to add node\nEnter 2 to insert a node at any position\nEnter 3 to insert after a value\nEnter -1 to terminate and display: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : add();
            break;
            case 2 : insert();
         break;
             case 3 : insert_after_value();
             break;
            case -1 : break;
            default : printf("invalid\n");
            break;
        }
    }

  traverse(first);
  return 0;
}
void insert_after_value()
{
    struct node *new ,*ptr;
    ptr=first;
   // preptr=first;
    int val ,num;

    printf("Enter data after which you want to add new data\n");
    scanf("%d",&val);
    printf("Enter new data\n");
    scanf("%d",&num);
    new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    new->next=ptr->next;
    ptr->next=new;

}
void add()
{
    struct node *new,*temp;
    temp=first;
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("enter data of new node : ");
    scanf("%d",&new->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
}
void insert()
{
    struct node *temp,*new;
    int len=1,pos,i=1;
    temp=first;
    while(temp->next!=NULL)   
    {
        temp=temp->next;
        len++;
    }
    printf("enter the position to insert new node : ");
    scanf("%d",&pos);
    if(pos<1||pos>len+1)
    {
        printf("invalid position\n");
    }
    else if(pos==1)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        printf("enter data of new node : ");
        scanf("%d",&new->data);
        new->next=first;
        first=new;
    }
    else
    {
        temp=first;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
            
        }
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter data of new node : ");
        scanf("%d",&new->data);
        new->next=temp->next;
        temp->next=new;
    }
    
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