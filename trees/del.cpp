#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Insert function to build BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Find minimum value node in a subtree
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete function for BST
Node* deleteNode(Node* root, int key) {
    // Base case: if tree is empty
    if (root == NULL) {
        return root;
    }
    
    // If key is smaller than root's data, go to left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If key is greater than root's data, go to right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If key is same as root's data, then this is the node to be deleted
    else {
        // Case 1: Node with only right child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: Node with only left child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal to display the tree
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search function to check if a node exists
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    
    // Insert nodes to create BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;
    
    // Delete a leaf node (node with no children)
    cout << "\nDeleting 20 (leaf node): ";
    root = deleteNode(root, 20);
    inorder(root);
    cout << endl;
    
    // Delete a node with one child
    cout << "\nDeleting 30 (node with one child): ";
    root = deleteNode(root, 30);
    inorder(root);
    cout << endl;
    
    // Delete a node with two children
    cout << "\nDeleting 50 (node with two children): ";
    root = deleteNode(root, 50);
    inorder(root);
    cout << endl;
    
    // Try to delete a non-existent node
    cout << "\nDeleting 100 (non-existent): ";
    root = deleteNode(root, 100);
    inorder(root);
    cout << endl;
    
    return 0;
}
