#include<stdio.h>
#include <stdlib.h>

struct nodeCLL{
    int data;
    struct nodeCLL* next;
};

struct nodeDLL{
    int data;
    struct nodeDLL *prev,*next;
};

struct nodeCLL* insertInCLL(struct nodeCLL* head, int data){
    struct nodeCLL* newnode = (struct nodeCLL*)malloc(sizeof(struct nodeCLL));

    newnode->data = data;

    if(head == NULL){
        head = newnode;
        newnode->next = head;
        return head;
    }

    struct nodeCLL* temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;

    return head;
}

void displayCLL(struct nodeCLL* head){
    if(head == NULL) return;

    struct nodeCLL* temp = head;

    printf("\n\n");
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n\n", temp->data);
}

void countCLL(struct nodeCLL* head){
    int count = 1;
    if(head == NULL) return;

    struct nodeCLL* temp = head;

    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    printf("\n\nNumber of featured Books: %d", count);
}

struct nodeCLL* deleteStartCLL(struct nodeCLL* head){
    if(head == NULL) return NULL;

    struct nodeCLL* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    if(temp == head){
        free(head);
        return NULL;
    }

    temp->next = head->next;
    free(head);

    return temp->next;
}

struct nodeCLL* deleteEndCLL(struct nodeCLL* head){

    if(head == NULL) return NULL;

    struct nodeCLL *temp = head, *prev = NULL;

    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL){
        free(head);
        return NULL;
    }

    prev->next = head;
    free(temp);

    return head;
}


struct nodeDLL* insertInDLL(struct nodeDLL* head, int data){

    struct nodeDLL* newnode = malloc(sizeof(struct nodeDLL));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    struct nodeDLL* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

void forward(struct nodeDLL* head){
    printf("\n\nPrinting List in Forward Way\n");
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

void backward(struct nodeDLL* head){
    printf("\n\nPrinting List in Backward Way\n");
    struct nodeDLL* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    while(temp){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
}

struct nodeDLL* insertAtKInDLL(struct nodeDLL* head, int data, int k){
    struct nodeDLL* newnode = malloc(sizeof(struct nodeDLL));
    newnode->data = data;

    if(k == 1){
        newnode->next = head;
        newnode->prev = NULL;

        if(head)
            head->prev = newnode;

        return newnode;
    }

    struct nodeDLL* temp = head;

    for(int i=1;i<k-1 && temp;i++)
        temp = temp->next;

    if(temp == NULL) return head;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next)
        temp->next->prev = newnode;

    temp->next = newnode;

    return head;
}

void displayDLL(struct nodeDLL* head){
    if(head == NULL) return;

    struct nodeDLL* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void kthCounter(struct nodeDLL* head, int k){
    int count = 0;
    struct nodeDLL* temp = head;

    while(temp){
        count++;
        temp = temp->next;
    }

    if(k > count){
        printf("Invalid k\n");
        return;
    }

    temp = head;
    for(int i=0;i<count-k;i++)
        temp = temp->next;

    printf("Kth node from end: %d\n", temp->data);
}

void kthNoCounter(struct nodeDLL* head, int k){
    struct nodeDLL *fast=head, *slow=head;

    for(int i=0;i<k;i++){
        if(fast==NULL){
            printf("Invalid k\n");
            return;
        }
        fast = fast->next;
    }

    while(fast){
        slow = slow->next;
        fast = fast->next;
    }

    printf("Kth node from end: %d\n", slow->data);
}


struct nodeDLL* insertInDCLL(struct nodeDLL* head,int data){

    struct nodeDLL* newnode = malloc(sizeof(struct nodeDLL));
    newnode->data = data;

    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        return newnode;
    }

    struct nodeDLL* last = head->prev;

    last->next = newnode;
    newnode->prev = last;

    newnode->next = head;
    head->prev = newnode;

    return head;
}

void displayDCLL(struct nodeDLL* head){

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    struct nodeDLL* temp=head;

    printf("\n\n");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n\n");
}

struct nodeDLL* deleteKInDCLL(struct nodeDLL* head,int k){

    if(!head){
        printf("List empty\n");
        return NULL;
    }

    struct nodeDLL* temp=head;

    for(int i=1;i<k;i++)
        temp=temp->next;

    if(temp->next==temp){
        free(temp);
        return NULL;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    if(temp==head)
        head=temp->next;

    free(temp);
    return head;
}

struct nodeCLL* mergeTwoCLL(struct nodeCLL* h1, struct nodeCLL* h2){

    if(!h1) return h2;
    if(!h2) return h1;

    struct nodeCLL* t1=h1;
    while(t1->next!=h1)
        t1=t1->next;

    struct nodeCLL* t2=h2;
    while(t2->next!=h2)
        t2=t2->next;

    t1->next=h2;
    t2->next=h1;

    return h1;
}

void unionList(struct nodeDLL* h1, struct nodeDLL* h2){

    printf("Union: ");

    struct nodeDLL* temp=h1;

    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    temp=h2;

    while(temp){
        struct nodeDLL* t=h1;
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

void intersection(struct nodeDLL* h1, struct nodeDLL* h2){

    printf("\nIntersection: ");

    while(h1){
        struct nodeDLL* temp=h2;

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

void findMiddle(struct nodeCLL* head){

    if(!head) return;

    struct nodeCLL *slow=head,*fast=head;

    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }

    printf("\n\nMiddle element: %d\n\n",slow->data);
}

int main(){
    struct nodeCLL* featuredBooksHead = NULL;

    featuredBooksHead = insertInCLL(featuredBooksHead, 20);
    featuredBooksHead = insertInCLL(featuredBooksHead, 30);
    featuredBooksHead = insertInCLL(featuredBooksHead, 40);
    featuredBooksHead = insertInCLL(featuredBooksHead, 50);

    countCLL(featuredBooksHead);
    displayCLL(featuredBooksHead);
    featuredBooksHead = deleteStartCLL(featuredBooksHead);
    featuredBooksHead = deleteEndCLL(featuredBooksHead);
    displayCLL(featuredBooksHead);


    struct nodeDLL* borrowHistoryHead = NULL;

    borrowHistoryHead = insertInDLL(borrowHistoryHead, 4);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 5);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 6);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 7);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 8);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 9);

    forward(borrowHistoryHead);
    backward(borrowHistoryHead);
    borrowHistoryHead = insertAtKInDLL(borrowHistoryHead, 6, 3);
    printf("Inserting at Kth Position\n");
    displayDLL(borrowHistoryHead);


    int k = 2;

    printf("\n\nKth Element from Last: \n");
    kthCounter(borrowHistoryHead,k);
    kthNoCounter(borrowHistoryHead,k);



    struct nodeDLL* branchesHead = NULL;

    branchesHead = insertInDCLL(branchesHead,1);
    branchesHead = insertInDCLL(branchesHead,2);
    branchesHead = insertInDCLL(branchesHead,3);
    branchesHead = insertInDCLL(branchesHead,4);

    printf("\n\nDCLL Branches");
    displayDCLL(branchesHead);

    branchesHead = deleteKInDCLL(branchesHead, 3);
    printf("\nAfter deleting Branch from Kth Position");
    displayDCLL(branchesHead);



    struct nodeCLL* featuredBooksHead2 = NULL;

    featuredBooksHead = insertInCLL(featuredBooksHead, 50);
    featuredBooksHead = insertInCLL(featuredBooksHead, 60);
    featuredBooksHead = insertInCLL(featuredBooksHead, 70);

    struct nodeCLL* mergedCLL = mergeTwoCLL(featuredBooksHead ,featuredBooksHead2);

    printf("Merged List");
    displayCLL(mergedCLL);


    struct nodeDLL* borrowHistoryHead2 = NULL;
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 4);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 15);
    borrowHistoryHead = insertInDLL(borrowHistoryHead, 16);

    unionList(borrowHistoryHead, borrowHistoryHead2);
    intersection(borrowHistoryHead, borrowHistoryHead2);

    findMiddle(featuredBooksHead);
}
