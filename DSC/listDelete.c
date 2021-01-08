
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first;
void input(int n);
void delBeg();
void delEnd();
void disp();
void delAny();
void delVal();
void delBeforeVal();
void deleteAfter();
int main()
{   int n;
    printf("Hello World");
    printf("Enter num of nodes\n");
    scanf("%d",&n);
    input(n);
   // disp();
  // delBeg();
   //delEnd();
  // delAny();
  
//delBeforeVal();
 deleteAfter();
    disp();

    return 0;
}
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
    printf("head==> ");
    while(temp!=NULL)
    {
        printf("%d ==>",temp->data);
        temp=temp->next;
    }
    printf("Null");
}
void delBeg()
{
    struct node *p;
    p=first;
    first=first->next;
    p->next=NULL;
    free(p);
}
void delEnd()
{
    struct node *p,*q;
    p=first;
    /
    while(first->next->next!=NULL)
    {
        p=p->next;
    }
    q=p->next;
    p->next=NULL;
  
}
void delAny()
{   int val,i;
    struct node *p,*q;
    p=first;
    printf("enter the node to delete\n");
    scanf("%d",&val);
    if(val==1)
    {   q=first;
        first=first->next;
        q->next=NULL;
        free(q);
    }
    else{
    for(i=1;i!=val-1;i++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    
    q->next=NULL;
    free(q);
    }
}
void delVal()
{   int val;
    struct node *p,*q;
    p=first;
    printf("Enter the value to delete\n");
    scanf("%d",&val);
    if(val==p->data)
    {   
        first=first->next;
        p->next=NULL;
        free(p);
    }
    else{
    while(p->next!=NULL&&p->next->data!=val)
    { 
        p=p->next;
    }
     if(p->next==NULL)
    {
        printf("%d is not present",val);
    } 
    else
    {
    q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
        
    }
}
}
void delBeforeVal()
{    struct node *p,*q;
    p=first;
    int key;
    printf("Enter data before which the node is to be deleted : ");
    scanf("%d",&key);
    if(key==first->data)
    {
        printf("there is no node before %d \n",key);
    }
    else
    {
        while(p->next!=NULL&&p->next->data!=key)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            printf("%d is not present in list\n",key);
        }
        else
        {
            q=p->next;
            p->next=q->next;
            q->next=NULL;
            free(q);
        }
        
    }
}
void deleteAfter()
{
     struct node *p,*q;
    p=first;
    int key;
    printf("Enter data after which the node is to be deleted : ");
    scanf("%d",&key);
    
    {
        while(p->next!=NULL&&p->data!=key)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            printf("%d is not present in list\n",key);
        }
        else
        {
            q=p->next;
            p->next=q->next;
            q->next=NULL;
            free(q);
        }
        
    }
}
