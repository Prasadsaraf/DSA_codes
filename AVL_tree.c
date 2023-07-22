#include <stdio.h>
#include <stdlib.h>

// Create Node
struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
  int height;
};

// Calculate height
int getHeight(struct TreeNode *N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Create a node
struct TreeNode *newTreeNode(int data)
{
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

// Right rotate
struct TreeNode *rightRotate(struct TreeNode *y)
{
  struct TreeNode *x = y->left;
  struct TreeNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

  return x;
}

// Left rotate
struct TreeNode *leftRotate(struct TreeNode *x)
{
  struct TreeNode *y = x->right;
  struct TreeNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct TreeNode *N)
{
  if (N == NULL)
    return 0;
  return getHeight(N->left) - getHeight(N->right);
}

// Insert node
struct TreeNode *insertNode(struct TreeNode *node, int data)
{
  // Find the correct position to insert the node and insert it
  if (node == NULL)
    return newTreeNode(data);

  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  int balance = getBalance(node);
  if (balance > 1 && data < node->left->data)
    return rightRotate(node);

  if (balance < -1 && data > node->right->data)
    return leftRotate(node);

  if (balance > 1 && data > node->left->data)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && data < node->right->data)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct TreeNode *minValueNode(struct TreeNode *node)
{
  struct TreeNode *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a node
struct TreeNode *deleteNode(struct TreeNode *root, int data)
{
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);

  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  else
  {
    if ((root->left == NULL) || (root->right == NULL))
    {
      struct TreeNode *temp = root->left ? root->left : root->right;

      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
        *root = *temp;
      free(temp);
    }
    else
    {
      struct TreeNode *temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct TreeNode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

int main()
{
  struct TreeNode *root = NULL;
  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printPreOrder(root);

  root = deleteNode(root, 3);

  printf("\nAfter deletion: ");
  printPreOrder(root);

  return 0;
}
