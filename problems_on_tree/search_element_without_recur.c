#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

int searchelewithoutrecur(struct BinaryTree *root,int value)
{
  struct BinaryTree *temp;
  struct Queue *Q = createQueue();
  enQueue(Q,root);

  while(!isEmpty(Q));
  {
    temp= deQueue(Q);

    if(value = temp->data)
    {
       deQueue(Q);
       return 1;
    }
    if(temp->left)
     enQueue(Q,temp->left);
    if(temp->right)
     enQueue(Q,temp->right);
  }
  deleteQueue(Q);
  return 0;
}

// Function to insert a value into the BST
struct BinaryTree* insert(struct BinaryTree* root, int value) {
    // If the tree is empty, create a new node and return it as the new root
    if (root == NULL) {
        return createNode(root,value);
    }

    // Otherwise, recursively insert the value into the appropriate subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

int createNode(struct BinaryTree *root , int value)
{
  struct Queue *Q;
  struct BinaryTree *temp;
  struct BinaryTree *newNode;

  newNode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));

  if(!newNode)
  {
    printf("Memory not allocated \n");
  }

  if(!root)
  {
    root = newNode;
    return newNode;
  }

  Q = createQueue();
  enQueue(Q, root);
  
  while(!isEmpty(Q))
  {
    temp = deQueue(Q);

    if(temp->left)
    {
      enQueue(Q,temp->left);
    }
    else
    {
      temp->left= newNode;
      deleteQueue(Q);
      return newNode;
    }

     if(temp->right)
    {
      enQueue(Q,temp->right);
    }
    else
    {
      temp->right= newNode;
      deleteQueue(Q);
      return newNode;
    }
  }
  deleteQueue(Q);
  return 0;
}

int main() {
    // Initialize an empty BST
    struct BinaryTree* root ;
    
    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

  //function to be performed
  if(!searchelewithoutrecur(root,70))
   printf("The search element is found\n");
  else
   printf("The search value not found\n");

    return 0;
}