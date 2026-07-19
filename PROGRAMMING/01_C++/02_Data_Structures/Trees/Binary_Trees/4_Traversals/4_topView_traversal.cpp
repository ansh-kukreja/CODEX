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


vector<int> topViewOfTree(Node* root){
    vector<int> ans;

    //============ hd: Horizontal Distance ===========
        
    if(root == NULL) return ans;
    
    // < Hd, Node >
    map<int,int> topNode;

    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        if(topNode.find(hd) == topNode.end()){  // This Condition confirms that there is no existing value at given 'hd' in the Map
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}


int main(){
    Node* root = NULL;
    buildTree(root);  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    vector<int> topView = topViewOfTree(root);

    cout<<endl;
    for(auto i: topView){
        cout<<i<<" ";
    }
    cout<<endl;
}