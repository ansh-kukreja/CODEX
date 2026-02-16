#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

struct node* insert(struct node* head,int data){

    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;

    if(!head){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }

    struct node* last=head->prev;

    last->next=newnode;
    newnode->prev=last;
    newnode->next=head;
    head->prev=newnode;

    return head;
}

struct node* deleteK(struct node* head,int k){

    if(!head){
        printf("List empty\n");
        return NULL;
    }

    struct node* temp=head;

    for(int i=1;i<k;i++)
        temp=temp->next;

    if(temp->next==temp){
        free(temp);
        return NULL;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    if(temp==head)
        head=temp->next;

    free(temp);
    return head;
}

void display(struct node* head){

    if(!head) return;

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

    struct node* head=NULL;

    head = insert(head,5);
    head = insert(head,10);
    head = insert(head,15);
    head = insert(head,20);

    head = deleteK(head,2);

    printf("After deletion:\n");
    display(head);
}