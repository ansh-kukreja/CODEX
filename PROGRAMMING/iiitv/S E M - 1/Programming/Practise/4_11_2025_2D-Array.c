#include<stdio.h> 
#define NROWS 3
#define NCOLS 5

void inputEntry(float table[][NCOLS]);
void printTable(float table[NROWS][NCOLS]);



int main(){ 

    float table[NROWS][NCOLS] = {{0}};

    printTable(table);

    while(1)
    {
        inputEntry(table);
        printTable(table);
    }

    return 1;
}

void printTable(float table[NROWS][NCOLS]){
    
}