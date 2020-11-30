#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}

int addNodes(struct Node* iter)
{
  if (iter == NULL)
    return 0;
  return iter->value + addNodes(iter->left) + addNodes(iter->right);
}

int maximumSum(struct Node* head)
{
  if (head == NULL)
	  return 0;
	
  int left = maximumSum(head->left);
  int right = maximumSum(head->right);

  if (left > right){ 
	  return left + head->value;}
  else{
	  return right + head->value;}
}

/*
 *               1
 *   	   2            3 
 * 	    4     5     6      7
 *    10 X  10 X   X 10  10 X
 * 
*/

int main(){

  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->right->right = newNode(7);
  root->left->left = newNode(4);
  root->right->left = newNode(6);
  root->left->right = newNode(5);
  root->left->left->left = newNode(10);
  root->left->right->left = newNode(10);
  root->right->left->right = newNode(10);
  root->right->right->left = newNode(10);
 
  printf("Maximum sum: %d",maximumSum(root));
  printf("\n");
  return 0;
}





