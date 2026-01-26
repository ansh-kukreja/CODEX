#include<iostream>
#include<queue>
using namespace std;

// ===================== Diameter of a Tree ======================
/*
    Maximum distance between any Two Leaf Nodes (See Diagram in Notes)

    -- Three Possible Scenarios --
    1) Check Diameter of Left Side
    2) Check Diameter of Right Side
    3) Take Heights of Left and Right Sides + Root Node

    - Pass the Max Value out of above 3 options and Pass it to the Parent Node
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


// ======================= Diameter Of a Tree ======================= 
// This is a way but it is not efficient, Time Complexity is O(n²)

int diameterOfATree(node* root){
    if(root == NULL) return 0;

    int option1 = diameterOfATree(root->left);
    int option2 = diameterOfATree(root->right);
    int option3 = heightOfATree(root->left) + heightOfATree(root->right) + 1;

    int ans = max(option1, max(option2, option3));
    return ans;
}


// =================== Diameter (Optimised Approach) ================
/* This Function return pair of integers such that "<diameter,height>"
*/
pair<int,int> getDiameter(node* root){
    if(root == NULL){
        return make_pair(0,0);
    }

    pair<int,int> left = getDiameter(root->left);
    pair<int,int> right = getDiameter(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1; 

    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3));
    ans.second = max(left.second, right.second) + 1; // Maintains and Tracks the Height

    return ans;
}



int main(){
    node* root = NULL;
    buildTree(root);  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    printTree(root);

    cout<<endl<<"Maximum Diameter of the Tree is : "<<getDiameter(root).first<<endl<<endl;
} 