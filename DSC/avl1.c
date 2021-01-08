#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,balFact;
    struct node *left,*right;
}*root;
void preorder(struct node *p)
{
    if(p!=NULL)
    {
         printf(" %d(%d) ",p->data,p->balFact);
        preorder(p->left);
        preorder(p->right);
    }
}
int max(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    return y;
}
int height(struct node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        return (max(height(p->left),height(p->right))+1);
    }
}
void balance(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    p->balFact=height(p->left)-height(p->right);
}
/*void newBalFact(struct node *p,int key)
{
    if(key>p->data)
    {
        newBalFact(p->right,key);
    }
    else if (key<p->data)
    {
        newBalFact(p->left,key);
    }
    else
    {
        p->balFact=0;
    }
    balance(p);
   
    
}*/
struct node* insert(struct node *a,int key)
{
    if(a==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->right=NULL;
        new->left=NULL;
        new->balFact=0;
        new->data=key;
        return new;
    }
    else if(key>a->data)
    {
        a->right=insert(a->right,key);
    }
    else
    {
        a->left=insert(a->left,key);
    }
    balance(a);
    if(a->balFact<-1&&key>a->right->data)
    {
        struct node *x,*y;
        x=a;
        y=a->right;
        x->right=y->left;
        y->left=x;
        a=y;
        balance(a);
        balance(a->left);
        balance(a->right);
    }
    else if(a->balFact<-1&&key<a->right->data)
    {
        struct node *x,*y,*z;
        x=a;
        y=a->right;
        z=y->left;
        y->left=z->right;
        z->right=y;
        x->right=z->left;
        z->left=x;
        a=z;
        balance(a);
        balance(a->left);
        balance(a->right);
    }
    else if(a->balFact>1&&key<a->left->data)
    {
        struct node *x,*y;
        x=a;
        y=a->left;
        x->left=y->right;
        y->right=x;
        a=y;
        balance(a);
        balance(a->left);
        balance(a->right);
    }
    else if(a->balFact>1&&key>a->left->data)
    {
        struct node *x,*y,*z;
        x=a;
        y=x->left;
        z=y->right;
        y->right=z->left;
        z->left=y;
        x->left=z->right;
        z->right=x;
        a=z;
        balance(a);
        balance(a->left);
        balance(a->right);
    }
    return a;
}
int main()
{
    int key,x=0;
    do
    {
        printf("enter 1 to insert\nenter 2 to display(preorder)\nenter 0 to exit : ");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : printf("enter data of node to be inserted : ");
                     scanf("%d",&key);
                     root=insert(root,key);
                     break;
            case 2 : printf("preorder--\n");
                     preorder(root);
                     break;
            case 0 : break;
            default : printf("invalid\n");
                      break;
        }
    } while (x);
    return 0;
}