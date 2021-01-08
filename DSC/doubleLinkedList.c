#include<stdlib.h>
#include<stdio.h>
int n;
struct node
{
   struct node *prev;
   int data;
   struct node *next; 
}*head;
void disp()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
   
}
void dispRev()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        //printf("%d ",temp->data);
        temp=temp->next;
    }
     while(temp->prev!=NULL)
     {
         printf("%d",temp->prev);
         temp=temp->prev;
     }

}
void create()
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
        struct node *new= (struct node*)malloc(sizeof(struct node));
        new= (struct node*)malloc(sizeof(struct node));
        new->prev= NULL ;
        printf("Enter the data to insert at the beginning\n");
        scanf("%d",&new->data);
        new->next=head;
        new->prev=NULL;
        head->prev=new;
        //head->next=NULL;
        head=new;  
      
  }
  
}
void insertEnd()
{   struct  node *temp=head;
    if(head==NULL)
  {
    struct node *new= (struct node*)malloc(sizeof(struct node));
    new->prev= NULL ;
    printf("Enter the data to insert at the end \n");
    scanf("%d",&new->data);
    new->next=NULL;
    head=new; 
  } 
  else
  {
      struct node *new= (struct node*)malloc(sizeof(struct node));
    new->prev= NULL ;
    printf("Enter the data to insert at the end \n");
    scanf("%d",&new->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    new->next=NULL;

  }
  
}
void insertAnyPos()
{
    int pos,i=0;
    printf("Enter the position to insert\n");
    scanf("%d",&pos);
    if(pos==0||pos>n+2)
      printf("invalid position\n");
    else{
    if(pos==1)
    {   
        insertBegin();
    }
    else
    {   struct node *temp=head;
        struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d\n",pos);
        scanf("%d",&new->data);

        for(i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        new->prev=temp;
        temp->next=new;
        temp->next->prev=new;

    }
    }
    

}
void deletehead()
{
    struct node *temp=head;
    head=head->next;
    
    head->prev=NULL;
    printf("%d is deleted\n",temp->data);
    free(temp);
}
void deleteLast()
{
    struct node *temp=head,*temp1;
   if(temp->next==NULL)
   {  
        printf("%d is deleted\n",temp->data);
       head=head->next;
       head->prev=NULL;
       
       free(temp);
   }
   else
   {
      while(temp->next->next!=NULL)
      {
          temp=temp->next;
      }
      printf("\n\n%d is deleted\n\n",temp->next->data);
      temp->next=NULL;
      
   }
   
}
void deleteAnypos()
{
    int pos,i=0;
    printf("Enter the position to delete\n");
    scanf("%d",&pos);
    if(pos==0||pos>n)
      printf("invalid position\n");
    else{
    if(pos==1)
    {   
        deletehead();
    }
    else if (pos==n)
    {   
        deleteLast();
    }
    else
    {
        struct node *temp=head;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        printf("\n\n%d is deleted\n\n",temp->data);
        free(temp);
    }
    
}
}
void insertBefore()
{
    int key;
    struct node *new,*p;
    p=head;
    new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    printf("Enter data of new node : ");
    scanf("%d",&new->data);
    printf("Enter data before which new node is to be inserted : ");
    scanf("%d",&key);
    if(head->data==key)
    {
       insertBegin();
    }
    else
    {
        while(p->next!=NULL&&p->next->data!=key)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            printf("%d is not present in list",key);
        }
        else
        {
            new->next=p->next;
            p->next=new;
            new->prev=p;
        }
        
    }   
}
/*void deleteMiddle()
{
    int pos,i=0;
    if(n==0||n==1)
    {
        deletehead();
    }
    
    pos = n/2;
    
    
    if(pos==0)
    {   
        deletehead();
    }
    
    
    
    {
        struct node *temp=head;
        if(pos==1)
    {
        temp=temp->next;
    }
        for(i=0;i<=pos-1;i++)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        printf("\n\n%d is deleted\n\n",temp->data);
        free(temp);
    }
    
}*/
void deleteMiddle()
{
    struct node* temp=head;
    int i=0;
    if(head==NULL)
    {
        printf("Cannot delete, empty list\n");
        return;
    }
    if(n==1)
    {
        head=NULL;
        printf("%d deleted\n",temp->data);
        free(temp);
        n--;
        return;
    }
    if(n==2)
    {
        temp=temp->next;
        head->next=NULL;
        printf("%d deleted\n", temp->data);
        free(temp);
        n--;
        return;
    }
    while(i<(n/2))
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("%d deleted\n", temp->data);
    free(temp);
    n--;
}


int main()
{
   int x,c=0;
   printf("Enter num of nodes\n");
   scanf("%d",&n);
   create(n);
   while(x)
   {
       printf("\n0 Exit \n1 insert at beginning\n2 insert at end \n3 insert at any position \n4 display\n5 delete head node\n6 delete last node\n7 delete at any position\n8 insert before a given value\n9 delete middle node\n");
       scanf("%d",&x);
       switch(x)
       {
           case 1 :insertBegin();++n;break;
           case 2 :insertEnd();++n;break;
           case 3 :insertAnyPos();++n;break;
           case 4 :disp();break;
           case 5 :deletehead();--n;break;
           case 6 :deleteLast();--n;break;
           case 7 :deleteAnypos();--n;break;
           case 8 :insertBefore();++n;break;
           case 9 : deleteMiddle();--n;break;
       }
   }
    
    
    
    
    disp();
    dispRev();

}

