#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*node1;
void create(int);
void display(void);
void insert_after(void);
void insert_before(void);
void insert_insort(void);
int main()
{
    int n;
    printf("enter number of number of nodes : ");
    scanf("%d",&n);
    create(n);
    insert_after();
   // insert_before();
  //  insert_insort();
    display();
    return 0;
}
void create(int n)
{
    int i=2;
    struct node *new,*p;
    node1=(struct node*)malloc(sizeof(struct node));
    node1->link=NULL;
    p=node1;
    printf("enter data of node 1 : ");
    scanf("%d",&node1->data);
    while(i<=n)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter data of node %d : ",i);
        scanf("%d",&new->data);
        new->link=NULL;
        p->link=new;
        p=p->link;
        i++;
    }
}
void display(void)
{
    struct node *p;
    int i=1;
    p=node1;
    while(p!=NULL)
    {
        printf("data of node %d is : %d \n",i,p->data);
        i++;
        p=p->link;
    }
}
void insert_after(void)
{
    int key;
    struct node *p,*new;
    p=node1;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("enter data after which new node is to be inserted : ");
    scanf("%d",&key);
    while(p->data!=key)
    {
        p=p->link;
    }
    printf("enter data of new node : ");
    scanf("%d",&new->data);
    new->link=p->link;
    p->link=new;

}
void insert_before(void)
{
    int key;
    struct node *p,*new;
    p=node1;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("enter data before which new node is to be inserted : ");
    scanf("%d",&key);
    printf("enter data of new node : ");
    scanf("%d",&new->data);
    if(p->data==key)
    {
        node1=new;
        new->link=p;
    }
    else
    {
        while((p->link)->data!=key)
        {
            p=p->link;
        }
        new->link=p->link;
        p->link=new;
    }
    
}
void insert_insort(void)
{
    int key;
    struct node *p,*new;
    p=node1;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("enter data of new node : ");
    scanf("%d",&key);
    new->data=key;
    if(p->data>+key)
    {
        node1=new;
        new->link=p;
    }
    else
    {
        while((p->link)->data<=key)
        {
            p=p->link;
        }
        new->link=p->link;
        p->link=new;
    }
}