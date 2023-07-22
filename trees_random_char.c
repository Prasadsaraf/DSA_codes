#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creation of the NODE
struct TreeNode
{
    char value;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(char data)
{
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for preorder traversal
void preOrderTraversal(struct TreeNode *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        fprintf(fp, "%c->", root->value);
        preOrderTraversal(root->left, fp);
        preOrderTraversal(root->right, fp);
    }
}

// Function for inorder traversal
void inOrderTraversal(struct TreeNode *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrderTraversal(root->left, fp);
        fprintf(fp, "%c->", root->value);
        inOrderTraversal(root->right, fp);
    }
}

// Function for postorder traversal
void postOrderTraversal(struct TreeNode *root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrderTraversal(root->left, fp);
        postOrderTraversal(root->right, fp);
        fprintf(fp, "%c->", root->value);
    }
}

int main()
{
    FILE *outputFile = fopen("output.txt", "w");
    int i;
    struct TreeNode *root = NULL; // Initialize root to NULL
    int n;
    char a;

    printf("Enter the number of characters to generate: ");
    scanf("%d", &n);

    // Code for random character generation
    time_t t;
    srand((unsigned)time(&t));

    printf("The random characters generated are:\n");
    for (i = 0; i < n; i++)
    {
        a = 'a' + rand() % 26; // Generate a random lowercase character
        fprintf(outputFile, "%c\n", a);

        if (i == 0)
        {
            root = createNode(a); // Create the root node
        }
        else
        {
            struct TreeNode *current = root;
            struct TreeNode *parent = NULL;

            while (current != NULL)
            {
                parent = current;
                if (a < current->value)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (a < parent->value)
            {
                parent->left = createNode(a);
            }
            else
            {
                parent->right = createNode(a);
            }
        }
    }

    // Open files for writing traversal results
    FILE *preOrderFile = fopen("preorder.txt", "w");
    FILE *inOrderFile = fopen("inorder.txt", "w");
    FILE *postOrderFile = fopen("postorder.txt", "w");

    preOrderTraversal(root, preOrderFile);
    inOrderTraversal(root, inOrderFile);
    postOrderTraversal(root, postOrderFile);

    // Close files
    fclose(preOrderFile);
    fclose(inOrderFile);
    fclose(postOrderFile);
    fclose(outputFile);

    return 0;
}
