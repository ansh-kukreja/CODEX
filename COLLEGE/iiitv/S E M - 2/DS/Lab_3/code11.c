#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head,int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if(!head) return newnode;

    struct node* temp=head;
    while(temp->next)
        temp=temp->next;

    temp->next=newnode;
    return head;
}

void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

struct node* deleteLastOccurrence(struct node* head,int key){

    struct node *temp=head;
    struct node *last=NULL,*prev=NULL,*lastPrev=NULL;

    while(temp){
        if(temp->data==key){
            last=temp;
            lastPrev=prev;
        }
        prev=temp;
        temp=temp->next;
    }

    if(!last){
        printf("Element not found");
        return head;
    }

    if(lastPrev==NULL){
        head=head->next;
    }
    else{
        lastPrev->next=last->next;
    }

    free(last);
    return head;
}

int main(){
    int n,x;
    struct node* head = NULL;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter Value: ");
        scanf("%d",&x);
        head = insert(head,x);
    }

    printf("Enter Key: ");
    int key;
    scanf("%d",&key);

    head = deleteLastOccurrence(head,key);

    display(head);
}