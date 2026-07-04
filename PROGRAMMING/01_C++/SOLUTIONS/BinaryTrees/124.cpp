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
    int maxSum = INT_MIN;

    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_hi_milgya = l + r + root->val;
        int best_of_both_paths = max(l,r) + root->val;
        int koi_acha_path_nhi_hai = root->val;

        maxSum = max({
            maxSum,
            neeche_hi_milgya,
            best_of_both_paths,
            koi_acha_path_nhi_hai
        });

        return max(best_of_both_paths, koi_acha_path_nhi_hai);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);

        return maxSum;
    }
};


int main(){
    
}