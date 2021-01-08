#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
}*first;


void display();
void insertSort();

int main()
{
  int x;
 
  while(x)
  { 
     printf("\nEnter the option: \n1)Insertion\n2)Display the list\n3)Exit\n");
     scanf("%d",&x);
     switch(x)
     {
         case 1:
         insertSort();
         break;

         case 2:
         display();
         break;

         case 3:
         exit(0);
         break;

         default: printf("wrong input\n");
     }
    

  }
  return 0;
}
void insertSort()
{
	
	
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	 printf("Enter the data to be inserted:\n");
	scanf("%d",&newNode->num);
	newNode->next = NULL;
	if (first == NULL || first->num >= newNode->num)
	{
		newNode->next = first;
		first = newNode;
	}
    else
	{
	    struct node* temp = first;
        while (temp->next != NULL && (temp->next->num < newNode->num))
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
	}
}
void display()
{
    
    {
        printf("\nThe list is as follows:\n");
        struct node *tmp;
        tmp = first;
        while(tmp!=NULL)
        {
           printf("%d ", tmp->num);
           tmp = tmp->next;
        }
    }
}