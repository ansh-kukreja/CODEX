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


vector<vector<int>> verticalTraversal(Node* root){

    // <HorizDist, <Level, Nodes>>
    map<int, map<int,vector<int>>> nodes;

    //        <Nodes, <HorizDist, Level>>
    queue<pair<Node*, pair<int,int>>> q;
    vector<vector<int>> ans;

    if(root == NULL) return ans;

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontalDistance][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance-1, level+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance+1, level+1)));
        }
    }

    for(auto i: nodes){
        vector<int> temp;
        for(auto j: i.second){
            for(auto k: j.second){
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}


int main(){
    Node* root = NULL;
    buildTree(root);  // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    vector<vector<int>> ans = verticalTraversal(root);

    cout<<endl;
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}