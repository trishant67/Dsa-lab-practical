#include<iostream>
using namespace std;

class node {
 public:
    node* left;
    node* right;
    int data;

    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
node * create_node(int value){
    node*newNode = new node(value);
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
node *insert(node*root , int value){
    if (root == NULL) return create_node(value);
    if (value < root->data){
        root->left = insert(root->left , value);
    }
    else if (value > root->data){
        root->right = insert(root->right , value);
    }
    return root;
}
void inorder_traversal (node*root){
    if (root == NULL) return;
    inorder_traversal(root->left);
    cout << root->data <<" ";
    inorder_traversal(root->right);
}
int main (){ 
    node*root = nullptr;
    int n , value ;
    cout << "enter the number of nodes :";
    cin >> n;

    for( int i = 0 ; i<n ; i++){
        cin >> value ;
        root = insert(root , value);
    }
    cout << "inorder traversal of BST :";
    inorder_traversal(root);

    return 0;
}