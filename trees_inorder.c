#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* insert(struct TreeNode* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void printInorder(struct TreeNode* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

int main()
{
    struct TreeNode* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);

    printf("\nInorder traversal of the binary tree is:\n");
    printInorder(root);

    return 0;
}
