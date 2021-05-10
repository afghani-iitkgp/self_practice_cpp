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

void preOrderTraversal(treeNode* root)
{
    if (root == nullptr)
        return;
    
    cout<< root->val<< "--";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);


}

treeNode* mergeTree(treeNode* root1, treeNode* root2)
{
    queue<treeNode*> q1, q2, q3;
    q1.push(root1);
    q2.push(root2);
    treeNode* root3;


    while( !q1.empty() || !q2.empty() ) {

        treeNode* curr_root1 = q1.front();
        treeNode* curr_root2 = q2.front();
        int val3;

        if (curr_root1 && curr_root2) {
            val3 = curr_root1->val + curr_root2->val;
        }

        if (curr_root1 && !curr_root2) {
            val3 = curr_root1->val;
        }

        if (!curr_root1 && curr_root2) {
            val3 = curr_root2->val;
        }

        root3 = getNode(val3);
        q3.push(root3);

        if (curr_root1->left && curr_root2->left) {
            q1.push(curr_root1->left);
            q2.push(curr_root2->left);
            int val3_left =  curr_root1->left->val + curr_root2->left->val;
            root3->left = getNode(val3_left);
            q3.push(root3->left);
        } 
            

        if (curr_root1->right)
            q2.push(curr_root1->right);
            
        if (curr_root2->left) 
            q2.push(curr_root2->left);
        
        if (curr_root2->right)
            q2.push(curr_root2->right);
        
        // q3.push(root3);
        // q3.push(root3->right);





    }
}

int main()
{
    treeNode* root1 = getNode(1);
    root1->left = getNode(3);
    root1->right = getNode(2);
    root1->left->left = getNode(5);

    treeNode* root2 = getNode(2);
    root2->left = getNode(1);
    root2->right= getNode(3);
    root2->left->right = getNode(4);
    root2->right->right = getNode(7);

    treeNode* root3 = mergeTree(root1, root2);
    preOrderTraversal(root3);

    return 0;
}