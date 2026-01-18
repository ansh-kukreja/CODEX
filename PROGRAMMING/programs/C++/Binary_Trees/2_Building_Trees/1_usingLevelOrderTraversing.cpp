#include<iostream>
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


void buildUsingLevelOrder(node* &root){
    queue<node*> q;

    int data;
    cout<<"Enter Data for Root : "<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter Left Node for: "<<temp->data<<endl;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter Right Node for: "<<temp->data<<endl;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}


void levelOrderPrinting(node* &root){
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


int main(){
    node* root = NULL;
    buildUsingLevelOrder(root);  // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderPrinting(root);
}