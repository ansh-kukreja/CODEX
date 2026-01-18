#include<iostream>
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

void levelOrderTraversing(Node* &root){
    cout<<endl;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}


// =================================================================================

void createMapping(vector<int> &in, map<int,int> &nodeToIndex, int n){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(vector<int> &in, vector<int> &pre, int &preOrderIndex, int inOrderStart, int inOrderEnd,
int n, map<int,int> &nodeToIndex){
    
    if(preOrderIndex >= n || inOrderStart > inOrderEnd){
        return NULL;
    }
    
    int element = pre[preOrderIndex++];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
    
    root->left = solve(in,pre,preOrderIndex,inOrderStart,position-1,n,nodeToIndex);
    root->right = solve(in,pre,preOrderIndex,position+1,inOrderEnd,n,nodeToIndex);
    
    return root;
}

// =================================================================================



int main(){
    vector<int> inorder = {3,1,4,0,5,2};
    vector<int> preorder = {0,1,3,4,2,5};

    int preOrderIndex = 0;
    int n = inorder.size();

    map<int,int> nodeToIndex;
    createMapping(inorder, nodeToIndex, n);
    
    Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n, nodeToIndex);
    levelOrderTraversing(ans);
}