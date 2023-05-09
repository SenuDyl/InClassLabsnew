#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
		traverseInOrder(root->left);
		cout << root->key <<" ";
		traverseInOrder(root->right);
	}

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node==NULL){
    node =new struct node;
    node->key=key;
    node->left=node->right=NULL;
    return node;
  }
  else if (key > node->key){
    node->right = insertNode(node->right, key);
  }else{
    node->left = insertNode(node->left, key);
  }
	return node;
}

struct node* findMin(struct node* node)
{
	struct node* temp = node;
  while (temp && temp->left != NULL){
		temp = temp->left;
}
	return temp;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		//Case 1- Deleting leaf nodes
		if (root->left == NULL && root->right == NULL){
      struct node* node1 = root->right;
      free(root);
      return node1;
    }//Case 2- Delete a node which has only one child
    else if (root->left == NULL) {
			struct node* node1 = root->right;
			free(root);
			return node1;
		}
		else if (root->right == NULL) {
			struct node* node1 = root->left;
			free(root);
			return node1;
		}//Case 3- Delete a node which has two children
    else{
      struct node*node1=findMin(root->right);
      root->key=node1->key;
      root->right=deleteNode(root->right,node1->key);
    }
    
	}
	return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}