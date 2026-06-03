#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

struct Node* inorderPredecessor(struct Node* root, int key) {
    struct Node* predecessor = NULL;

    while(root != NULL) {
        if(key > root->data) {
            predecessor = root;
            root = root->right;
        } 
        else if(key < root->data) {
            root = root->left;
        } 
        else {
            if(root->left != NULL)
                return findMax(root->left);
            break;
        }
    }
    return predecessor;
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter node to find predecessor: ");
    scanf("%d", &key);

    struct Node* pred = inorderPredecessor(root, key);

    if(pred != NULL)
        printf("Inorder Predecessor of %d is %d\n", key, pred->data);
    else
        printf("No inorder predecessor exists\n");

    return 0;
}