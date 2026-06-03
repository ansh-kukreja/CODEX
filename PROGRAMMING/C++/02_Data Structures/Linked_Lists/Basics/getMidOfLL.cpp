#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory has been freed of Node with Val "<<val<<endl;
    }
};

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail -> next = temp;
    tail = temp;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* getMid(Node* head){
    Node* slow = head;


// When num of Nodes are even, then we have two center nodes, let them be L and R, 

// if we want L (Left) write this
    Node* fast = head->next;

// else for R (Right) write this
    // Node* fast = head;
    

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    Node* n1 = new Node(4);

    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 5 );
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);

    cout<<"Middle Value is: "<<getMid(head)->data<<endl;
}