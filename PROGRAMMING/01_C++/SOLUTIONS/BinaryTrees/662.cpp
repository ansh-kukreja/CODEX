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
    int widthOfBinaryTree(TreeNode* root) {
        //                 (Complete Binary Tree)
        //           Node        CBT Index
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(!q.empty()){
            unsigned long long startIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            int size = q.size();
            maxWidth = max(maxWidth, (int)((endIdx-startIdx)+1) );

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front().first;
                unsigned long long currIdx = q.front().second;
                q.pop();

                if(curr->left) q.push({curr->left, (currIdx*2)+1 });
                if(curr->right) q.push({curr->right, (currIdx*2)+2 });
            }
        }

        return maxWidth;
    }
};



int main(){
    
}