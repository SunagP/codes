#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
char data[5];
struct node* left;
struct node* right;
};

struct node* createNode(char val[])
{
    struct node* newnode=malloc(sizeof(struct node));
    strcpy(newnode->data,val);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* start,char val[])
{
    if(start==NULL)
        return createNode(val);
    if(strcmp(start->data,val)>0)
    {
        start->left=insert(start->left,val);
    }
    else
    {
        start->right=insert(start->right,val);
    }
    return start;
}

void inorder(struct node* start)
{
    if(start==NULL)
        return;
    inorder(start->left);
    printf(" %s",start->data);
    inorder(start->right);
}


int main()
{
    char n[5];
    int x=1;
    struct node* root=malloc(sizeof(struct node));
    root = NULL;
   
    while(x)
    {  printf("\n1 insert month\n2 inorder display\n0 exit\n");
       scanf("%d",&x);
       switch(x)
        {   case 1 :
            printf("Enter month  : ");
            scanf("%s",n);
            root=insert(root,n);
            break;
            case 2 :inorder(root);break;
            
        }
        
        
        
    }
    

    return 0;

}