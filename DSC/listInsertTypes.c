#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
}*first;
void create(int);
void display(void);
void insertBeg(void);
void insertEnd(void);
void insertAfter(void);
void insertBefore(void);
void insertAnyPos(int);

int main()
{
    int x=1,len;
    printf("Enter number of elements : ");
    scanf("%d",&len);
    create(len);
    while(x!=-1)
    {
        if(first==0)
        {

            printf("no elements in list\n");
            printf("Enter 1 to add nodes\nEnter 0 to exit\n");
            scanf("%d",&x);
            switch(x)
            {
                case 1 : insertAnyPos(len);
                break;
                case 0 : break;
                default : printf("invalid\n");
                break;
            }

        }
        else
        {
            printf("\nEnter 1 to display list\nEnter 2 insert to node at beginning\nEnter 3 to insert node at the end\nEnter 4 insert node after a data\n");
            printf("Enter 5 to insert a node before a data\nEnter 6 to insert a node at any position\nEnter 7 to delete a node at any position\n");
            printf("Enter 0 to exit : ");
            scanf("%d",&x);
            switch(x)
            {
                case 1 : display();
                break;
                case 2 : insertBeg();
                        len++;
                break;
                case 3 : insertEnd();
                        len++;
                break;
                break;
                case 4 : insertAfter();
                        len++;
                break;
                case 5 : insertBefore();
                        len++;
                break;
                case 6 : insertAnyPos(len);
                        len++;
                break;
                
                break;
                case 0 : exit(0);
                default : printf("invalid option chosen!!");
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
            printf("Node %d data : %d\n",i,temp->data);
            temp=temp->link;
            i++;
        }
       

    }
    
}
void insertBeg(void)
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter data of new node : ");
    scanf("%d",&new->data);
    new->link=first;
    first=new;

}
void insertEnd(void)
{
    struct node *new,*p;
    p=first;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter data of new node : ");
    scanf("%d",&new->data);
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=new;
}
void insertAfter(void)
{
    int key;
    struct node *new,*p;
    p=first;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter data of new node : ");
    scanf("%d",&new->data);
    printf("Enter data after which new node is to be inserted : ");
    scanf("%d",&key);
    while(p->data!=key)
    {
        p=p->link;
    }
    if(p==NULL)
    {
        printf("%d is not present in list\n",key);
    }
    else
    {
        new->link=p->link;
        p->link=new;
    }
}
void insertBefore(void)
{
    int key;
    struct node *new,*p;
    p=first;
    new=(struct node*)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter data of new node : ");
    scanf("%d",&new->data);
    printf("Enter data before which new node is to be inserted : ");
    scanf("%d",&key);
    if(first->data==key)
    {
        new->link=first;
        first=new;
    }
    else
    {
        while(p->link!=NULL&&p->link->data!=key)
        {
            p=p->link;
        }
        if(p->link==NULL)
        {
            printf("%d is not present in list",key);
        }
        else
        {
            new->link=p->link;
            p->link=new;
        }
        
    }   
}
void insertAnyPos(int len)
{
    if(first==0)
    {
        first=(struct node*)malloc(sizeof(struct node));
        printf("Enter data of new node : ");
        scanf("%d",&first->data);
    }
    else
    {
        int pos,i=0;
        printf("Enter position of new node to be inserted\n");
        scanf("%d",&pos);
        if(pos<1||pos>(len+1))
        {
            printf("invalid position\n");
        }
        else
        {
            struct node *new,*p;
            p=first;
            new=(struct node*)malloc(sizeof(struct node));
            new->link=NULL;
            printf("Enter data of new node : ");
            scanf("%d",&new->data);
            if(pos==1)
            {
                new->link=first->link;
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
    
}
