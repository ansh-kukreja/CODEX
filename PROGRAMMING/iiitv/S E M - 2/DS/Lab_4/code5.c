#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node* insert(struct node* head, int data){

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    struct node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

void forward(struct node* head){
    printf("\n\nPrinting List in Forward Way\n");
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

void backward(struct node* head){
    printf("\n\nPrinting List in Backward Way\n");
    struct node* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    while(temp){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
}

int main(){
    struct node* head = NULL;

    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 9);

    forward(head);
    backward(head);
}