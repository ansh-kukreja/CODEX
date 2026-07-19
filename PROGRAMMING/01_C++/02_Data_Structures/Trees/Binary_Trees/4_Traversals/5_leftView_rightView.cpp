#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    };
};

Node* buildTree(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}


void leftView(Node* root, vector<int> &ans, int level){
    if(root == NULL) return;
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    leftView(root->left, ans, level+1);
    leftView(root->right, ans, level+1);
}

void rightView(Node* root, vector<int> &ans, int level){
    if(root == NULL) return;
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    rightView(root->right, ans, level+1);
    rightView(root->left, ans, level+1);
}


int main(){
    Node* root = NULL;
    buildTree(root);  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    vector<int> ans;
    leftView(root, ans, 0);
    // rightView(root, ans, 0);

    cout<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}