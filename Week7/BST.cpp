#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) {
    return;
  }

  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // If the tree is empty, create a new node as the root
  if (node == NULL) {
    struct node *newNode = new struct node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  // If the key is less than the root's key, insert into the left subtree
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  }
  // If the key is greater than the root's key, insert into the right subtree
  else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  // Return root node
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) { // Base case: empty tree
    return root;
  }
  if (key < root->key) { // The key to be deleted is in the left subtree
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key) { // The key to be deleted is in the right subtree
    root->right = deleteNode(root->right, key);
  }
  else { // The key to be deleted is found
    // Case 1: No child or only one child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    // Case 2: Two children
    else {
      // Find the inorder predecessor (the largest node in the left subtree)
      struct node *current = root->left;
      while (current->right != NULL) {
        current = current->right;
      }
      // Replace the key of the node to be deleted with the key of the inorder predecessor
      root->key = current->key;
      // Delete the inorder predecessor
      root->left = deleteNode(root->left, current->key);
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