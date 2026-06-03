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

struct node* merge(struct node* a,struct node* b){
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while(a && b){
        if(a->data < b->data){
            tail->next=a;
            a=a->next;
        }
        else{
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }

    tail->next = a ? a : b;

    return dummy.next;
}

int main(){
    int n1,n2;

    printf("Enter number of Values in List 1: ");
    scanf("%d",&n1);
    printf("Enter number of Values in List 2: ");
    scanf("%d",&n2);

    printf("\n---- Enter Values for List 1 ----\n");
    struct node* head1 = create(n1);

    printf("\n---- Enter Values for List 2 ----\n");
    struct node* head2 = create(n2);

    struct node* head = merge(head1,  head2);

    printf("\n\n==== Merged Linked List ====\n");
    display(head);
    printf("\n\n");
}