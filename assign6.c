#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  int count;
  struct node* left, *right;
};

typedef struct node node;

void DisplayTree(node *t)
{
  if (t!=NULL)
    {
      DisplayTree(t->left);
      printf("(%d,%d) ",t->data,t->count);
      DisplayTree(t->right);
    }
}

node *insert(node *t, int a)
{
  node* temp;
  node* ptr=t;

  temp = (node*)malloc(sizeof(node));
  temp->data = a;
  temp->count = 1;
  temp->left = NULL;
  temp->right = NULL;
  
  if (t==NULL)
    return(temp);
  else
    if (a < t->data)
      {
	t->count++;
	t->left = insert(t->left,a);
      }
    else
      {
	t->right = insert(t->right,a);
      }
  return(t);
}


int kthsmallest(node* t, int k)
{
  if(!t || k < 0)
    return;
  kthsmallest(t->left, k);
  k--;
  if(k==0) 
    return (t->data);
  kthsmallest(t->right, k);
}

int main()
{
  node* root=NULL;
  int k;
  
  root = insert(root,10);
  root = insert(root,6);
  root = insert(root,14);
  root = insert(root,4);
  root = insert(root,8);
  root = insert(root,12);
  root = insert(root,16);

  DisplayTree(root);
  printf("\n");

  printf("Enter k\n");
  scanf("%d",&k);

  printf("Result = %d\n",kthsmallest(root,k));
}
