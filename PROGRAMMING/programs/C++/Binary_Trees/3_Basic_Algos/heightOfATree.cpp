#include<iostream>
#include<queue>
using namespace std;

// ===================== Height of a Tree ======================
/*
    Maximum distance between Root Node and a Leaf Node in a Tree
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


// ======================= Height Of a Tree ===========================================
int heightOfATree(node* root){
    if(root == NULL) return 0;

    int left = heightOfATree(root->left);
    int right = heightOfATree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
// ==================================================================



int main(){
    node* root = NULL;
    buildTree(root);  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    printTree(root);

    cout<<endl<<"Maximum height of the Tree is : "<<heightOfATree(root)<<endl<<endl;
}