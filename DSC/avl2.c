#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,balFact;
    struct node *left,*right;
}*root;
int max(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    return y;
}
int search(struct node* a,int key)
{
    if(a==NULL)
    {
        return 0;
    }
    else if (a->data==key)
    {
        return 1;
    }
    else if(key>a->data)
    {
        return search(a->right,key);
    }
    else
    {
        return search(a->left,key);
    }
    
    
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
void LL(struct node **a)
{
    struct node *x,*y;
        x=*a;
        y=(*a)->left;
        x->left=y->right;
        y->right=x;
        *a=y;
        balance(*a);
        balance((*a)->left);
        balance((*a)->right);
}
void LR(struct node **a)
{
       struct node *x,*y,*z;
        x=*a;
        y=x->left;
        z=y->right;
        y->right=z->left;
        z->left=y;
        x->left=z->right;
        z->right=x;
        *a=z;
        balance(*a);
        balance((*a)->left);
        balance((*a)->right);
}
void RR(struct node **a)
{
      struct node *x,*y;
        x=*a;
        y=(*a)->right;
        x->right=y->left;
        y->left=x;
        *a=y;
        balance(*a);
        balance((*a)->left);
        balance((*a)->right);
}
void RL(struct node **a)
{
        struct node *x,*y,*z;
        x=*a;
        y=(*a)->right;
        z=y->left;
        y->left=z->right;
        z->right=y;
        x->right=z->left;
        z->left=x;
        *a=z;
        balance(*a);
        balance((*a)->left);
        balance((*a)->right);
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
         printf(" %d(%d) ",p->data,p->balFact);
        preorder(p->left);
        preorder(p->right);
    }
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
        RR(&a);
        
    }
    else if(a->balFact<-1&&key<a->right->data)
    {
        RL(&a);
    }
    else if(a->balFact>1&&key<a->left->data)
    {
        LL(&a);
    }
    else if(a->balFact>1&&key>a->left->data)
    {
        LR(&a);
        
    }
    return a;
}
struct node* delete(struct node *a,int key)
{
    if(!search(a,key))
    {
        printf("entered element not present\n");
    }
   else if(root->data==key&&root->right==NULL&&root->left==NULL)
    {
        struct node *p=root;
        root=NULL;
        free(p);
    }
   else if(a==NULL)
     return NULL;
    else if(a->data<key)
     {
        a->right = delete(a->right,key);
        //balance(a->left);
     }
    else if(a->data > key)
     {
        a->left = delete(a->left,key);
        //balance(a->right);
     }
    else
    {   
        if(a->left==NULL && a->right==NULL)
         {
             free(a);
             return NULL;

         } 
        else if(a->right==NULL)
        {
            struct node *temp=a->left;
            free(a);
            return temp;
        }
        else if(a->left==NULL)
        {
            struct node *temp=a->right;
            free(a);
            return temp;
        }
        else
        {
           struct node *temp=a->right;
           while(temp->left!=NULL)
           {
               temp=temp->left;
           }
           a->data=temp->data;
           a->right=delete(a->right,a->data);
        }
    }

    balance(a);
    if(a->balFact<-1&&height(a->right->left)<height(a->right->right))
    {
        RR(&a);
        
    }
    else if(a->balFact<-1&&height(a->right->left)>height(a->right->right))
    {
        RL(&a);
    }
    else if(a->balFact>1&&height(a->left->right)<height(a->left->left))
    {
        LL(&a);
    }
    else if(a->balFact>1&&height(a->left->right)>height(a->left->left))
    {
        LR(&a);
        
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
            case 3 : if(root==NULL)
                     {
                         printf("no elements to delete\n");
                     }
                     else
                     {
                        printf("enter element to be deleted : ");
                        scanf("%d",&key);
                        root=delete(root,key);
                     }
            case 0 : break;
            default : printf("invalid\n");
                      break;
        }
    } while (x);
    return 0;
}