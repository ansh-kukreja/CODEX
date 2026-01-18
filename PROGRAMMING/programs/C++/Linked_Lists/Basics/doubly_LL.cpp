//     ____________________________________________________________________
//    |                      |               |                             |  
//    |  Prev. Node Address  |     DATA      |      Next Node Address      |
//    |______________________|_______________|_____________________________|


#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        if(this->prev != NULL){
            delete prev;
            this->prev = NULL;
        }
        cout<<"Memory has been freed of Node with Val "<<val<<endl;
    }
};

void printDLL(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int cnt=0;

    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}


void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);

    if(head == NULL){
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* tail, Node* &head, int pos, int d){
    // --------- Head Case ----------
    // if(pos == 1){
    //     insertAtHead(head, tail, d);
    //     return;
    // }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp -> next;
        cnt += 1;
    }
    // ---------- Tail Case ---------
    // if(temp -> next == NULL){
    //     insertAtTail(head, tail, d);
    //     return;
    // }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(int pos, Node* &head){
    if(pos == 1){
        Node* temp = head;
        Node* next = head->next;

        next->prev = NULL;
        head = next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr->next;
            cnt+=1;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main(){
    // Node* node1 = new Node(7);
    // Node* head = node1;
    // Node* tail = node1;

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    printDLL(head);

    insertAtPosition(tail, head, 3, 98);
    printDLL(head);

    deleteNode(6, head);
    printDLL(head);
}