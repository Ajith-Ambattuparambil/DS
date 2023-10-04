//Binary search tree operations in C

#include<stdio.h>
#include<stdlib.h>
struct node
   {
      int key;
      struct node *left,*right;
   };
 
//Create a node

struct node *newNode(int item) 
   {
      struct node *temp=(struct node*) malloc(sizeof(struct node));
      temp->key=item;
      temp->=temp->right=NULL;
      return temp;
   }
  
//Inorder Traversal

void inorder(struct node *root)
   {
      if(root!=NULL)
         {
         
         //Traverse Left
            
            inorder(root->left);
                     
         //Traverse root
         
            printf("%d -> ", root->key);
            
         //Traverse Right
         
            inorder(root->right);
         }
   }
         
//Insert a node

struct node *insert(struct node *node,int key)
   {
   
   //Return a new node if the tree is empty
      
      if(node==NULL) 
      return newNode(key);
      
   //Traverse to the right place and insert the node
                     
      if(key< node->key)
         node->left=insert(node->left, key);
      else
         node->right=insert(node->right,key);
         return node;
    }
    
//Deleting a node

struct node *deleteNode(struct node *root,int key)
   {
      
   //Return if the tree is empty 
   
      if(root==NULL) 
      return root;
      
   //Find the node to be deleted
    
      if(key< root->key)
         root->left=deleteNode(root->left,key);
      else if(key>root->key)
         root->right=deleteNode(root->right, key);
         
      else
         {
         
         //If the node is only with one child or no child
         
            if(root->left == NULL)
               {
                  struct node *temp=root->left;
                  free(root);
                  return temp;
               }
           else if(root->right==NULL)
              {
                 struct node *temp=root->left;
                 free(root);
                 return temp;
              }
              
       //if the node has two children
       
       struct node *temp=minValueNode(root->right);
       
       //Place the inorder successor in position of the node to be deleted
       
       root->key=temp->key;
       
       //Delete the inorder successor     
       root->right=deleteNode(root->right,temp->key);
      }
    return root;
  }
  
 //Driver code
 
 int main()
    {
        struct node *root=NULL;
        root=insert(root,8);
        root=insert(root,3);
        root=insert(root,1);
        root=insert(root,6);                                                         
        root=insert(root,7);
        root=insert(root,10);
        root=insert(root,14);
        root=insert(root,4);
        
        printf("Inorder traversal: ");
        inorder(root);
        
        printf("\nAfter deleting 10\n");
        root=deleteNode(root,10);
        printf("Inorder traversal: ");
        inorder(root);
       }                                                 
