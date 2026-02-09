#include<stdio.h>
#include <stdlib.h>

struct node{
    int orderId;
    struct node* next;
};

struct node* create(int n){
    struct node *head = NULL;
    struct node *temp, *newnode;
    
    for(int i=0;i<n;i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter your Order ID: ");
        scanf("%d",&newnode->orderId);

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
        printf("%d ",head->orderId);
        head = head->next;
    }
}

void search(struct node* head, int key){
    int counter = 0;
    int found = 0;
    printf("Order Id Found at Positions: ");

    while(head){
        if(head->orderId == key){
            found++;
            printf(" %d", counter);
        }
        counter++;
        head = head->next;
    }
    if(found == 0){
        printf("\nOrder not found\n");
    }
}

void sort(struct node* head){
    struct node *i,*j;
    int temp;

    for(i=head; i != NULL; i = i->next){

        for(j = i->next; j != NULL; j = j->next){

            if(i->orderId > j->orderId){
                temp = i->orderId;
                i->orderId = j->orderId;
                j->orderId = temp;
            }
        }
    }
}

void removeDuplicates(struct node* head){
    struct node *i,*j,*prev;

    for(i = head; i != NULL; i = i->next){
        prev=i;
        j=i->next;

        while(j != NULL){
            if(i->orderId == j->orderId){
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
    printf("Enter number of Order IDs you want to place: ");
    scanf("%d",  &n);

    struct node* head = create(n);

    printf("\nOrder IDs in the order they were placed\n");
    display(head);
    printf("\n\n");

    int searchId;
    printf("Enter Order Id you want to search: ");
    scanf("%d", &searchId);
    search(head, searchId);
    printf("\n\n");

    sort(head);
    printf("\n\nOrder IDs for Billing\n\n");
    display(head);
    printf("\n\n");

    removeDuplicates(head);
    printf("\n\nAfter removing Duplicates\n\n");
    display(head);
    printf("\n\n");
}