#include<iostream>
#include<map>
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

Node* hasLoop(Node* head){
    Node* temp = head;
    map<Node*, bool> visited;

    while(temp != NULL){

        if(visited[temp] == true){
            return temp;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return NULL;
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


    Node* loopHead = hasLoop(head);
    
    if(loopHead != NULL){
        cout<<endl<<"Cycle Exists in given List at Node : "<<loopHead->data<<endl<<endl;
    }
    else{
        cout<<endl<<"Cycle Doesn't Exists"<<endl<<endl;
    }
}