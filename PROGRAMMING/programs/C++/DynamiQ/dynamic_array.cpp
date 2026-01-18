#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Size of Array: "; cin>>n;
    
//     Takes         Takes
//    8 bytes       4 bytes
// (Stack Memory)  (Heap Memory)
//       |           |
    int* arr = new int[n];

    cout<<"Enter values in Array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }


// Free the "Heap Memory"
    delete []arr;
}

