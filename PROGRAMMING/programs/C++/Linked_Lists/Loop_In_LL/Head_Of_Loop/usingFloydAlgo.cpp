#include<iostream>
using namespace std;

// ================ Getting Head of Loop using Floyd Algo ================

/* 

                             __ __ __> __ __(C)
                            |               |
                            |               |
    (A)--->------->---------(B)             |
                            |               |
                            |__ __ __< __ __|



C = The Point where 'Fast and Slow' meets when they are trapped in a cycle
A = Actual Head of the Linked List
B = Head of the Cycle/Loop which we have to find

Algorithm : When (Fast == Slow) i.e at point 'C', then put 'Slow' at 'A' aka HEAD, and now start
=========   traversing both 'Fast' and 'Slow' at normal pace i.e. one node at a time.
            Eventually they both will meet at point 'B' (Head of Loop) by the magic of mathematics.

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


// ====== Finding Head of Loop "B" ========

Node* floydHeadOfLoopFinder(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* poi = floydPOIFinder(head);

    if(poi == NULL) return NULL;

    Node* slow = head;
    Node* fast = poi;

    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }

    return fast; 
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

    Node* headOfLoop = floydHeadOfLoopFinder(head);

    if(headOfLoop != NULL){
        cout<<endl<<"Head of Loop is at Node : "<<headOfLoop->data<<endl<<endl;
    }
} 