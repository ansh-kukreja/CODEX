#include<iostream>
using namespace std;

// ================ Approach 2 ================

/* 
    Create 3 Separate Linked Lists of 1s, 1s, 2s and then Merge them into one  list

    ###### Use this approach when data replacement is not allowed ######
*/


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
    }
};

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail -> next = temp;
    tail = temp;
}

void printLL(Node* &head){
    Node* temp = head;

    while(true){
        cout<<temp -> data<<" ";
        temp = temp -> next;

        if(temp -> next == NULL){
            cout<<temp -> data<<" ";
            break;
        }
    }
    cout<<endl;
}

void insertAtTailOfSubList(Node* &tail,  Node*   curr){
    tail -> next = curr;
    tail = curr;
}


int main(){
    Node* n1 = new Node(2);

    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    printLL(head);


    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;

    while(temp != NULL){
        if(temp -> data == 0){
            insertAtTailOfSubList(zeroTail, temp);
        }
        else if(temp -> data == 1){
            insertAtTailOfSubList(oneTail, temp);
        }
        else if(temp -> data == 2){
            insertAtTailOfSubList(twoTail, temp);
        }
        temp = temp->next;
    }


    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    head = zeroHead->next;

    printLL(head);
} 