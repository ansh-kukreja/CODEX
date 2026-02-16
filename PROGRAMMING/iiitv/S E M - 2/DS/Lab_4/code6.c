#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node* create(struct node* head, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;

    if(head == NULL){
        head = newnode;
        newnode->next = head;
        return head;
    }

    struct node* temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;

    return head;
}

void display(struct node* head){
    if(head == NULL) return;

    struct node* temp = head;

    printf("\n\n");
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

struct node* insertAtK(struct node* head, int data, int k){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;

    if(k == 1){
        newnode->next = head;
        newnode->prev = NULL;

        if(head)
            head->prev = newnode;

        return newnode;
    }

    struct node* temp = head;

    for(int i=1;i<k-1 && temp;i++)
        temp = temp->next;

    if(temp == NULL) return head;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next)
        temp->next->prev = newnode;

    temp->next = newnode;

    return head;
}

int main(){
    struct node* head = NULL;

    head = create(head, 4);
    head = create(head, 5);
    head = create(head, 7);
    head = create(head, 8);
    head = create(head, 9);

    head = insertAtK(head, 6, 3);

    display(head);
}