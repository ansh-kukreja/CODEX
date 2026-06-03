#include <stdio.h>

int main() {
    FILE *fin, *fout;
    char name[100];
    int mark;

    // Open input file
    fin = fopen("names.lst", "r");
    if (fin == NULL) {
        printf("Error! Could not open names.lst\n");
        return 1;
    }

    // Open output file
    fout = fopen("namesMarks.dat", "w");
    if (fout == NULL) {
        printf("Error! Could not create namesMarks.dat\n");
        fclose(fin);
        return 1;
    }

    int count = 0;

    // Read each name and ask for a mark
    while (fscanf(fin, "%s", name) == 1) {
        count++;

        // Ask user for the mark of this name
        printf("Enter mark for %s: ", name);
        scanf("%d", &mark);

        // Write name + mark to output file
        fprintf(fout, "%s %d\n", name, mark);
    }

    // Print number of names processed
    printf("\nTotal names processed: %d\n", count);

    // Close both files
    fclose(fin);
    fclose(fout);

    return 0;
}
