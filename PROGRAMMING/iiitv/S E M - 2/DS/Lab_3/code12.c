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

struct node* deleteAll(struct node* head,int key){
    while(head && head->data == key){
        struct node* temp=head;
        head = head->next;
        free(temp);
    }

    struct node* curr=head;

    while(curr && curr->next){
        if(curr->next->data==key){
            struct node* temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else{
            curr = curr->next;
        }
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
    deleteAll(head, 4);
    display(head);
    printf("\n\n");
}