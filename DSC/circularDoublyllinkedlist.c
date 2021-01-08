#include<stdio.h>
#include<stdlib.h>

struct node
{
   struct node *prev;
   int data;
   struct node *next; 
}*head;
void disp()
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
   
}
void create()
{   int i,n;
struct node *new;
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    head = (struct node*)malloc(sizeof(struct node));
    head->prev= NULL ;
    printf("Enter the data of node 1\n");
    scanf("%d",&head->data);
    head->next=NULL;
    struct node *temp=head;
    for(i=2;i<=n;i++)
    {
     new= (struct node*)malloc(sizeof(struct node));  
  
    printf("Enter the data of node %d\n",i);
    scanf("%d",&new->data); 
    new->prev=temp;
    new->next=NULL;
    temp->next=new;
    temp=new;
 }
 temp->next=head;
 head->prev=temp;


}
void insertBegin()
{
  if(head==NULL)
  {
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->prev= NULL ;
    printf("Enter the data to insert at the beginning \n");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new; 
  } 
  else
  {
      
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        struct node *new= (struct node*)malloc(sizeof(struct node));
        new= (struct node*)malloc(sizeof(struct node));
        new->prev= NULL ;
        printf("Enter the data to insert at the beginning\n");
        scanf("%d",&new->data);
        new->next=head;
        temp->next=new;
        new->prev=temp;
        head->prev=new;
        //head->next=NULL;
        head=new;  
      
  }
  
}
void insertEnd()
{
  if(head==NULL)
  {
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->prev= NULL ;
    printf("Enter the data to insert at the beginning \n");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new; 
  } 
  else
  {
      
        struct node *temp=head;
        struct node *new= (struct node*)malloc(sizeof(struct node));
        new= (struct node*)malloc(sizeof(struct node));
        new->prev= NULL ;
        printf("Enter the data to insert at the end\n");
        scanf("%d",&new->data);
        new->next=head;
        new->prev=NULL;
        head->prev=new;
        //head->next=NULL;
         
      
  }
  
}

int main()
{
    create();
    disp();
    insertBegin();
    disp();
    insertEnd();
    disp();
}