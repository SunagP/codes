#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *left;
  int data;
  struct node *right;

};

struct node *create(int data)
{
   struct node *new =(struct node*)malloc(sizeof(struct node*));
    new->data = data;
    new->left=NULL;
    new->right=NULL;
    return new;

}

struct node *insert(struct node *node,int key)
{
    if(node==NULL)
     return create(key);
    if(key < node->data)
      node->left = insert(node->left,key);
    else
      node->right = insert(node->right,key);
    
    return node;

    
}
/*struct node *insert(struct node *node,int key)
{
   if(node==NULL)
    {
    struct node *new =(struct node*)malloc(sizeof(struct node*));
    new->data = key;
    new->left=NULL;
    new->right=NULL;
    }
    else
    { while(1){
       struct node *temp=node;
       struct node *new =(struct node*)malloc(sizeof(struct node*));
       if(key>node->data)
       {  
         if(node->right==NULL)
         {
           temp->right=new;
           break;}
          else
          { temp=temp->right;
              
          }
          
       } 
       else
       {
           if(node->left==NULL)
         {
           temp->left=new;
           break;}
          else
          { temp=temp->left;
              
          }
       }
       
    }
    }
    return node;
}*/
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ->",root->data);
        inorder(root->right);
    }
}
void inorderrev(struct node *root)
{
    if(root!=NULL)
    {
        inorderrev(root->right);
        printf("%d ->",root->data);
        inorderrev(root->left);
    }
}
void preorder(struct node *root)
{ 
    if(root!=NULL)
    {   
        printf("%d ->",root->data);
        inorder(root->left);
        inorder(root->right);
        
    }
    
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {   
        inorder(root->left);
        inorder(root->right);
        printf("%d ->",root->data);
    }
}
int search(struct node *root,int key)
{
    if(root==NULL)
     return 0;
    if(root->data==key)
     return 1;
    if(root->data < key)
     return search(root->right,key);
    else
     return search(root->left,key);
    
    
}

int rightMin(struct node *root)
{
    struct node *temp = root;
    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
struct node *delete(struct node *root,int key)
{
    if(root==NULL)
     return NULL;
    else if(root->data<key)
      root->right = delete(root->right,key);
    else if(root->data > key)
      root->left = delete(root->left,key);
    else
    {   if(root->left==NULL && root->right==NULL)
         {
             free(root);
             return NULL;

         } 
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else
        {
           int rm = rightMin(root->right);
           root->data=rm;
           root->right=delete(root->right , rm);
        }
    }
        
      return root;  
    }
int count = 0;
int leafnodes(struct node* newnode)
{
 
    if(newnode != NULL)
    {
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            count++;
        }
        leafnodes(newnode->right);
    }
    return count;
 
}
int height(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       
       int lh = height(node->left); 
       int rh = height(node->right); 
  
       
       if (lh > rh)  
           return(lh+1); 
       else return(rh+1); 
   } 
}  
  
int fullnode(struct node *root)
{
    if (root == NULL){
      return 0;
   }
   int result = 0;
   if (root->left && root->right){
      result++;
   }
   result += (fullnode(root->left) +
   fullnode(root->right));
//   printf("%d",result);
   return result;
}
struct node* cloneBinaryTree(struct node *root){
    if(root == NULL)
        return NULL;
    /* create a copy of root node */
    struct node* newNode = create(root->data);
    /* Recursively create clone of left and right sub tree */
    newNode->left = cloneBinaryTree(root->left);
    newNode->right = cloneBinaryTree(root->right);
    /* Return root of cloned tree */
    return newNode;
}
    
 int sumofNodes(struct node* root)
 {
   if (root == NULL)
    return 0;
   return(root->data + sumofNodes(root->left) + sumofNodes(root->right));
 }
 

int main()
{
    struct node *root=NULL,*clone;
    int x=1,data,key,key1;
    
   
    while(x)
    {
        printf("\n1 insert\n2 inorder\n3 postorder\n4 preorder\n5 search an elememt\n6 delete an element\n7 leafnode count\n8 height of tree\n9 Number og full nodes\n10 copy of bst\n11 sum of all nodes\n0 exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1 : printf("enter data\n");
                     scanf("%d",&data);
                     root = insert(root,data);break;
            case 2 : printf("Inorder traversal \n");inorder(root);printf("Inorder traversal rev\n");inorderrev(root);break;
            case 3 : printf("postorder traversal \n");postorder(root);break;
            case 4 : printf("preorder traversal \n");preorder(root);break;
            case 5 : printf("Enter data to search\n");
                     scanf("%d",&key);
                    if( search(root,key))
                     printf("%d is found\n",key);
                    else
                    {
                        printf("%d is Not found\n",key);
                    }break;
            case 6 : printf("Enter data to delete");
                     scanf("%d",&key1);
                    if( search(root,key1))
                    { 
                    printf("%d is deleted",key1);
                      delete(root,key1);

                    }
                    else
                    {
                        printf("%d is Not found\n",key1);
                    }break;
            case 7 :
                     printf("Number of leaf nodes in the Tree are : %d\n",leafnodes(root));break;
                     
            case 8 : printf("Height of tree is %d", height(root));break;
            case 9 : {int full;
            full = fullnode(root);
            printf(" full node %d",full);}break;
            case 10:clone = cloneBinaryTree(root);
            printf("Inorder traversal of copy tree \n");inorder(clone);break;
            case 11: {
                int sumnodes = 0;
                sumnodes = sumofNodes(root);
                printf("Sum of all nodes is %d",sumnodes);
            }  break;       
                    

        }
    }
    
    return 0;
}