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
    printf("%d\n", temp->data);
}

int countNodes(struct node* head){
    if(head == NULL) return 0;

    int count = 0;
    struct node* temp = head;

    do{
        count++;
        temp = temp->next;
    }while(temp != head);

    return count;
}

int main(){
    struct node* head = NULL;

    head = create(head,10);
    head = create(head,20);
    head = create(head,30);
    head = create(head,40);

    display(head);

    printf("Total num of Nodes: %d \n\n", countNodes(head));
}