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

struct node* deleteStart(struct node* head){
    if(head){
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node* deleteEnd(struct node* head){
    if(!head) return NULL;

    if(!head->next){
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while(temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct node* deleteKth(struct node* head, int k){
    if(!head) return NULL;

    if(k == 1)
        return deleteStart(head);

    struct node* temp = head;

    for(int i=1; i<k-1 && temp; i++)
        temp = temp->next;

    if(temp && temp->next){
        struct node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    return head;
}

int main(){
    int n;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    struct node* head = create(n);


    printf("\n---- Original Linked List ----\n");
    display(head);

    printf("\n---- After Deletion ----\n");
    head = deleteStart(head);
    head = deleteEnd(head);
    head = deleteKth(head, 2);
    display(head);
    printf("\n\n");
}