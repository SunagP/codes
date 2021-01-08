#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

void create()
{
    int n,i;
    printf("Enter number of node \n");
    scanf("%d",&n);
    struct node *new,*temp;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of node 1\n");
    scanf("%d",&head->data);
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d\n",n);
        scanf("%d",&new->data);
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
    temp->next=head;



}
void disp()
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d \n",temp->data);
}
void insertBegin()
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at beginning\n");
    scanf("%d",&new->data);
    struct node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->next=head;
    head=new;

}
void insertEnd()
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end\n");
    scanf("%d",&new->data);
    struct node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->next=head;
    
}
void deleteBeg(void)
{
    struct node *p,*temp=head;
    p=head;
    
    
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next=p->next;
    head=head->next;
    
    free(p);
}
void deleteEnd(void)
{
    struct node *p,*q;
    p=head;
    while(p->next->next!=head)
    {
        p=p->next;
    }
    q=p->next;
    p->next=head;
    free(q);

}
int main()
{
    create();
    disp();
    insertBegin();
    disp();
    insertEnd();
    disp();
    deleteBeg();
    disp();
    deleteEnd();
    disp();
}
