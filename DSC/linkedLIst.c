#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

typedef struct node s;
void traverse(s*n);
int main()
{
    s *head=(s*)malloc(sizeof(s));
    s *first=(s*)malloc(sizeof(s));
    s *second=(s*)malloc(sizeof(s));

    printf("Enter 1st node \n");
    scanf("%d",&head->data);
    head->link=first;
    printf("Enter 2nd node \n");
    scanf("%d",&first->data);
    first->link=second;
     printf("Enter 3rd node \n");
    scanf("%d",&second->data);
    second->link=NULL;
    traverse(head);
    
    return 0;

}
void traverse(s *n)
{
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n=n->link;
    }
}