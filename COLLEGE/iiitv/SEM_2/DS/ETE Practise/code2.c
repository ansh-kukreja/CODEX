#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create(struct Node* head, int n){
    struct Node* temp;

    for(int i=0; i<n; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter Value of %d Node : ", i+1);
        scanf("%d",  &newNode->data);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    return head;
}

void display(struct Node* head){
    while(head){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void printRev(struct Node* head){
    if(head == NULL) return;

    printRev(head->next);
    printf("%d ", head->data);
}


int main(){

    struct Node *head = NULL;
    head = create(head, 4);

    printf("\n\n");
    display(head);
    printf("\n\n");
    printRev(head);
    printf("\n\n");
}