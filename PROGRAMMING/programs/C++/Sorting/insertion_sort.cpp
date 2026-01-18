#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int x=0; x<n; x++){
        cout<<arr[x]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[7] = {7,9,4,6,5,2,78}; // 2,4,5,6,7,9,78
    int n = 7;

    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        for(;j>=0; j--){
            printArr(arr, n);
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }


    cout<<"Printing Sorted Array: ";
    for(int x=0; x<n; x++){
        cout<<arr[x]<<" ";
    }
}