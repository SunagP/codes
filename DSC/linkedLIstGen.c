#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *first;//head node
typedef struct node s;//s is alias of struct
void traverse(s*n);
void inputs(int n)
{
     s *temp,*new;
     int i;
    //allocating memory for first node
    first= (struct node*)malloc(sizeof(struct node));
    
    printf("Enter node 1 data : \n");
    scanf("%d",&first->data);
    //linking the first node to NULL
    first->next=NULL;
    //assigning the address of first node to temp 
    temp=first;
    //taking inputs excluding the first node
    for(i=1;i<n;i++)
    {  
        new= (struct node*)malloc(sizeof(struct node));
        printf("Enter node %d data : \n",i+1);
        scanf("%d",&new->data);
        new->next=NULL;
       temp->next = new;//linking the first node to the next nodes
       temp = temp->next;//updating the temp 
    }

}
void insertBegin(int val) 
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
   

   
   new->next=NULL;
    new->data= val;
    
    new->next = first;
    first = new;
    
    
}
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    
        newNode->data = data; 
        newNode->next = NULL; 

        temp = first;

        // Traverse to the last node
        while( temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; 

        printf("DATA INSERTED SUCCESSFULLY\n");
    
}
void deleteFirstNode()
{
    if(first==0)
    {
        printf("no elements in the list");
    }
    else
    {
        struct node *toDelete;
        toDelete = first;
        first = first->next;
        
        printf("\nData deleted = %d\n", toDelete->data);

      
        free(toDelete);
        


        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
    
    
}
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(first == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = first;
        secondLastNode = first;

        
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == first)
        {
            first = NULL;
        }
        else
        {
           
            secondLastNode->next = NULL;
        }

        
        free(toDelete);

      
    }
    
}
void deleteAnyPos(int n)
{
    int pos;
    struct node *toDelete, *secondLastNode;
    
    printf("Enter position of node to delete\n");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("Invalid position\n");

    }
    else
    {
       

    if(first == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = first;
        secondLastNode = first;

        
        while(toDelete->next >= pos)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == first)
        {
            first = NULL;
        }
        else
        {
           
            secondLastNode->next = NULL;
        }

        
        free(toDelete);

    }
    
}

}
void reverseList()
{
    struct node *prevNode, *cur;

   
        prevNode = first;
        cur = first->next;
        first = first->next;

        prevNode->next = NULL; 

        while(first != NULL)
        {
            first = first->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = first;
        }

        first = prevNode; 

       
    
}

int main()
{
    int n,data;
    int x=1;
    
      printf("Enter number of elements\n");
      scanf("%d",&n);
    
      inputs(n);
     // traverse(first);
    
      while(x){
       printf("\nenter 1 to insert new node at the end\nenter 2 to delete first node\nenter 3 to display list \nenter 4 to delete last node\nenter 5 to delete a particular node\nenter 6 to reverse the list\nenter 7 to insert at beginning\nenter 0 to end\n");
      scanf("%d",&x);
      
      switch(x)
      {
       case 1 :
    
    
         printf("\nEnter data to insert at end of the list: \n");
         scanf("%d", &data);
         insertNodeAtEnd(data);
         break;
        
    
     
       case 2:  deleteFirstNode();
     
           
           break;
     
     
     case 3 : traverse(first);
     
        
       break;
       case 4 : deleteLastNode();
       break;
       case 5 : deleteAnyPos(n);
       break;
       case 6 : reverseList();
       break;
       case 7 : 
       printf("Enter data to insert at beginnning\n");
       scanf("%d",&data);
       insertBegin(data);
       default : break;
     
      }
     
      }
    return 0;

}
void traverse(s *n)
{
    if(first==0)
    {
        printf("no elements in the list");
    }
    else
    {
         //iterating over all the nodes untill last node
        int i=1;
        printf("Entered elements are\n");
        while(n!=NULL)
        {   printf("Node %d data : %d\n",i,n->data);
       // printf("%d ",n->data);
        n=n->next;
        i++;
    }
    }
    
}