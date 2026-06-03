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

int exists(struct node* head,int val){
    while(head){
        if(head->data==val) return 1;
        head=head->next;
    }
    return 0;
}

struct node* insert(struct node* head, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(!head) return newnode;

    struct node* temp = head;
    while(temp->next)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

struct node* unionList(struct node* a, struct node* b){
    struct node* result = NULL;

    while(a){
        if(!exists(result, a->data))
            result = insert(result, a->data);
        a = a->next;
    }

    while(b){
        if(!exists(result, b->data))
            result = insert(result, b->data);
        b = b->next;
    }

    return result;
}

struct node* intersectionList(struct node* a, struct node* b){
    struct node* result = NULL;

    while(a){
        if(exists(b, a->data) && !exists(result, a->data))
            result = insert(result, a->data);
        a = a->next;
    }

    return result;
}



int main(){
    int n1,n2;

    printf("Enter number of Values in List 1 : ");
    scanf("%d",&n1);

    printf("\n---- Enter Values for List 1 ----\n");
    struct node* head1 = create(n1);

    printf("Enter number of Values in List 2: ");
    scanf("%d",&n2);

    printf("\n---- Enter Values for List 2 ----\n");
    struct node* head2 = create(n2);

    struct node* unionHead = unionList(head1, head2);
    struct node* interHead = intersectionList(head1, head2);

    printf("\n==== UNION ====\n");
    display(unionHead);

    printf("\n\n==== INTERSECTION ====\n");
    display(interHead);

    printf("\n\n");
}