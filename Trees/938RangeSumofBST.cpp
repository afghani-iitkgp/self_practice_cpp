/* Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high]. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

};

Node* getNode(int data) 
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->val = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

Node* insertNodeIntoBST(Node* root, int data)
{
    if (root == nullptr) {       
        root = getNode(data);
    }

    if (data > root->val) {
        root->right = insertNodeIntoBST(root->right, data);

    }
    else if (data < root->val) {
        root->left = insertNodeIntoBST(root->left, data);
    }

    return root;
    
}

int rangeSumBST(Node* root, int l, int r)
{
    // if (root == nullptr)
    //     return 0;
    
    // int sum;

    // if (root->val >= low && root->val <= high)
    //     sum = root->val;
    // else
    //     sum = 0;

    // sum += rangeSumBST(root->left, low, high);
    // sum += rangeSumBST(root->right, low, high);

    // return sum;
    return root ? (root->val>=l and root->val<=r ? root->val : 0) + rangeSumBST(root->left, l, r) + rangeSumBST(root->right, l, r) : 0;

}

int main()
{
    Node* root = nullptr;
    root = insertNodeIntoBST(root, 10);
    root = insertNodeIntoBST(root, 5);
    root = insertNodeIntoBST(root, 15);
    root = insertNodeIntoBST(root, 3);
    root = insertNodeIntoBST(root, 7);
    root = insertNodeIntoBST(root, 18);
    root = insertNodeIntoBST(root, 10);
    root = insertNodeIntoBST(root, 10);

    int low = 11;
    int high = 15;
    int s = rangeSumBST(root, low, high);
    cout<<"sum = "<<s<<'\n';

}