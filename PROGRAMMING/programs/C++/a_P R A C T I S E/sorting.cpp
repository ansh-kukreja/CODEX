#include<iostream>
using namespace std;

int main(){
    int arr[] = {9,7,4,3,5,1,8,9,7,0}; // 0134577899
    int size = sizeof(arr)/sizeof(int);

    for(int i=0; (i+1)<size; i++){
        for(int j=0; (j+i+1)<size; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout<<"\nPrinting Array\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}