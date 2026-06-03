#include<iostream>
#include<queue>
using namespace std;

// ===================== Balanced Tree ======================
/*
    When differrence between heights of LEFT Part and RIGHT Part
    of each Node of a Tree is (<= 1)
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

void printTree(node* &root){
    cout<<endl;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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

int heightOfATree(node* root){
    if(root == NULL) return 0;

    int left = heightOfATree(root->left);
    int right = heightOfATree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}


// ======================= Balanced Tree ======================= 
// This is a way but it is not efficient, Time Complexity is O(n²)

bool isBalanced(node* root){
    if(root == NULL) return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(heightOfATree(root->left) - heightOfATree(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}


// ================== Balanced Tree (Optimised Approach) ================== 

pair<bool,int> isBalanced2(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalanced2(root->left);
    pair<bool,int> right = isBalanced2(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = left.second + right.second + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
        return ans;
    }
    else{
        ans.first = false;
        return ans; 
    }
}


int main(){
    node* root = NULL;
    buildTree(root);  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    printTree(root);

    if(isBalanced2(root).first){
        cout<<endl<<"Tree is Balanced"<<endl<<endl;
    }
    else{
        cout<<endl<<"Tree is Not Balanced"<<endl<<endl;
    }
} 