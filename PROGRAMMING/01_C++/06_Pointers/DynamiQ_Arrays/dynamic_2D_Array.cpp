#include<iostream>
using namespace std;

int main(){
    int n;
    int m;
    cout<<"Enter Rows of Array: "; cin>>n;
    cout<<"Enter Columns of Array: "; cin>>m;

    // Created Array of Arrays ( 'int*' means Array )
    int** arr = new int*[n];

    // Creating inside wale Arrays ( the 'int*' that we created above )
    for(int i=0; i<n; i++){
        arr[i] = new int(m);
    }

    // 2D Dynamic Array Created Completely-

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // Input bhi Leliya

    cout<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Array ko print bhi kr diya

    for(int i=0; i<n; i++){
        delete []arr[i];
    }
    delete []arr;

    // Memory ko De-Allocate krna thori bhulunga mai ^^_
}

