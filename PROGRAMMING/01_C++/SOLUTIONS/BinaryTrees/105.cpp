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
    unordered_map<int,int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if(inStart > inEnd) return NULL;

        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int inorderPos = pos[element];

        root->left = build(preorder, inStart, inorderPos - 1);
        root->right = build(preorder, inorderPos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) pos[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};


int main(){
    
}