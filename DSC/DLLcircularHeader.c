#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* next, *prev;
    int data;
}*node1,*header;
void create(int n)                    
{
    int i,num;
    struct node *temp,*new;
    node1=(struct node*)malloc(sizeof(struct node));
    printf("enter data for node 1 : ");
    scanf("%d",&num);
    node1->data=num;
    node1->next=NULL;
    node1->prev=NULL;
    temp=node1;
   
    for(i=2;i<=n;i++)    
    {
        new=(struct node*)malloc(sizeof(struct node));
        if(new==NULL)
        {
            printf("memory allocation failed\n");
        }
        else
        {
            printf("enter data of node %d : ",i);
            scanf("%d",&new->data);
            new->next=NULL;
            new->prev=temp;
            temp->next=new;
            temp=temp->next;
        }
        
    }
    header->data=n;
    header->next=node1;
    temp->next=node1;
    node1->prev=temp;

}
void insert_before(void)
{
    int key;
    struct node *new,*p;
    p=node1;
    printf("enter data before which new node is to be inserted : ");
    scanf("%d",&key);
    if(node1->data==key)
    {
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        new->prev=NULL;
        printf("enter data of new node : ");
        scanf("%d",&new->data);
       
        
        node1->prev->next = new;
        new->prev=node1->prev;
        new->next=node1;
        header->data++;
        node1=new;
    }
    else
    {
        while(p!=NULL&&p->data!=key)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            printf("%d is not present in list",key);
        }
        else
        {
            header->data++;
            new=(struct node*)malloc(sizeof(struct node));
            new->next=NULL;
            new->prev=NULL;
            printf("enter data of new node : ");
            scanf("%d",&new->data);
            new->next=p;
            p->prev->next=new;
            new->prev=p->prev;
            p->prev=new;
        }
    }   
}
void delete_middle()
{
    if(header->data==0)
    {
        printf("no nodes to delete\n");
    }
    else
    {
        int i=1;
        struct node *p=node1;
        if(header->data==2)
        {
            struct node *p=node1->next;
            node1->next=NULL;
            p->next=NULL;
            p->prev=NULL;
            free(p);
            header->data--;
        }
        else if(header->data==1)
        {
            struct node *p=node1;
            header->data--;
            header->next=header;
            node1=NULL;
            p->next=NULL;
            p->prev=NULL;
            free(p);
        }
        else
        {
            while(i<(header->data/2)+1)
            {
                p=p->next;
                i++;
            }
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p->next=NULL;
            p->prev=NULL;
            free(p);
            header->data--;
        }
        

    }
    
}
void display()
{
    if(node1==NULL)
    {
        printf("no nodes in the list\n");
    }
    else
    {
        struct node *p;
        p=node1;
        while(p->next!=node1)
        {
            printf(" %d ",p->data);
            p=p->next;
        }
        printf(" %d ",p->data);
        printf("\n");
    }
    
}
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->next=header;
    header->prev=NULL;
    int x=1,len;
    printf("enter number of elements\n");
    scanf("%d",&len);
    create(len);
    while(x)                    
    {
        printf("\n1 display the list\n2 insert a node before a value\n3 delete middle node\n");
        printf("4 nodes count\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : display();
            break;
            case 2 : insert_before();
            break;
            case 3 : delete_middle();
            break;
            case 0 : break;
            case 4: printf("number of nodes present in the list=%d\n",header->data);
            default : printf("invalid input\n");
            break;
        }
    }
    return 0;

}