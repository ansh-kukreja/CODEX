//     ___________________________________________
//    |               |                           |  
//    |     DATA      |      Next Node Address    |
//    |_______________|___________________________|


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

void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    // --------- Head Case ----------
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp -> next;
        cnt += 1;
    }
    // ---------- Tail Case ---------
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

void deleteNodePos(Node* &head, int pos){
    if(pos == 1){
        Node* deleteMe = head;
        head = head -> next;

        deleteMe->next = NULL;
        delete deleteMe;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt=1;

    while(cnt < pos){
        prev = curr;
        curr = curr -> next;
        cnt+=1;
    }
    prev -> next = curr -> next;

    curr->next = NULL;
    delete curr;
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

int main(){
    Node* n1 = new Node(9);
    // cout<<"Data: "<<n1 -> data<<endl;
    // cout<<"Next Address: "<<n1 -> next<<endl;

    Node* head = n1;
    Node* tail = n1;

    insertAtHead(head, 4);
    insertAtHead(head, 7);
    printLL(head);

    insertAtTail(tail, 70);
    insertAtTail(tail, 900);
    printLL(head);

    insertAtPosition(tail, head, 2, 67);
    printLL(head);

    deleteNodePos(head, 2);
    printLL(head);
}