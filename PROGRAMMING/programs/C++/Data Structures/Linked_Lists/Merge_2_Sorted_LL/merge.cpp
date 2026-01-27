#include<iostream>
using namespace std;

// ================ Merging 2 Sorted Linked Lists ================


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


// =======================================================================================

Node* merge(Node* first, Node* second){

    // Edge Case
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){

            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr1->next;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first; 
}

Node* merge2SortedList(Node* first, Node* second){
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data <= second->data){
        return merge(first, second);
    }
    else{
        return merge(second, first);
    }
}

// =======================================================================================



int main(){
    Node* n1 = new Node(1);
    Node* head1 = n1;
    Node* tail1 = n1;

    insertAtTail(tail1, 4);
    insertAtTail(tail1, 5);
    insertAtTail(tail1, 9);


    Node* n2 = new Node(2);
    Node* head2 = n2;
    Node* tail2 = n2;

    insertAtTail(tail2, 3);
    insertAtTail(tail2, 7);
    insertAtTail(tail2, 9);

    printLL(head1);
    printLL(head2);

    Node* mergedList = merge2SortedList(head1, head2);
    printLL(mergedList);
} 