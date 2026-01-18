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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// =======================================================================================

Node* mergeSort(Node* head){
    // Base Case 
    if(head == NULL || head->next == NULL) return head;

    // Divide the List into two halves
    Node* mid = getMid(head);
    Node* leftPart = head;  
    Node* rightPart = mid->next;
    mid->next = NULL;

    // Sort the two halves
    leftPart = mergeSort(leftPart);
    rightPart = mergeSort(rightPart);

    // Merge both sorted halves
    return merge2SortedList(leftPart, rightPart);
}

// =======================================================================================



int main(){
    Node* n1 = new Node(7);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 4);
    insertAtTail(tail, 2);
    insertAtTail(tail, 9);

    printLL(head);

    Node* newHead = mergeSort(head);
    printLL(newHead);

} 