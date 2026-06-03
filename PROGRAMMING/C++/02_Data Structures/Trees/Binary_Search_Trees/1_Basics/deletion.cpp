#include<iostream>
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
    }
};

void traverse(Node* &root){
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


Node* insert(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

Node* minVal(Node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;

    if(root->data == val){
        // Case 1: (0 child)
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: (1 child)
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: (2 child)
        if(root->left != NULL && root->right != NULL){
            // Swapping Target Node with Inorder Successor or Inorder Predecessor
            int min = minVal(root->right) ->data;
            root->data = min;
            root->right =  deleteNode(root->right, min);
        }

    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
        return root;
    }
    else{
        root->left = deleteNode(root->left, val);
        return root;
    }
}

int main(){
    Node* root = NULL;
    int data;
    cin>>data;

    while(data != -1){
        root = insert(root, data);
        cin>>data;
    }

    traverse(root);
}

// 10 8 21 7 27 5 4 3