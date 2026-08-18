#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node* insert(struct node* head,int data){

    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if(!head){
        newnode->prev=NULL;
        return newnode;
    }

    struct node* temp=head;
    while(temp->next)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;

    return head;
}

void unionList(struct node* h1, struct node* h2){

    printf("Union: ");

    struct node* temp=h1;

    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    temp=h2;

    while(temp){
        struct node* t=h1;
        int found=0;

        while(t){
            if(t->data==temp->data){
                found=1;
                break;
            }
            t=t->next;
        }

        if(!found)
            printf("%d ",temp->data);

        temp=temp->next;
    }
}

void intersection(struct node* h1, struct node* h2){

    printf("\nIntersection: ");

    while(h1){
        struct node* temp=h2;

        while(temp){
            if(h1->data==temp->data){
                printf("%d ",h1->data);
                break;
            }
            temp=temp->next;
        }
        h1=h1->next;
    }
}

int main(){

    struct node *h1=NULL,*h2=NULL;

    h1=insert(h1,1);
    h1=insert(h1,2);
    h1=insert(h1,3);

    h2=insert(h2,2);
    h2=insert(h2,3);
    h2=insert(h2,4);

    printf("\n\n");

    unionList(h1,h2);
    intersection(h1,h2);

    printf("\n\n");
}