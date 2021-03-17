#include<stdlib.h>
#include<stdio.h>

struct node
{
   struct node *prev;
   int data;
   struct node *next; 
}*head,*header;

void disp();
void create();
void insertBefore();
void deleteMiddle();


int main()
{
   int x=1;
   int n;
   header = (struct node*)malloc(sizeof(struct node));
   printf("Enter num of nodes\n");
   scanf("%d",&n);
   create(n);

   //header->next=NULL;
   header->prev=NULL;
   
   while(x)
   {
       printf("\n0 Exit \n1 insert before a given value \n2 delete middle node\n3 display\n4 number of nodes\n");
       scanf("%d",&x);
       switch(x)
       {
           case 1 :insertBefore();printf("%d",header->next->data);   break;
           case 2 :deleteMiddle();break; 
           case 3 :disp();break;
           case 4 : printf("Number of nodes is %d\n",header->data);break;

       }
   }

}


void disp()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Empty list..\n");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
   
}
void create(int n)
{   int i;
    struct node *new;
    head = (struct node*)malloc(sizeof(struct node));

    head->prev= NULL ;
    printf("Enter the data of node 1\n");
    scanf("%d",&head->data);
    head->next=NULL;
    struct node *last=head;
    for(i=2;i<=n;i++)
    {
     new= (struct node*)malloc(sizeof(struct node));  
  
    printf("Enter the data of node %d\n",i);
    scanf("%d",&new->data); 
    new->prev=last;
    new->next=NULL;
    last->next=new;
    last=new;

      
    }
    header->data=n;
    header->next=head;

}
void insertBefore()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp= head;
    int num;
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    printf("Enter the value before which insertion is done : ");
    scanf("%d",&num);
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    header->data++;
    if(num==head->data)
    {
        newnode->prev=NULL;
        newnode->next=head;
        head=newnode;
        header->next = head;
        return;
    }
    while(temp->next->data!=num)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
    header->data++;
}
void deleteMiddle()
{
    struct node* temp=head;
    int i=0;
    if(head==NULL)
    {
        printf("Cannot delete, empty list\n");
        return;
    }
    if(header->data==1)
    {
        head=NULL;
        printf("%d deleted\n",temp->data);
        free(temp);
        header->data--;
        return;
    }
    if(header->data==2)
    {
        temp=temp->next;
        head->next=NULL;
        printf("%d deleted\n", temp->data);
        free(temp);
        header->data--;
        return;
    }
    while(i<(header->data/2))
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("%d deleted\n", temp->data);
    free(temp);
    header->data--;
}
