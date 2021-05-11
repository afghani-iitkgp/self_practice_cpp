#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* getNode(int data) 
{
    Node* new_node = new Node();

    new_node->val = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

Node* insertNode(Node* root, int data)
{
    if (root == nullptr)
        root = getNode(data);

    if (data > root->val) {
        // shift it to right sub-tree
        root->right = insertNode(root->right, data);
    }

    if (data < root->val) {
        // shift it to left sub-tree
        root->left = insertNode(root->left, data);
    }

    return root;

}

void preorder(Node* root) 
{
    if (root == nullptr)
        return;
    
    preorder(root->left);
    cout<<root->val<< "-- ";
    preorder(root->right);

}


int main()
{
    
   Node* root =  nullptr;
   root = insertNode(root,100);
   root = insertNode(root, 50);
   root = insertNode(root, 200);
   root = insertNode(root, 10);
   root = insertNode(root, 60);
   root = insertNode(root, 150);
   root = insertNode(root, 300);


   preorder(root);
}