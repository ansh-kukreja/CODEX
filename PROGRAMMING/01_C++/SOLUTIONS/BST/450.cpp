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
    int findPredecessor(TreeNode* root){
        // We know that left child is non-null
        root = root->left;

        while(root->right) root = root->right;
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key){
            // No Child
            if(!root->left && !root->right) return  NULL;

            // One Child
            if(root->left && !root->right) return root->left;

            if(!root->left && root->right) return root->right;

            // Both Child
            int pred = findPredecessor(root);
            root->val = pred;
            root->left = deleteNode(root->left, pred);
            return root;
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};



int main(){
    
}