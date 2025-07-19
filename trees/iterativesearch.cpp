#include<iostream>
using namespace std;
struct node{
        int data;
        node *left;
        node *right;
        node(int val){
            data =val;
            left=nullptr;
            right=nullptr;
        }
};
void preorder(node *root){
    if(root ==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root ==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(node *root){
    if(root ==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}   
int  isBst(struct node*root){
    static struct node* prev =NULL;
    if(root!=NULL){
        if(!isBst(root->left)) {
        return false;
        }
        if(prev != NULL && prev->data >= root->data) {
            return false;
        }
        prev = root;
        return isBst(root->right);
    }
return 1;
}
struct node *search(struct node*root,int key){
    while(root!=NULL){
        if(root->data == key) return root;
        else if(root->data > key) root = root->left;
        else root = root->right;
    }
    return NULL; 
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    if(isBst(root)){
        cout << "The tree is a BST" << endl;
    } else {
        cout << "The tree is not a BST" << endl;
    }
    
    struct node* n = search(root, 3);
    if(n != NULL) {
        cout << "Found node with value: " << n->data << endl;
    } else {
        cout << "Node not found." << endl;
    }   
    
    return 0;
}