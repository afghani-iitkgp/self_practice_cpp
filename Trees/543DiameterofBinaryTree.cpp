/* Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.
*/

#include <bits/stdc++.h>
using namespace std;

struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;
};

treeNode* getNode(int data)
{
    treeNode* new_node = (treeNode*) malloc(sizeof(treeNode));
    new_node->val = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;

}

treeNode* insertIntoBST(treeNode* root, int data)
{
    if (root == nullptr)
        root = getNode(data);
    
    else {
        if (root->val > data) {
            root->left = insertIntoBST(root->left, data);
        }
        else if (root->val < data) {
            root->right = insertIntoBST(root->right, data);
        }

    }

    return root;
}


pair<int,int> diameterOfBinaryTree(treeNode* root)
{
    int dia_left, dia_right;
    int height_left, height_right;
    pair<int, int> r;

    
    if (root == nullptr)
        return make_pair(0, 0);
    
    tie(height_left, dia_left) = diameterOfBinaryTree(root->left);
    tie(height_right, dia_right) = diameterOfBinaryTree(root->right);
    
    r.first = max(height_left, height_right) + 1;
    int dia_curr = height_left + height_right;
    int dia_prev = max(dia_left, dia_right);
    
    r.second = (dia_prev >= dia_curr) ? dia_prev : dia_curr; 
    cout<<"root : "<<root->val<<"  "<<"diameter : "<< r.second<<"   "<<"height : "<<r.first<<'\n';
    return r; 
}

int main()
{
    // treeNode* root = nullptr;
    // root = insertIntoBST(root, 1);
    // root = insertIntoBST(root, 2);
    // root = insertIntoBST(root, 3);
    // root = insertIntoBST(root, 4);
    // root = insertIntoBST(root, 5);
    // root = insertIntoBST(root, 6);
    // root = insertIntoBST(root, 6);
    // root = insertIntoBST(root, 7);
    // root = insertIntoBST(root, 8);
    // root = insertIntoBST(root, 9);
    // root = insertIntoBST(root, 10);


    // treeNode* root = getNode(1);
    // root->left = getNode(2);
    // root->right = getNode(3);
    // // root->right->left = getNode(4);
    // // root->right->left->left = getNode(8);
    // // root->right->left->left->right = getNode(9);

    // // root->right->right = getNode(5);
    // // root->right->right->left = getNode(6);
    // // root->right->right->left->right = getNode(7);
    // // root->right->right = getNode(5);
    // // root->right->right = getNode(5);
    // root->left->left = getNode(4);
    // root->left->right = getNode(5);

    treeNode* x = getNode(1);
    
    x->left = getNode(2);
    x->right = getNode(3);

    x->right->left = getNode(4);
    x->right->right = getNode(5);

    x->right->left->left = getNode(6);
    x->right->left->right = getNode(7);
    x->right->right->right = getNode(8);

    x->right->left->left->left = getNode(9);
    x->right->left->right->left = getNode(10);
    x->right->left->right->right = getNode(11);

    x->right->left->left->left->left = getNode(12);
    x->right->left->left->left->right = getNode(13);
    x->right->left->right->left->left = getNode(14);
    x->right->left->right->right->left = getNode(15);

    x->right->left->left->left->left->right = getNode(16);
    x->right->left->left->left->right->left = getNode(17);
    x->right->left->right->right->left->left = getNode(18);











    pair<int, int> p = diameterOfBinaryTree(x);

    cout<<p.first<<"\n"<<p.second<<"\n";


    
}