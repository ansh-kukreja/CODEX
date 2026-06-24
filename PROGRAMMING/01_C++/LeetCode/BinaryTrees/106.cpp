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
    int postIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if(postIndex < 0 || inStart > inEnd) return NULL;

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int inorderPos = pos[element];

        root->right = build(postorder, inorderPos + 1, inEnd);
        root->left = build(postorder, inStart, inorderPos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) pos[inorder[i]] = i;

        postIndex = postorder.size()-1;
 
        return build(postorder, 0, inorder.size() - 1);
    }
};


int main(){
    
}