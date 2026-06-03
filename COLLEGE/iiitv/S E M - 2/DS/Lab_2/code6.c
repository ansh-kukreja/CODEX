#include<stdio.h>

int main(){
    int matrix[100][100];
    int rows,cols;

    printf("\nEnter No of Rows: ");
    scanf("%d", &rows);

    printf("Enter No of Columns: ");
    scanf("%d", &cols);

    printf("Enter values of Matrix: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int isIdent = 1;

    if(rows != cols){
        isIdent = 0;
    }
    else{
        for(int i=0; i<rows; i++){
            if(matrix[i][i] != 1){
                isIdent = 0;
                break;
            }
        }

        if(isIdent != 0){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){

                    if(i != j && matrix[i][j] != 0){
                        isIdent = 0;
                        break;
                    }
                }
            }
        }

    }

    if(isIdent){
        printf("\nThe Given Matrix is an Identity Matrix!\n\n");
    }
    else{
        printf("\nThe Given Matrix is NOT an Identity Matrix!\n\n");
    }

}