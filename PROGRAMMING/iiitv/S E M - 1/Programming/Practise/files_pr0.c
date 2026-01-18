#include <stdio.h>

int main() {
    char filename[100];
    FILE *fp;
    char word[100];
    int count = 0;

    // Ask the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error! Could not open the file.\n");
        return 1;
    }

    // Count words using fscanf
    while (fscanf(fp, "%s", word) == 1) {
        count++;
    }

    // Print the word count using printf or fprintf
    printf("Number of words in the file: %d\n", count);

    // Close the file
    fclose(fp);

    return 0;
}
