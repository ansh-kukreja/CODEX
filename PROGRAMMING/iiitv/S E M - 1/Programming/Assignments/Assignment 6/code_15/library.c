#include <stdio.h>
#include "library.h"

void addBook(struct Book library[], int *count) {
    struct Book newBook;
    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title);   

    library[*count] = newBook;
    (*count)++;

    printf("Book added successfully!\n");
}

void removeBook(struct Book library[], int *count) {
    int id, i, j, found = 0;
    printf("\nEnter Book ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (library[i].id == id) {
            found = 1;
            for (j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book with ID %d removed successfully!\n", id);
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found!\n", id);
    }
}

void showBooks(struct Book library[], int count) {
    int i;
    if (count == 0) {
        printf("\nNo books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (i = 0; i < count; i++) {
        printf("Book ID: %d\n", library[i].id);
        printf("Title  : %s\n", library[i].title);
        printf("-----------------------\n");
    }
}
