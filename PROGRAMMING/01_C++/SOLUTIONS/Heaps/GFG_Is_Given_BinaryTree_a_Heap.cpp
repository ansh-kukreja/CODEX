#include<iostream>
using namespace std;


class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    int n;
    
    bool isCBT(Node* root, int index) {
        if(!root) return true;

        if(index >= n) return false;

        bool left  = isCBT(root->left, (2 * index) + 1);
        bool right = isCBT(root->right, (2 * index) + 2);

        return left && right;
    }

    int getCount(Node* root) {
        if(!root) return 0;

        int count = 1 + getCount(root->left) + getCount(root->right);
        return count;
    }
    
    bool isMaxOrderPropertySatisfied(Node* root) {
        // == Leaf Node Case ==
        if (!root->left && !root->right) 
            return true;
        
        // == Only Left Child Case ==
        if (root->left && !root->right) 
            return (root->data > root->left->data);
            
        // == Both Left & Right Child Exists Case (Assuming it is CBT as we're checking it before this) ==
        else {
            bool left = isMaxOrderPropertySatisfied(root->left);
            bool right = isMaxOrderPropertySatisfied(root->right);
            
            if (left && right && 
            (root->data > root->left->data) && 
            (root->data > root->right->data))
                return true;
            
            else return false;
        }
    }
    
    bool isHeap(Node* tree) {
        n = getCount(tree);
        
        if (isCBT(tree, 0) && isMaxOrderPropertySatisfied(tree) )
            return true;
        
        else 
            return false;
    }
};



int main(){
    
}