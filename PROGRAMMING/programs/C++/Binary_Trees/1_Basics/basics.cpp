#include<iostream>
using namespace std;

// ============= BINARY TREE ==============
/*
    A Binary Tree can have 2 or less than 2 child Nodes ( 0 <= Child-Nodes <= 2 )
*/

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    };
};

node* buildTree(node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}


int main(){
    node* root = NULL;
    buildTree(root);
}