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

void kthFromLast(struct node* head,int k){
    struct node *p=head,*q=head;

    for(int i=0;i<k;i++){
        if(!q) return;
        q=q->next;
    }

    while(q){
        p=p->next;
        q=q->next;
    }

    printf("%d",p->data);
}

int main(){
    int n;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    struct node* head = create(n);

    printf("Enter Value of K: ");
    int k;
    scanf("%d", &k);
    kthFromLast(head, k);

    printf("\n");
}