#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head3=NULL;
void display(struct node*);
void create(struct node**);
void insert(int);
void list_intersection(struct node *,struct node *);
int main()
{
    struct node *head1,*head2;
    head3=(struct node*)malloc(sizeof(struct node));
    head3->data=0;
    head3->link=NULL;
    printf("enter elements of list 1 : \n");
    create(&head1);
    printf("enter elements of list 2 : \n");
    create(&head2);
    printf("list 1 : \n");
    display(head1);
    printf("list 2 : \n");
    display(head2);
    list_intersection(head1,head2);
    printf("common elements in two lists are : ");
    display(head3);
    
    return 0;
}
void create(struct node **a)
{
    int x,i=2;
    struct node *new,*p;
    *a=(struct node*)malloc(sizeof(struct node));
    (*a)->link=NULL;
    p=*a;
    printf("enter data of node 1 : ");
    scanf("%d",&(*a)->data);
    while(x)
    {
        printf("enter 1 to add element to the list\nenter 0 to end the list : ");
        scanf("%d",&x);
        switch(x)
        {
            case 0 : break;
            case 1 : new=(struct node*)malloc(sizeof(struct node));
                     new->link=NULL;
                     printf("enter data of new node : ");
                     scanf("%d",&new->data);
                     while(p->link!=NULL)
                     {
                         p=p->link;
                     }
                     p->link=new;
            break;
            default : printf("invalid\n");
            break;


        }
    }
}
void display(struct node *a)   //displays the list
{
    struct node *temp;
    temp=a;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void list_intersection(struct node *a,struct node *b)
{
    struct node *p,*q;
    p=a;
    q=b;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            if(p->data==q->data)
            {
                insert(p->data);
            }
            q=q->link;
           
        }
         p=p->link;
         q=b;
    }
    p = head3;              
    while (p->link!=NULL) 
    {
       if (p->data==p->link->data) 
       {           
           q=p->link->link;
           free(p->link);
           p->link=q;  
       }
       else
       {
           p=p->link;
       }
       
    }
}
void insert(int key)    
{
   if(head3->data==0)
   {
       head3->data=key;
   }
   else
   {
        struct node *new,*p;
        new=(struct node*)malloc(sizeof(struct node));
        new->link=NULL;
        p=head3;
        new->data=key;
        if(p->data>=key)
        {
            head3=new;
            new->link=p;
        }
        else
        {
            while(p->link!=NULL&&p->link->data<=key)
            {
                p=p->link;
            }
            new->link=p->link;
            p->link=new;  

        }
   }
   
}