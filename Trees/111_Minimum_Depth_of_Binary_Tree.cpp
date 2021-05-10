#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
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
struct distNode {
    treeNode* node;
    int dist;
};

int minDepthOfTree(treeNode* root)
{
    if (root == nullptr)
        return 0;
    
    queue<distNode> q;
    
    q.push({root, 0});

    while (!q.empty()) {

        distNode curr_root = q.front();

        if (curr_root.node->left == nullptr && curr_root.node->right == nullptr)
            return curr_root.dist;
        else {
            int d = ++curr_root.dist;
            if (curr_root.node->left)
                q.push({curr_root.node->left, d });
            if (curr_root.node->right)
                q.push({curr_root.node->right, d });
            
            q.pop();
        }
    }
    
}


int main()
{
    treeNode* root = getNode(2);
    root->left = getNode(9);
    root->right = getNode(20);
    root->right->left = getNode(15);
    root->right->right = getNode(17);
    
    // root->left = getNode(2);
    // root->left->left = getNode(20);

    // root->right = getNode(3);

    // root->right->left = getNode(4);
    // root->right->right = getNode(5);

    // root->right->left->left = getNode(6);
    // root->right->left->right = getNode(7);
    // root->right->right->right = getNode(8);    

    int minDepth = minDepthOfTree(root) + 1;
    cout<<minDepth<<'\n';
}