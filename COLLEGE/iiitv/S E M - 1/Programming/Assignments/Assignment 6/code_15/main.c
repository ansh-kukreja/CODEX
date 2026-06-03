#include <stdio.h>
#include "library.h"

int main() {
    struct Book library[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n==== Library ====\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Show All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                removeBook(library, &count);
                break;
            case 3:
                showBooks(library, count);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


//    gcc main.c library.c -o library
//    ./library