#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};
int item,flag=0;
void search(struct node *root);
// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);
    // Traverse root
    printf("%d -> ", root->key);
    // Traverse right
    inorder(root->right);
  }
}
// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);
  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}
// Find the inorder successor
struct node *minValueNode(struct node *node) 
{
  struct node *current = node;
  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;
  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    // If the node has two children
    struct node *temp = minValueNode(root->right);
    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;
    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
// Driver code
int main() {
  struct node *root = NULL;
  int i,n,m,d,choice;

  do
  {
  printf("\nEnter your choice:\n1. Insertion\n2. Deletion\n3. Search\n4. Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  printf("Enter the element to be inserted:\n");
  scanf("%d",&m);
  root = insert(root,m);
  printf("\nInorder traversal:\n");
  inorder(root);
  break;
  case 2:
  printf("\nEnter the value to be deleted:\n");
  scanf("%d",&item);
          search(root);
          if(flag==0)
             printf("element not found");
          else
          	{
          	 printf("\nAfter deleting %d\n",item);
                 root = deleteNode(root,item);
                 printf("Inorder traversal:\n");
                 inorder(root);
          	}
  
  flag=0;
  break;
  case 3: printf("\n enter the value to be searched \n");
          scanf("%d",&item);
          search(root);
          if(flag==0)
             printf("element not found");
          else
              printf("%d found in binary search tree",item);
          flag=0;
  
  case 4:
  printf("\nExiting\n");
  break;
  }
  }while(choice!=4);
  return 0;
 } 
void search(struct node *root)
    {
       if (root != NULL) 
       {
        // Traverse left
        search(root->left);
         // Traverse root
         if(item==root->key)
         {
         flag=1;
         }
         // Traverse right
         search(root->right);
               }
    }
