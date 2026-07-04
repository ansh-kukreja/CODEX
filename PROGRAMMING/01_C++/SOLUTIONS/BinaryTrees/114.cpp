#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void flatten(TreeNode* root) {
        
        while(root){
            if(root->left){
                // Step 1: Finding Predecessor of Root Node
                TreeNode* pred = root->left;
                while(pred->right) pred = pred->right;

                // Left Part ka end -> Right Part ka Head
                pred->right = root->right;

                // Root ka right part = Root ka left part
                root->right = root->left;

                // Root ka left is of no use now
                root->left = NULL;
            }

            // Move on to next node
            root = root->right;
        }
    }
};