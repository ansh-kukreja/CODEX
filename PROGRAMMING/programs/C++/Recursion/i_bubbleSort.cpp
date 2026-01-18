#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    if(n == 0 || n == 1){
        return;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, n-1);
}

int main(){
    int size = 7;
    int arr[7] = {4,6,7,42,54,7,9};      // 4 6 7 7 9 42 54

    bubbleSort(arr, size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}