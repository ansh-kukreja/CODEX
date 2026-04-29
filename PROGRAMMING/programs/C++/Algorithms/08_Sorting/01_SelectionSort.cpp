#include<iostream>

using namespace std;


// Find Minimum element and swap it with first index, then with second index, ....

void selectionSort(int* arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[7] = {2,6,31,0,6,8,9};
    selectionSort(arr, 7);

    cout<<"\nSorted Array: ";
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}