#include <stdio.h>
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

void search(struct node* head, int x){
    int pos=1, found=0;

    while(head){
        if(head->data == x){
            printf("Found at position %d\n",pos);
            found=1;
        }
        head=head->next;
        pos++;
    }

    if(!found){
        printf("Element not found");
    }
}

int main(){
    int n,find;

    printf("Enter number of Values: ");
    scanf("%d",&n);

    struct node* head = create(n);

    printf("Enter Value you want to Search: ");
    scanf("%d",&find);

    search(head,find);
}