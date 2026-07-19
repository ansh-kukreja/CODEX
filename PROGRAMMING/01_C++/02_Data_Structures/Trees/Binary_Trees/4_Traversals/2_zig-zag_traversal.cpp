#include<iostream>
#include<queue>
#include<vector>
using namespace std;

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

vector<int> zigZagTraversal(node* root) {
    vector<int> result;
    if(root == NULL) return result;
    
    queue<node*> q;
    q.push(root);
    
    bool leftToRight = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        
        for(int i=0; i<size; i++){
            node* frontNode = q.front();
            q.pop();
            
            int index = leftToRight? i : size-i-1;
            ans[index] = frontNode->data;
            
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        
        leftToRight = !leftToRight;
        
        for(auto i:ans){
            result.push_back(i);
        }
    }
    
    return result;
}


int main(){
    node* root = NULL;
    buildTree(root);  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    vector<int> ans = zigZagTraversal(root);

    cout<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}