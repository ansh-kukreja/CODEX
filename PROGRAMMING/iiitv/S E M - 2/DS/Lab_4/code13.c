#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head,int data){

    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;

    if(!head){
        newnode->next=newnode;
        return newnode;
    }

    struct node* temp=head;

    while(temp->next!=head)
        temp=temp->next;

    temp->next=newnode;
    newnode->next=head;

    return head;
}

void findMiddle(struct node* head){

    if(!head) return;

    struct node *slow=head,*fast=head;

    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }

    printf("\n\nMiddle element: %d\n\n",slow->data);
}

int main(){

    struct node* head=NULL;

    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    head = insert(head,40);
    head = insert(head,50);

    findMiddle(head);
}