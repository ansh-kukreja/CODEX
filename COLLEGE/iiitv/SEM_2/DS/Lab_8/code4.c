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

struct Node* findMin(struct Node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    struct Node* min = findMin(root);
    struct Node* max = findMax(root);

    if(min != NULL)
        printf("Minimum value: %d\n", min->data);
    else
        printf("Tree is empty.\n");

    if (max != NULL)
        printf("Maximum value: %d\n", max->data);
    else
        printf("Tree is empty.\n");

    return 0;
}