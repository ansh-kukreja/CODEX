#include<iostream>
using namespace std;

// ================ FLOYD LOOP/CYCLE DETECTION ALGORITHM ================
/* 
    "Slow and Fast Pointers" wali approach, aka 2 pointer approach, when (slow == fast) then
    it means cycle exists and if (fast == NULL) then it means no cycle exists 
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


// ====== Checking Loop ========

bool floydLoopDetection(Node* head){
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        slow = slow->next;

        if(slow == fast) return true;
    }

    return false;
}


int main(){
    Node* n1 = new Node(4);

    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7); // Loop head
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);

    tail->next = head->next->next->next;  // Creating Cycle


    bool loopHai = floydLoopDetection(head);

    if(loopHai){
        cout<<endl<<"Cycle Exists in given List"<<endl<<endl;
    }
    else{
        cout<<endl<<"Cycle Doesn't Exists"<<endl<<endl;
    }
}