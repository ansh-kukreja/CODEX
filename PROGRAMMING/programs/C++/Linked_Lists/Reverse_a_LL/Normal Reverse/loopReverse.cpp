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


Node* reverseLL(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;

    while(curr != NULL){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}



int main(){
    Node* n1 = new Node(4);

    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    printLL(head);

    head = reverseLL(head);

    printLL(head);

}