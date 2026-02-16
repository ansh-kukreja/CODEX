#include <stdio.h>
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
    while(temp->next)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

void kthCounter(struct node* head, int k){
    int count = 0;
    struct node* temp = head;

    while(temp){
        count++;
        temp = temp->next;
    }

    if(k > count){
        printf("Invalid k\n");
        return;
    }

    temp = head;
    for(int i=0;i<count-k;i++)
        temp = temp->next;

    printf("Kth node from end: %d\n", temp->data);
}

void kthNoCounter(struct node* head, int k){
    struct node *fast=head, *slow=head;

    for(int i=0;i<k;i++){
        if(fast==NULL){
            printf("Invalid k\n");
            return;
        }
        fast = fast->next;
    }

    while(fast){
        slow = slow->next;
        fast = fast->next;
    }

    printf("Kth node from end: %d\n", slow->data);
}

int main(){
    struct node* head = NULL;

    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    head = insert(head,40);
    head = insert(head,50);

    int k = 2;

    kthCounter(head,k);
    kthNoCounter(head,k);
}