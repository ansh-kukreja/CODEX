#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    int id;
    char title[50];
};

void addBook(struct Book library[], int *count);
void removeBook(struct Book library[], int *count);
void showBooks(struct Book library[], int count);

#endif
