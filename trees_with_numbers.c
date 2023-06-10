#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE* left;
    struct NODE* right;
};

//creating a NODE//
struct NODE* create(value)
{
    struct NODE* newNODE=malloc(sizeof(struct NODE));
    newNODE->data=value;
    newNODE->left=NULL;
    newNODE->right=NULL;
    return newNODE;
};

//inert at left//
struct NODE* insertLeft(struct NODE* root,int value)
{
    root->left=create(value);
    return root->left;
};

//insert right//
struct NODE* insertRight(struct NODE* root,int value)
{
    root->right=create(value);
    return root->right;
};

//preorder traversal//
void preorderTraversal(struct NODE* root,FILE *fp1)
{
  if (root == NULL)
    return;
    else
        {
  fprintf(fp1,"%d ->", root->data);
  printf("%d->",root->data);
  preorderTraversal(root->left,fp1);
  preorderTraversal(root->right,fp1);
}
}

//inorder traversal//
void inorderTraversal(struct NODE* root,FILE *fp2)
 {
  if (root == NULL)
    return;
    else
        {
  inorderTraversal(root->left,fp2);
  fprintf(fp2,"%d ->", root->data);
    printf("%d ->",root->data);
  inorderTraversal(root->right,fp2);
}
 }

//post order traversal//
void postorderTraversal(struct NODE* root,FILE *fp3)
 {
  if (root == NULL)
    return;
    else
        {
  postorderTraversal(root->left,fp3);
  postorderTraversal(root->right,fp3);
  fprintf(fp3,"%d ->", root->data);
    printf("%d ->",root->data);
}
 }

int main()
{
  struct NODE* root = create(1);
/*int i,j,n;
  scanf("%d",&n);
  scanf("%d",&j);
  for(i=0;i<n;i++)
  {
    scanf("%d",&j);
  }*/
  insertLeft(root, 3);
  insertRight(root, 5);
  insertLeft(root->left, 69);
  insertRight(root->left, 8);
  insertLeft(root->right, 0);
  insertRight(root->right, 23);
  FILE *fp1,*fp2,*fp3;

    fp1=fopen("inorder.txt","w");
    fp2=fopen("preorder.txt","w");
    fp3=fopen("postorder.txt","w");

  printf("Traversal of the inserted binary tree \n");
  printf("Inorder traversal \n");
  inorderTraversal(root,fp1);

  printf("\nPreorder traversal \n");
  preorderTraversal(root,fp2);


  printf("\nPostorder traversal \n");
  postorderTraversal(root,fp3);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
}
