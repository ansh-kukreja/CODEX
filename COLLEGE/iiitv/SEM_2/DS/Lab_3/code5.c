#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
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

void removeDuplicates(struct node* head){
    struct node *i,*j,*prev;

    for(i = head; i != NULL; i = i->next){
        prev=i;
        j=i->next;

        while(j != NULL){
            if(i->data == j->data){
                prev->next = j->next;
                free(j);
                j=prev->next;
            }
            else{
                prev = j;
                j = j->next;
            }
        }
    }
}

int main(){
    int n;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    struct node* head = create(n);

    printf("\n---- Original Linked List ----\n");
    display(head);
    printf("\n---- After Removing Duplicates ----\n");
    removeDuplicates(head);
    display(head);

    printf("\n\n");
}