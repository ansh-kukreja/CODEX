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
    TreeNode* findPredecessor(TreeNode* root){
        TreeNode* temp = root->left;

        while(temp->right && temp->right != root) temp = temp->right;

        return temp;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        while(root){
            if(root->left == NULL){
                inorder.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* pred = findPredecessor(root);

                if(pred->right == NULL){
                    pred->right = root;
                    root = root->left;
                }
                else{
                    pred->right = NULL;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return inorder;
    }
};

int main(){

}