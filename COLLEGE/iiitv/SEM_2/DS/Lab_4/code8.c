#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

struct node* insert(struct node* head,int data){

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;

    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }

    struct node* last = head->prev;

    last->next = newnode;
    newnode->prev = last;

    newnode->next = head;
    head->prev = newnode;

    return head;
}

void display(struct node* head){

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    struct node* temp=head;

    printf("\n\n");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n\n");
}

int main(){

    struct node* head=NULL;

    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);

    display(head);
}