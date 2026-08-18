#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int n){
    struct node *head = NULL;
    struct node *temp, *newnode;
    
    for(int i=0;i<n;i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Value of Node %d: ", i+1);
        scanf("%d",&newnode->data);

        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head = head->next;
    }
}

void insertAfter(struct node* head, int key, int val){
    while(head != NULL){
        if(head->data == key){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=val;
            newnode->next=head->next;
            head->next=newnode;
            return;
        }
        head=head->next;
    }
}

int main(){
    int n;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    struct node* head = create(n);

    printf("\n---- Original Linked List ----\n");
    display(head);

    printf("\n---- After Insertion ----\n");
    insertAfter(head, 4, 0);
    display(head);
    printf("\n\n");
}