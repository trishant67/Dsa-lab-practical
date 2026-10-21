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
    node*newNode = new node();
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
int main(){
    node*root = create_node(1);
    node*root->left = create_node(2);
    node*root->right = create_node(3);
    node*root->right->left = create_node(4);
    node*root->right->right = create_node(5);

    return 0;
}
