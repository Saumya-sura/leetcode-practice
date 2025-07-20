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

Node *insert (Node *root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key < root->data) {
        root->left = insert(root->left, key);
    } else if(key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    
    cout << "Inorder traversal of the AVL tree is: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
