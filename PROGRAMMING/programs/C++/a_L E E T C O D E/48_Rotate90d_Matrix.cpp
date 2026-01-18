#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
}

void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        // for(int i=0; i<row; i++){
        //     int s=0;
        //     int e=col-1;
        //     while(s<e){
        //         swap(matrix[i][s], matrix[i][e]);
        //         s++;
        //         e--;
        //     }
        // }
        printMatrix(matrix);
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    printMatrix(matrix);
    cout<<endl;
    rotate(matrix);
}