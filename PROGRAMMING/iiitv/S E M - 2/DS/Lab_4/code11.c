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

struct node* merge(struct node* h1, struct node* h2){

    if(!h1) return h2;
    if(!h2) return h1;

    struct node* t1=h1;
    while(t1->next!=h1)
        t1=t1->next;

    struct node* t2=h2;
    while(t2->next!=h2)
        t2=t2->next;

    t1->next=h2;
    t2->next=h1;

    return h1;
}

void display(struct node* head){

    struct node* temp=head;

    printf("\n");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n\n");
}

int main(){

    struct node *h1=NULL,*h2=NULL;

    h1=insert(h1,1);
    h1=insert(h1,2);

    h2=insert(h2,3);
    h2=insert(h2,4);

    struct node* merged=merge(h1,h2);

    printf("Merged List:\n");
    display(merged);
}