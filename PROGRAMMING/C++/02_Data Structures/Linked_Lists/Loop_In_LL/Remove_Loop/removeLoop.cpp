#include<iostream>
using namespace std;

// ================ Removing Loop ================

/* 

                             __ __ __> __ __(C)
                            |               |
                            |               |
    (A)--->------->---------(B)             |
                                            |
                                            |
                                            |
                           NULL             |
                            ⬆              |
                            |__ __ __< __ __|


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


// ====== Finding first POI of Loop "C" ========

Node* floydPOIFinder(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        slow = slow->next;

        if(slow == fast) return fast;
    }

    return NULL;
}

// ====== Removing Loop ========

bool removeLoop(Node* head){
    if(head == NULL){
        return false;
    }

    Node* poi = floydPOIFinder(head);

    if(poi == NULL) return false;

    Node* slow = head;
    Node* fast = poi;

    Node* prev = NULL;

    while(slow != fast){
        slow = slow -> next;
        prev = fast;
        fast = fast -> next;
    }

    prev->next = NULL;
    return true; 
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

    removeLoop(head);
    printLL(head);
} 