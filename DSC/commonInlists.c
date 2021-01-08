#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void display(struct node* head)
{
    printf("\nThe list is as follows:\n");
    while(head!=NULL)
    {
        printf("%d ", head->num);
        head = head->next;
    }
}

struct node* insertSort(struct node* head)
{
    struct node* newnode=malloc(sizeof(struct node));
    printf("enter the data of the node: ");
    scanf("%d",&newnode->num);
    if(head==NULL || head->num>=newnode->num)
    {
        newnode->next=head;
        head=newnode;
        return head;

    }
    else
    {
        struct node* tmp = head;
        while(head->next!=NULL && (head->next->num<newnode->num))
        {
            head=head->next;
        }
        newnode->next=head->next;
        head->next=newnode;
        return tmp;
    }
}

void com_display(struct node* l1,struct node* l2)
{
    int arr[50];
    int i=0;
    printf("\nCommon elements in the 2 lists are: ");
    while(l1!=NULL)
    {
        arr[i]=l1->num;
        i++;
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        for(int j=0;j<i;j++)
        {
            if(l2->num==arr[j])
                printf("%d ",arr[j]);
        }
        l2=l2->next;
    }
}

int main()
{
    struct node* list1=malloc(sizeof(struct node));
    list1=NULL;
    struct node* list2=malloc(sizeof(struct node));
    list2=NULL;
    int x=1;

  while(x)
  {
     printf("\nEnter the option: \n1)Insertion to list 1\n2)insertion to list 2\n3)Display list 1\n4)display list 2\n5)show similar values in list 1 and list 2\n6)Exit\n");
     scanf("%d",&x);
     switch(x)
     {
         case 1:
         list1=insertSort(list1);
         break;

         case 2:
         list2=insertSort(list2);
         break;

         case 3:
         display(list1);
         break;

         case 4:
         display(list2);
         break;

         case 5:
            com_display(list1,list2);
         case 6:
            exit(0);

         default: printf("wrong input\n");
     }
  }

  return 0;

}