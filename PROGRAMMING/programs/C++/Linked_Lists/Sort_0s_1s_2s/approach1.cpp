#include<iostream>
using namespace std;

// ================ Approach 1 ================

/* 
    count the number of 0,1,2 present in List and replace the data in existing Linked List
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


int main(){
    Node* n1 = new Node(0);

    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);

    printLL(head);

   
    int zeroes = 0, ones = 0, twos = 0;
    Node* temp = head;

    while(temp != NULL){
        if(temp -> data == 0){
            zeroes++;
        }
        else if(temp -> data == 1){
            ones++;
        }
        else if(temp -> data == 2){
            twos++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroes != 0){
            temp->data = 0;
            zeroes--;
        }
        else if(ones != 0){
            temp->data = 1;
            ones--;
        }
        else if(twos != 0){
            temp->data = 2;
            twos--;
        }

        temp = temp->next;
    }

    printLL(head);
} 