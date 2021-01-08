#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
}*first;
void display(void);
void create(int);
void deleteBeg(void);
void deleteEnd(void);
void deleteValue(void);
void deleteAfter(void);
void deleteBefore(void);
void deletePos(int);

int main()
{
    int x=1,count;
    printf("Enter number of nodes in the list : ");
    scanf("%d",&count);
    create(count);
    while(x)
    {
        
        {
            printf("\nEnter 1 to delete first node\nEnter 2 to delete last node\nEnter 3 to delete a data\n");
            printf("Enter 4 to delete node after a data\nEnter 5 to delete node before a data\nEnter 6 to delete a node at any position\n");
            printf("Enter 7 to display list\nEnter 0 to exit  \n");
            scanf("%d",&x);
            switch(x)
            {
               
                case 1 : deleteBeg();
                        count--;
                break;
                case 2 : deleteEnd();
                        count--;
                break;
                case 3 : deleteValue();
                        count--;
                break;
                case 4 : deleteAfter();
                        count--;
                break;
                case 5 : deleteBefore();
                        count--;
                break;
                case 6 : deletePos(count);
                        count--;
                break;
                 case 7 : display();
                break;
                case 0 : break;
                default : printf("invalid input\n");
                break;
            }
        }
    }
        
    return 0;
}
void create(int n)                     
{
    int i,num;
    struct node *temp,*new;
    first=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node 1 : ");
    scanf("%d",&num);
    first->data=num;
    first->link==NULL;
    temp=first;
   
    for(i=2;i<=n;i++)   
    {
        new=(struct node*)malloc(sizeof(struct node));
        if(new==NULL)
        {
            printf("memory allocation failed\n");
        }
        else
        {
            printf("Enter data of node %d : ",i);
            scanf("%d",&new->data);
            new->link=NULL;
            temp->link=new;
            temp=temp->link;
        }
        
    }
}
void display(void)              
{
    if(first==NULL)
    {
        printf("no elements in list");
    }
    else
    {
        int i=1;
        struct node *temp;
        temp=first;
        
        while(temp!=NULL)
        {
            printf(" Node %d data is : %d\n",i,temp->data);
            temp=temp->link;
            i++;
        }
       

    }
    
}
void deleteBeg(void)
{
    struct node *p;
    p=first;
    first=first->link;
    p->link=NULL;
    free(p);
}
void deleteEnd(void)
{
    struct node *p,*q;
    p=first;
    while(p->link->link!=NULL)
    {
        p=p->link;
    }
    q=p->link;
    p->link=NULL;

}
void deleteAfter(void)
{
    struct node *p,*q;
    p=first;
    int key;
    printf("Enter data after which the node is to be deleted : ");
    scanf("%d",&key);
    while(p->link!=NULL&&p->data!=key)
    {
        p=p->link;
    }
    if(p->link==NULL)
    {
       if(p->data==key)
       {
           printf("there is no node after %d\n",key);
       }
       else
       {
           printf("%d is not present in list\n",key);
       }
       
        
    }
    else
    {
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
    
}
void deleteBefore()
{
    struct node *p,*q;
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
        while(p->link!=NULL&&p->link->data!=key)
        {
            p=p->link;
        }
        if(p->link==NULL)
        {
            printf("%d is not present in list\n",key);
        }
        else
        {
            q=p->link;
            p->link=q->link;
            q->link=NULL;
            free(q);
        }
        
    }
    
}
void deleteValue(void)
{
    struct node *p,*q;
    int key;
    printf("Enter data of the node to be deleted : ");
    scanf("%d",&key);
    p=first;
    if(key==first->data)
    {
        q=first;
        first=first->link;
        q->link=NULL;
        free(q);
    }
    else
    {
        while(p->link!=NULL&&p->link->data!=key)
        {
            p=p->link;
        }
        if(p->link==NULL)
        {
            printf("%d is not present in the list\n",key);
        }
        else
        {
            q=p->link;
            p->link=q->link;
            q->link=NULL;
            free(q);
        }
    }
    

   
    
}
void deletePos(int count)
{
    struct node *p,*q;
    p=first;
    int pos;
    printf("Enter position of the node to be deleted : ");
    scanf("%d",&pos);
    if(pos<1||pos>count+1)
    {
        printf("invalid position\n");
    }
    else if(pos==1)
    {
        q=first;
        first=first->link;
        q->link=NULL;
        free(q);

    }
    else
    {
        int i=1;
        for(i=1;i!=(pos-1);i++)
        {
            p=p->link;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
    
}
void insert(int count)
{
    int pos,i=0;
    struct node *new,*p;
    p=first;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter data new node : ");
    scanf("%d",&new->data);
    if(first==0)
    {
        first=new;
    }
    else
    {
        printf("Enter position to insert new node : ");
        scanf("%d",&pos);
        if(pos<1||pos>(count+1))
        {
            printf("invalid position\n");
        }
        else if(pos==1)
        {
            new->link=first;
            first=new;
        }
        else
        {
            while(i!=(pos-2))
            {
                p=p->link;
                i++;
            }
            new->link=p->link;
            p->link=new;
        }
    }
    
    

}