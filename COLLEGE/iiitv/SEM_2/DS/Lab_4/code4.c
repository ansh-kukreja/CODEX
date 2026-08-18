#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
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
    printf("%d\n\n", temp->data);
}


struct node* deleteStart(struct node* head){
    if(head == NULL) return NULL;

    struct node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    if(temp == head){
        free(head);
        return NULL;
    }

    temp->next = head->next;
    free(head);

    return temp->next;
}

struct node* deleteEnd(struct node* head){

    if(head == NULL) return NULL;

    struct node *temp = head, *prev = NULL;

    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        free(head);
        return NULL;
    }

    prev->next = head;
    free(temp);

    return head;
}

int main(){
    struct node* head = NULL;

    head = create(head,10);
    head = create(head,20);
    head = create(head,30);
    head = create(head,40);

    head = deleteStart(head);
    head = deleteEnd(head);

    display(head);
}