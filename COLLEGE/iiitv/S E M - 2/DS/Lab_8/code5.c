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
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

struct Node* inorderSuccessor(struct Node* root, int key) {
    struct Node* successor = NULL;

    while(root != NULL) {
        if(key < root->data) {
            successor = root;
            root = root->left;
        } 
        else if (key > root->data) {
            root = root->right;
        } 
        else {
            if(root->right != NULL)
                return findMin(root->right);
            break;
        }
    }
    return successor;
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

    printf("Enter node to find successor: ");
    scanf("%d", &key);

    struct Node* succ = inorderSuccessor(root, key);

    if (succ != NULL)
        printf("Inorder Successor of %d is %d\n", key, succ->data);
    else
        printf("No inorder successor exists\n");

    return 0;
}