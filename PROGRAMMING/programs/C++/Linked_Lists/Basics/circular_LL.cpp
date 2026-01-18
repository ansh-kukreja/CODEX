#include<iostream>
using namespace std;

class Node{
    public:
        int d;
        Node* next = NULL;

    Node(int data){
        d = data;
        next = NULL;
    }

    ~Node(){
        int value = this -> d;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Deleted Node with Value : "<<value<<endl;
    }  
};

void insertNode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else{
        Node* curr = tail;

        while(curr -> d != element){
            curr = curr -> next;
        } 

        Node* newNode = new Node(d);
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void printLL(Node* tail){
    Node* temp = tail;
    
    do{
        cout<<tail->d<<" ";
        tail = tail->next;
    }
    while(temp != tail);
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    insertNode(tail , 4, 9);
    printLL(tail);

    insertNode(tail , 9, 7);
    printLL(tail);
}